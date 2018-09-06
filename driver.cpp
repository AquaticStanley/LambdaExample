// This is a simple example for reusing code with lambdas

// Dependencies
#include <iostream>
#include <vector>
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

  // Zero out array
  auto zeroOut = [](int& element) { element = 0; };
  array.applyToArray(zeroOut);

  cout << "Zeroed out array:\n";
  cout << array << endl;

  // Make lambdas programmatically
  cout << "Make lambdas progmatically:\n";
  std::vector<std::function<void(int&)>> lambdaVect;

  for(int i = 0; i < 5; i++)
  {
    auto newLambda = [i](int& element) { element += i; };
    lambdaVect.push_back(newLambda);
  }

  for(unsigned int i = 0; i < lambdaVect.size(); i++)
  {
    cout << "Add " << i << " to all elements:\n";
    array.applyToArray(lambdaVect[i]);
    cout << array;
    cout << "Zeroing out...\n" << endl;
    array.applyToArray(zeroOut);
  }
}