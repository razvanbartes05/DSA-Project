#include "Map.h"
#include "MapIterator.h"
#include <exception>
#include <stdexcept>

using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    first();
}


void MapIterator::first() {
    currentIndex = 0;
    while (currentIndex < map.hashTableCapacity && map.hashTable[currentIndex] == NULL_TELEM) {
        ++currentIndex;
    }
}


void MapIterator::next() {
    if (!valid())
        throw std::runtime_error("");
    ++currentIndex;
    while (currentIndex < map.hashTableCapacity && map.hashTable[currentIndex] == NULL_TELEM) {
        ++currentIndex;
    }
}


TElem MapIterator::getCurrent() {
    if (!valid())
        throw std::runtime_error("");
    return map.hashTable[currentIndex];
}


bool MapIterator::valid() const {
    return currentIndex < map.hashTableCapacity;
}

