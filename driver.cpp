// This is a simple example for reusing code with lambdas

// Dependencies
#include <iostream>
#include "Array.h"

// Convenient outputting
using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Program Start\n\n";

  Array array(5);

  for(int i = 0; i < array.getSize(); i++)
  {
    array[i] = i;
  }

  cout << "Initial array state:\n";
  cout << array << endl;

  // Apply simple rule to each element
  array.applyToArray([](int& element) { element +=1; });

  cout << "Added 1 to each element:\n";
  cout << array << endl;

  // Apply rule depending on other element to each element
  array.applyToArray( [] (Array& fullArray) {
    int tempElement = fullArray[1];
    for(int i = 0; i < fullArray.getSize(); i++)
    {
      fullArray[i] += tempElement;
    }
  });

  cout << "Added element at array[1] to each element:\n";
  cout << array << endl;

  // Apply simple rule to each element with stored lambda
  auto lambda = [](int& element) { element += 1; };
  array.applyToArray(lambda);

  cout << "Added 1 to each element:\n";
  cout << array << endl;
}