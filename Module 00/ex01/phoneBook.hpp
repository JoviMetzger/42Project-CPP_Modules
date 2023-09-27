#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>

class MyClass               // The class
{
  private:
    //int y;
    int salary;
  public:                   // Access specifier
    int myNum;              // Attribute (int variable)
    std::string myString;   // Attribute (string variable)
    void myMethod();
    int x;
    void setSalary(int s)   //Setter
    {
      salary = s;
    }
    int getSalary()         // Getter
    {
      return salary;
    }
};

#endif