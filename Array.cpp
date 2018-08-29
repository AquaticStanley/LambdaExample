#include "Array.h"

Array::Array(int size)
{
  m_size = size;
  m_data = new int[size];
  for(int i = 0; i < m_size; i++)
  {
    m_data[i] = 0;
  }
}

Array::Array(const Array& rhs)
{
  if(m_size == rhs.m_size)
  {
    for(int i = 0; i < m_size; i++)
    {
      m_data[i] = rhs.m_data[i];
    }
  }
}

void Array::applyToArray(std::function<void(int&)> funcToApply)
{
  for(int i = 0; i < m_size; i++)
  {
    funcToApply(this->m_data[i]);
  }
}

void Array::applyToArray(std::function<void(Array&)> funcToApply)
{
  funcToApply(*this);
}

int& Array::operator[](int index)
{
  if(index >= 0 && index < m_size)
  {
    return m_data[index];
  }

  throw std::domain_error("Index was not valid.");
}

std::ostream& operator <<(std::ostream& os, Array& array)
{
  for(int i = 0; i < array.m_size; i++)
  {
    os << array.m_data[i] << " ";
  }
  os << std::endl;
  return os;
}