#include "phoneBook.hpp"

void MyClass::myMethod() 
{
  std::cout << "Hello World!";
}

int main() 
{
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  // Print attribute values
  std::cout << myObj.myNum << "\n";
  std::cout << myObj.myString <<"\n";

  myObj.myMethod();  // Call the method

  myObj.x = 25;  // Allowed (public)
  // myObj.y = 50;  // Not allowed (private) //WONT EVENCOMPILE

  myObj.setSalary(50000);
  std::cout << myObj.getSalary();

  return 0;
}
