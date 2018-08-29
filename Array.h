#pragma once

#include <functional>
#include <iostream>
#include <exception>

class Array
{
private:
  int* m_data;
  int m_size;

public:
  Array(int size);
  Array(const Array& rhs);
  ~Array() { delete[] m_data; }

  int getSize() const { return m_size; }

  void applyToArray(std::function<void(int&)> funcToApply);
  void applyToArray(std::function<void(Array&)> funcToApply);

  int& operator[](int index);
  friend std::ostream& operator <<(std::ostream& os, Array& array);
};