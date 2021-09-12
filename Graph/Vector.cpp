#include "Vector.h"

Vector::Vector(unsigned int size) : size{ size }, capacity(size + supply)
{
	data = new int[capacity];
}

Vector::~Vector()
{
	delete[] data;
}

Vector::Vector(const Vector& copyVector) : size{ 0 }, capacity{ 0 }, data{ nullptr }
{
	*this = copyVector;
}

Vector& Vector::operator=(const Vector& copyVector)
{
	if (this != &copyVector)
	{
		delete[] data;
		size = copyVector.size;
		capacity = copyVector.capacity;
		data = new int[size + capacity];
		for (size_t counter = 0; counter < copyVector.size; counter++)
		{
			data[counter] = copyVector.data[counter];
		}
	}
	return *this;
}

void Vector::resize(unsigned int newSize)
{
	if (newSize < size)
	{
		return;
	}
	if (newSize > capacity)
	{
		reserve(newSize);
	}
}

void Vector::reserve(unsigned int newCapacity)
{
	if (newCapacity < capacity)
	{
		return;
	}
	int* buffer = data;
	data = new int[size + newCapacity];
	for (size_t counter = 0; counter < size; counter++)
	{
		data[counter] = buffer[counter];
	}
	delete[] buffer;
}

const int& Vector::operator[](unsigned int index) const
{
	assert(isLegalIndex(index) && "Out of vector range!");
	return data[index];
}

void Vector::push_back(int newMember)
{
	if (size == capacity)
	{
		reserve(capacity);
	}
	data[size++] = newMember;
}

void Vector::pop_back()
{
	size--;
}
