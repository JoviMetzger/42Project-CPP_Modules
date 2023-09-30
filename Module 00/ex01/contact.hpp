#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

class Contact
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