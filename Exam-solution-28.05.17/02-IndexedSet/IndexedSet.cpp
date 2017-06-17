#include "IndexedSet.h"

IndexedSet::IndexedSet() :
	valuesSet(),
	valuesArray(nullptr)
{
}

IndexedSet::IndexedSet(const IndexedSet& other) :
	valuesSet(other.valuesSet),
	valuesArray(nullptr)
{
}

void IndexedSet::add(const Value& v)
{
	clearIndex();
	valuesSet.insert(v);
}

size_t IndexedSet::size() const
{
	return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index)
{
	if (!valuesArray)
		buildIndex();

	return valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)	
{
	if (this != &other)
	{
		valuesSet = other.valuesSet;
		valuesArray = nullptr;
	}

	return *this;
}

IndexedSet::~IndexedSet()
{
	clearIndex();
}

void IndexedSet::buildIndex()
{
	valuesArray = new Value[valuesSet.size()];
	int pos = 0;
	for (const int elm : valuesSet)
	{
		valuesArray[pos++] = elm;
	}
}

void IndexedSet::clearIndex()
{
	delete[] valuesArray;
	valuesArray = nullptr;
}

