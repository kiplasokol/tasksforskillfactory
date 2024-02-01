#ifndef INTEGER_ARRAY_H
#define INTEGER_ARRAY_H

#include <stdexcept>
#include <iostream>

class BadRange : public std::out_of_range
{
public:
    BadRange(const std::string& message) : std::out_of_range(message) {}
};

class BadLength : public std::length_error
{
public:
    BadLength(const std::string& message) : std::length_error(message) {}
};

class IntegerArray
{
public:
    IntegerArray();
    IntegerArray(int size, int value = 0);
    IntegerArray(const IntegerArray& other);
    ~IntegerArray();

    int& operator[](int index);
    const int& operator[](int index) const;
    IntegerArray& operator=(const IntegerArray& other);

    int getSize() const;
    void resize(int newSize, int value = 0);
    void insert(int index, int value);
    void remove(int index);

private:
    int size;
    int* data;
};

#endif // INTEGER_ARRAY_H