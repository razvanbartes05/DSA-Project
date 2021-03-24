#include "Map.h"
#include "MapIterator.h"

Map::Map() {
    hashTableCapacity = 10;
    numberOfElements = 0;
    firstFreePosition = 0;
    hashTable = new TElem[10];
    nextNode = new int[10];
    for (int i = 0; i < hashTableCapacity; ++i) {
        hashTable[i] = NULL_TELEM;
        nextNode[i] = NULL_NEXT;
    }
}

TValue Map::add(TKey c, TValue v) {
    if (needsReadjustment()) {
        readjust();
    }
    int insertPosition = hash(c);
    if (hashTable[insertPosition] == NULL_TELEM) {
        hashTable[insertPosition] = { c, v };
        nextNode[insertPosition] = NULL_NEXT;
        if (firstFreePosition == insertPosition)
            updateFirstFreePosition();
    }
    else {
        int currentNode = insertPosition;
        bool foundElement = false;
        while (nextNode[currentNode] != NULL_NEXT && foundElement == false) { 
            if (hashTable[currentNode].first == c) {
                foundElement = true;
            }
            else
                currentNode = nextNode[currentNode];
        }
        if (foundElement == true || hashTable[currentNode].first == c) {
            Employee oldValue = hashTable[currentNode].second;
            hashTable[currentNode] = { c, v };
            return oldValue;
        }
        hashTable[firstFreePosition] = { c, v };
        nextNode[firstFreePosition] = NULL_NEXT;
        nextNode[currentNode] = firstFreePosition;
        updateFirstFreePosition();
    }
    ++numberOfElements;
    return NULL_TVALUE;
}

TValue Map::search(TKey c) const {
    int currentNode = hash(c);
    while (currentNode != NULL_NEXT) {
        if (hashTable[currentNode].first == c) {
            return hashTable[currentNode].second;
        }
        currentNode = nextNode[currentNode];
    }
    return NULL_TVALUE;
}

TValue Map::remove(TKey c) {
    int actualNode = hash(c);
    int previousNode = NULL_NEXT;
    int index = 0;
    Employee oldValue;

    while (actualNode != NULL_NEXT && hashTable[actualNode].first != c) {
        previousNode = actualNode;
        actualNode = nextNode[actualNode];
    }

    if (actualNode == NULL_NEXT) { 
        return NULL_TVALUE;
    }
    else {
        oldValue = hashTable[actualNode].second;
        bool doneMoving = false;
        do {
            int currentPos = nextNode[actualNode];
            int previousPos = actualNode;

            while (currentPos != NULL_NEXT && hash(hashTable[currentPos].first) != actualNode) {
                previousPos = currentPos;
                currentPos = nextNode[currentPos];
            }

            if (currentPos == NULL_NEXT) {
                doneMoving = true;
            }
            else {
                hashTable[actualNode] = hashTable[currentPos];
                actualNode = currentPos;
                previousNode = previousPos;
            }
        } while (doneMoving == false);

        if (previousNode != NULL_NEXT) {
            nextNode[previousNode] = nextNode[actualNode];
        }
        hashTable[actualNode] = NULL_TELEM;
        nextNode[actualNode] = NULL_NEXT;
        if (actualNode < firstFreePosition) {
            firstFreePosition = actualNode;
        }
    }
    --numberOfElements;
    return oldValue;
}


int Map::size() const {
    return numberOfElements;
}

bool Map::isEmpty() const {
    return numberOfElements == 0;
}

MapIterator Map::iterator() const {
    return MapIterator(*this);
}

Map::~Map() {
    delete[] hashTable;
    delete[] nextNode;
}

bool Map::needsReadjustment() {
    return computeLoadFactor() >= MAXIMUM_LOAD_FACTOR;
}

void Map::readjust() {
    TElem* oldElements = new TElem[numberOfElements];
    for (int i = 0; i < numberOfElements; ++i) {
        oldElements[i] = NULL_TELEM;
    }
    int currentAppendIndex = 0;
    for (int i = 0; i < hashTableCapacity; ++i) {
        if (hashTable[i] != NULL_TELEM) {
            oldElements[currentAppendIndex++] = hashTable[i];
        }
    }

    hashTableCapacity *= 2;
    TElem* newHashTable = new TElem[hashTableCapacity];
    int* newNextNode = new int[hashTableCapacity];
    for (int i = 0; i < hashTableCapacity; ++i) {
        newHashTable[i] = NULL_TELEM;
        newNextNode[i] = NULL_NEXT;
    }
    delete[] hashTable;
    delete[] nextNode;
    hashTable = newHashTable;
    nextNode = newNextNode;

    firstFreePosition = 0;
    int oldNumberOfElements = numberOfElements;
    numberOfElements = 0;
    for (int i = 0; i < oldNumberOfElements; ++i) {
        add(oldElements[i].first, oldElements[i].second);
    }
    delete[] oldElements;
}

int Map::hash(TKey elem) const {
    return elem % hashTableCapacity;
}

double Map::computeLoadFactor() const {
    return (1.0 * numberOfElements) / (1.0 * hashTableCapacity);
}

void Map::updateFirstFreePosition() {
    ++firstFreePosition;
    while (firstFreePosition < hashTableCapacity && hashTable[firstFreePosition] != NULL_TELEM)
        ++firstFreePosition;
}