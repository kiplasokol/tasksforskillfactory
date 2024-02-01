#include "integer_array.h"

IntegerArray::IntegerArray() : size(0), data(nullptr) {}

IntegerArray::IntegerArray(int size, int value) : size(size), data(new int[size])
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}

IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size), data(new int[other.size])
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
}

IntegerArray::~IntegerArray()
{
    delete[] data;
}

int& IntegerArray::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw BadRange("Index out of range");
    }
    return data[index];
}

const int& IntegerArray::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        throw BadRange("Index out of range");
    }
    return data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        data = new int[other.size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

int IntegerArray::getSize() const
{
    return size;
}

void IntegerArray::resize(int newSize, int value)
{
    if (newSize < 0)
    {
        throw BadLength("Invalid size");
    }
    int* newData = new int[newSize];
    int elementsToCopy = (newSize < size) ? newSize : size;
    for (int i = 0; i < elementsToCopy; ++i)
    {
        newData[i] = data[i];
    }
    for (int i = elementsToCopy; i < newSize; ++i)
    {
        newData[i] = value;
    }
    delete[] data;
    data = newData;
    size = newSize;
}

void IntegerArray::insert(int index, int value)
{
    if (index < 0 || index > size)
    {
        throw BadRange("Index out of range");
    }
    int* newData = new int[size + 1];
    for (int i = 0; i < index; ++i)
    {
        newData[i] = data[i];
    }
    newData[index] = value;
    for (int i = index; i < size; ++i)
    {
        newData[i + 1] = data[i];
    }
    delete[] data;
    data = newData;
    ++size;
}

void IntegerArray::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw BadRange("Index out of range");
    }
    int* newData = new int[size - 1];
    for (int i = 0; i < index; ++i)
    {
        newData[i] = data[i];
    }
    for (int i = index + 1; i < size; ++i)
    {
        newData[i - 1] = data[i];
    }
    delete[] data;
    data = newData;
    --size;
}
