#pragma once
#include <utility>
#include "Domain.h"


typedef int TKey;
typedef Employee TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE Employee()
#define NULL_TELEM std::pair<TKey, TValue>(-111111, Employee())
class MapIterator;

typedef int (*HashFunction)(int, TKey);

class Map {
	friend class MapIterator;

private:
	TElem* hashTable;
	int* nextNode;
	int numberOfElements;
	int hashTableCapacity;
	int firstFreePosition;
	bool needsReadjustment();
	void readjust();
	int hash(TKey elem) const;
	double computeLoadFactor() const;
	void updateFirstFreePosition();

	const double MAXIMUM_LOAD_FACTOR = 0.65;
	const int NULL_NEXT = -1;

public:

	Map();
	
	TValue add(TKey c, TValue v);

	TValue search(TKey c) const;

	TValue remove(TKey c);

	int size() const;

	bool isEmpty() const;

	MapIterator iterator() const;

	~Map();
};