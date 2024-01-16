# CPP_Modules 🌊➕➕

Welcome to the C++ Modules! <br>
These modules are an introduction to **Object-Oriented Programming** in C++.
<br>
<br>

## 🌠Table of Contents

- [Orthodox Canonical Form](#Orthodox-Canonical-Form)
- [Public, Private, Protected Access Specifiers](#Public-Private-Protected-Access-Specifiers)
- [Deep copy & Shallow copy](#Deep-copy--Shallow-copy)
- [clone()](#clone)
- [Stack & Heap allocation](#Stack--Heap-allocation)
- [Reference & Pointer](#Reference--Pointer)
- [const](#const)
- [Floating-Point & Fixed-Point](#Floating-Point--Fixed-Point)
- [Inheritance](#Inheritance)
- [Inheritance (operator=)](#Inheritance-operator)
- [Virtual Class](#Virtual-Class)
- [Virtual Functions](#Virtual-Functions)
- [Type Casting](#Type-Casting)
- [C++ Modules](#C-Modules)
<br>

## 🌠Useful Resources

These webpages provide a comprehensive resource for C++, containing all the essential information you need. <br>

- [w3schools](https://www.w3schools.com/cpp/cpp_getstarted.asp) 
- [cplusplus](https://cplusplus.com/doc/tutorial/) 
- [programiz](https://www.programiz.com/cpp-programming) 
- [geeksforgeeks](https://www.geeksforgeeks.org/c-plus-plus/)
- [learncpp](https://www.learncpp.com/)
<br>

## 🌠Orthodox Canonical Form

Implement the four required member functions:
- `Default constructor`
- `Copy constructor`
- `Copy assignment operator`
- `Destructor`

### 🎇 Default Constructor:

***Constructor();***
- A default constructor is a special member function of a class <br>
  that is called when an object is created without any arguments. <br>
- It initializes the object's data members, <br>
  to a default value (usually 0 or a specified value). <br>
- It's called automatically when you create an object of the class <br>
  without providing any explicit constructor arguments.

### 🎇 Copy Constructor:

***Constructor(const Constructor& value);***
- A copy constructor is a member function that creates a new object <br>
  by copying the values of another object of the same class.
- It's used to initialize a new object with the same data as an existing object.

### 🎇 Copy Assignment Operator Overload:

***Constructor& operator=(const Constructor& value);***
- The copy assignment operator *(operator=)* is a member function <br>
  that allows you to assign the value of one object <br>
  to another object of the same class.
- It's used to make a deep copy of one object into another. <br>
- It is typically invoked when you use the assignment operator, <br>
  like obj1 = obj2, and ensures that obj1 now holds a copy of obj2's data.

**❗NOTE:❗** <br>
`obj1 = obj2:` *Should work.* <br>
`obj1 = obj2 = obj3:` *Should work.* <br>
`obj1 = obj1:` *Should **NOT** work.* <br>

### 🎇 Destructor:

***~Constructor();***
- A destructor is a special member function that is called when <br>
  an object is destroyed or goes out of scope.
- It is used to perform cleanup operations, <br>
  such as releasing resources or deallocating memory, <br>
  and is the opposite of a constructor.
<br>

## 🌠Public, Private, Protected Access Specifiers

The **public**, **private**, and **protected** access specifiers are used <br> to control the visibility and accessibility of class members <br> *(variables & functions)* within a class and its derived classes.

### 💿 Public:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Members declared as public are **accessible from anywhere in <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;the program**, both within the class and outside the class. <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;They are typically used for the interface of the class, <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;which defines how the class can be used by external code. <br>

### 💿 Private:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Members declared as private are **only accessible within <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;the class** where they are defined. <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;They are not accessible from external code or derived classes. <br> 

### 💿 Protected:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Members declared as protected are **accessible within the class <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;where they are defined and within derived classes**. <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;They are not directly accessible from external code, <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;but they can be accessed by derived classes. <br>
**Example:** <br>
```cpp
class MyBaseClass 
{
  protected:
      int   protectedVar;
      void  protectedFunction();
};

class MyDerivedClass : public MyBaseClass 
{
  public:
      void accessProtected() 
      {
          protectedVar = 42;    // Accessible in derived class.
          protectedFunction();  // Accessible in derived class.
      }
};
```
<br>
<br>

## 🌠Deep copy & Shallow copy

### 🌘 Deep Copy:
- A deep copy creates a new object that is a duplicate of the original object, <br>
and it recursively copies all the objects referenced by the original object.
- Deep copy ensures that the copy is fully independent of the original object. 
- **Any changes made to the copied object or its internal data won't affect the original object.**

### 🌘 Shallow Copy:
- A shallow copy, creates a new object that is a copy of the original object, <br>
but it doesn't recursively copy the objects referenced by the original.
- Instead, a shallow copy maintains references to the same objects as the original.
- Shallow copies are often faster and use less memory than deep copies <br>
because they don't replicate all the data and objects. 
- **Any changes in the copied object can affect the original object and vice versa.**
<br>

*In summary, the key distinction is that a deep copy creates a completely independent duplicate,* <br> 
*while a shallow copy shares some of the underlying data with the original object.*
<br>
<br>


## 🌠clone()

The `clone()` method is fundamental in creating precise replicas of objects. <br>
In object-oriented programming, this method generates a new object that retains <br>
the same state as the original. However, it's essential to note that **clone()** <br>
might not uniformly create new instances for every data component within the object.

- ***A basic clone*** typically replicates the **top-level** object and its references. <br>
  In contrast, a deep copy duplicates the entire structure, including nested objects, <br>ensuring an independent duplicate.

- Changes made in one object reflect in both.
<br>
<br>

## 🌠Stack & Heap allocation

### 🌛 Allocate on the Heap:
- The **heap** is created on the heap using dynamic memory allocation, <br>
  typically through the `new` operator in C++. 
- This means that the memory for the **heap** object is allocated on the heap, <br>
  and you need to manually deallocate it when you're done with it using `delete`. 
- Heap-allocated objects have a longer lifetime and exist <br>
  until explicitly freed by the programmer.
Example:
```c++
int	main()
{
	Heap *newHeap = new Heap("Bob");
	delete newHeap;
	return 0;
}
```

### 🌛 Allocate on the Stack:
- Stack-allocated objects are automatically managed by the program's execution stack. 
- They have a shorter lifetime and are typically limited to the scope in which they are defined. 
- When the scope ends *(e.g., when the function returns)*, <br>
  the stack-allocated objects are automatically destroyed.
Example:
```c++
int	main()
{
	Stack newStack = Stack("Bob");
	return 0;
}
```
<br>

## 🌠Reference & Pointer

### 🪐Syntax:
- 🟣 `Pointers` are declared using the `*` symbol - (int* ptr;), <br> 
      and they need to be dereferenced to access the value they point to `*ptr = 42;`.
- 🟠 `References` are declared using the `&` symbol - (int& ref = someInt;), <br>
      and you access the referenced value directly using the reference variable `ref = 42;`.
<br>

### 🪐Initialization:
- 🟣 `Pointers` can be declared without initialization and can be assigned a value later.
      **Or** can be assigned a special value, `nullptr`, to indicate that they don't point to any valid object. <br> 
      ***This allows for the representation of the absence of a value.***
- 🟠 `References` must be initialized when declared, and once initialized, <br> 
      they cannot be changed to refer to a different object.  <br>
      ***This enforces that references always refer to a valid object.***
<br>

## 🌠const

- `const int fixed()`: This declares a member function fixed that returns a const int, <br> 
  indicating that the integer returned by the function is constant and cannot be modified.

- `int fixed(const int x)`: This declares a member function fixed that takes a constant integer parameter x, <br> 
  meaning that x cannot be modified within the function.

- `int fixed() const`: This declares a member function fixed that is marked as const, <br> 
  indicating that the function can be called on const objects of the class and ensures that <br> 
  the function does not modify the state of the object it is called on.
<br> 

## 🌠Floating-Point & Fixed-Point

### 🌗 Precision:
  - ◻️`Floating-Point:` Numbers offer a variable level of precision. <br> 
    They use a fixed number of bits for the **mantissa** and another set of bits for the **exponent**. <br> 
    This allows them to represent a wide range of values but with varying precision.
  - ◼️`Fixed-Point:` Numbers have a fixed number of decimal places. <br> 
    This means you specify a fixed precision for your numbers, and all numbers have the same precision.
### 🌗 Range:
  - ◻️`Floating-Point:` Numbers can represent a wide range of values, <br> 
    both very small (close to zero) and very large, thanks to the exponent.
  - ◼️`Fixed-Point:` The range is constrained to a predefined interval, <br> 
    determined by the number of bits allocated for the integer and fractional parts.
### 🌗 Storage:
  - ◻️`Floating-Point:` The number does not reserve a specific number of bits for the integer part <br> 
    or the fractional part. 
    Instead it reserves a certain number of bits for the number *(the mantissa or significand)* <br> 
    and a certain number of bits to say where within that number the decimal place sits *(the exponent)*. <br> 
    **~For example:** <br>
    A floating point number that took up 10 digits with 2 digits reserved for the exponent ***might represent***: <br> 
    ***Largest value***: `9.9999999e+50` *(10^50)*, <br>
    ***Smallest non-zero value***: `0.0000001e-49` *(10^-49)*

    ```bash
    9.9999999e+50
    ^^^^^^^^^^^^^
    - Significand (9.9999999)
    - Exponent (50)
    ```
  - ◼️`Fixed-Point:` The number has a specific number of bits *(or digits)* reserved for <br> 
    the integer part *(the part to the left of the decimal point)* and a specific number of bits reserved for <br> 
    the fractional part *(the part to the right of the decimal point)*. <br> 
    No matter how large or small your number is, it will always use the same number of bits for each portion. <br> 
    **~For example:** <br>
    If your fixed point format was in decimal IIIII.FFFFF then: <br>
    ***Largest number*** - `99999.99999`, <br>
    ***Smallest non-zero number*** - `00000.00001`

    ```bash
    99999.99999
    IIIII.FFFFF
    ^^^^^^^^^^^
    - Fractional digits (FFFFF)
    - Integer digits (IIIII)
    ```
### 🌗 Usage:
  - ◻️`Floating-Point:` Suitable for scientific calculations, simulations, and applications <br> 
    where a wide range of values and precision is required.
  - ◼️`Fixed-Point:` Suitable for applications where you need a consistent level of precision <br> 
    and don't want to deal with the variability and potential rounding errors of floating-point numbers.

### 🌗 Floating-Point level of precision:
Floating-point represent real numbers *(numbers with decimal points)*. <br>
A Floating-point number is composed of two main parts.
1. `Mantissa:` The first part is called the **"mantissa"**, which stores the significant digits of the number. <br>
  It represents the actual value you want to work with.
2. `Exponent:` The second part is the **"exponent"**, which indicates the scale or magnitude of the number. <br> 
  It shows where the decimal point should be placed in the mantissa.
3. `Sign:` Floating-point numbers can be positive or negative, <br> 
  so there's also a sign bit to represent the sign of the number.

![image](https://www.c-programming-simple-steps.com/images/xIEEE-754-float-representation.png.pagespeed.ic.wRFQquB-9H.webp)
<br>

### 🌗 Difference between a Floating-Point, Fixed-Point, float and double:

- **Floating-point** numbers include both float and double.
- *Float* and *double* are standard floating-point data types, <br> 
  designed to represent real numbers with variable precision.
  <br>
  <br>
- **Fixed-point** numbers don't have predefined data types. 
- Fixed-point numbers are typically implemented using integer data types *(e.g., int, long)* <br> 
  with a specific interpretation of the position of the decimal point.
<br>

## 🌠Inheritance
Inheritance is a fundamental concept in **object-oriented programming** *(OOP)*, and it plays a central role in C++. <br>
- It allows you to create a new class *(derived or child class)* based on an existing class *(base or parent class)*. <br>
- Inheritance enables the child class to inherit the properties and behaviors <br> *(data members & member functions)* of the parent class, which promotes code reuse and the creation <br> of a hierarchical structure in your program.<br>

- In C++, there are different types of inheritance, including `single inheritance`, `multiple inheritance`, and `multilevel inheritance`. <br>

### ☁️ Single Inheritance:
Single inheritance is the simplest form of inheritance and means that a derived class inherits from a single base class.<br> **~For example:** <br>
*The `Dog` class derives from the `Animal` class and inherits the `eat` method.*<br>
```cpp
class Animal	// Base class
{
       public:
	   void eat();
};

class Dog : public Animal   // Derived class
{
       public:
	   void bark();
};
```

### ☁️ Multiple Inheritance:
Multiple inheritance allows a derived class to inherit from multiple base classes. <br>In other words, a single derived class can have attributes and behaviors from more than one parent class. <br>
**~For example:** <br>
*The `Child` class inherits both `function1` from `Parent1` and `function2` from `Parent2`* <br>
```cpp
class Parent1	// Base class
{
       public:
	   void function1();
};

class Parent2	// Base class
{
       public:
	   void function2();
};

class Child : public Parent1, public Parent2 // Derived class
{
       public:
	   void childFunction()
	   {
		function1();
		function2();
	   }
};

```
<br>

❗ For more insights into multiple inheritance, you can explore detailed explanations <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; on the subject at [Geeksforgeeks](https://www.geeksforgeeks.org/multiple-inheritance-in-c/).

<br>

## 🌠Inheritance (operator=)
❄️ **Option A:** <br> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In this implementation, you perform a **deep copy** by manually copying each member variable <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;from the source object to the target object. <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This approach ensures that the two objects are entirely independent of each other. <br>
&nbsp;&nbsp;**For example:**
```c++
ClassA& ClassA::operator=(const ClassA& value)
{
    // Perform a deep copy
    _name = value._name;
    _points = value._points;
    _energy = value._energy;
    _damage = value._damage;
    return *this;
}
```
<br>

❄️ **Option B:** <br> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In this implementation, the assignment operator delegates the assignment operation <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to a `base class`, BaseClass, by calling its assignment operator. <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This is commonly used when a `derived class` DerivedClass inherits from a base class BaseClass. <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;By invoking the base class's assignment operator, you effectively reuse <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;the assignment logic defined in the base class. <br>
&nbsp;&nbsp;**For example:**
```c++
DerivedClass& DerivedClass::operator=(const DerivedClass& value)
{
    BaseClass::operator=(value);
    return *this;
}
```
<br>

**The key difference:** <br>
- *`Option A:` manually copies each member, making it a deep copy.* <br>
- *`Option B:` relies on the base class's assignment operator to handle the assignment, which can simplify the code.*
<br>
<br>

## 🌠Virtual Class
In object-oriented programming, a `virtual base class` is a base class that <br> is declared as **"virtual"** in a class hierarchy. <br> This concept is used to address issues that can arise in multiple inheritance scenarios, <br> particularly when you have a class hierarchy with diamond-shaped inheritance patterns. <br> <br>

### ✖️ Diamond Inheritance Problem:
*You have a class hierarchy like this: (diamond-shaped inheritance pattern)*
```bash

     BaseClass_⚫	 |	BaseClass_⚫ --> is the base class.
	/   \		 |
       /     \		 |
      /       \		 |
     /         \	 |
Class_🔴     Class_🔵	 |	Class_🔴 inherit from BaseClass_⚫ --> is a derived class, BUT a base class for Class_🟡.
     \         /	 |	Class_🔵 inherit from BaseClass_⚫ --> is a derived class, BUT a base class for Class_🟡.
      \       /		 |
       \     /		 |
	\   /		 |
       Class_🟡		 |	Class_🟡 inherits from both Class_🔴 and Class_🔵 --> is a derived class.

```
- The **issue with this setup** is that when you create an instance of `Class_🟡`, it inherits `BaseClass_⚫` from both `Class_🔴` and `Class_🔵`.
- This can lead to [ambiguity](https://dictionary.cambridge.org/dictionary/english/ambiguity) and problems when trying to access members *(variables or functions)* from BaseClass. <br>

### ✔️ Virtual Inheritance Solution:
To resolve the diamond inheritance problem and ensure that there's only one instance of the `BaseClass_⚫` shared among `Class_🔴` and `Class_🔵`, you should use virtual inheritance. <br>
```cpp
class BaseClass_⚫
{
    // ... (rest of the code)
};

class Class_🔴 : virtual public BaseClass_⚫   // Use virtual inheritance
{ 
    // ... (rest of the code)
};

class Class_🔵 : virtual public BaseClass_⚫   // Use virtual inheritance
{
    // ... (rest of the code)
};

class Class_🟡 : public Class_🔴, public Class_🔵 
{
    // ... (rest of the code)
};

```
<br>
<br>

## 🌠Virtual Functions

### 🔆 Virtual Function:
- **Usage:** A virtual function in a base class is a function that can be overridden in derived classes.
- **Implementation:** It has an implementation in the base class, but it can be overridden in derived classes to provide a different implementation.
- **Example:** In a Shape base class with a virtual function draw(), various shapes like Circle and Square can override this function to draw themselves differently while sharing the same base function name.<br>
**"It's handy when you want different versions of something in your program to behave slightly differently."**

***Virtual Function Example:***
```c++
// Base class
class Shape 
{
  public:
      virtual void draw() // Virtual function - has a function body
      {
          std::cout << "Drawing a shape." << std::endl;
      }
};

// Derived classes
class Circle : public Shape 
{
  public:
      void draw() // draw()-Circle will overwrite draw()-Shape
      {
          std::cout << "Drawing a circle." << std::endl;
      }
};

class Square : public Shape 
{
  public:
      void draw() // draw()-Square will overwrite draw()-Shape
      {
          std::cout << "Drawing a square." << std::endl;
      }
};

int main() 
{
    Circle circle;
    Square square;
    Shape* shape1 = &circle;
    Shape* shape2 = &square;

    // Calls the overridden draw functions
    shape1->draw(); // Output: "Drawing a circle."
    shape2->draw(); // Output: "Drawing a square."

    return 0;
}
```
<br>

### 🔆 Pure Virtual Function:
Classes containing pure `virtual functions` are known as `abstract classes`.<br>
Abstract classes cannot be instantiated directly; they are meant to be inherited by derived classes.
- **Usage:** A pure virtual function in a base class is a function that must be overridden in derived classes; it is declared in a base class but has no implementation in the base class *(no function body)*.
- **Implementation:** It has no implementation in the base class and must be overridden by derived classes.<br>
  It's a function declared with = 0 `virtual void func() = 0;`.
- **Example:** In a Vehicle base class with a pure virtual function start(), all derived vehicles like Car and Bike must implement their specific way of starting the vehicle. They cannot be instantiated directly because the base class lacks an implementation for this critical functionality.

***Pure Virtual Function Example:***
```c++
// Base class
class Vehicle 
{
  public:
      virtual void start() = 0; // Pure virtual function - has no function body - no implementation
};

// Derived classes
class Car : public Vehicle 
{
  public:
      void start() // Implementation of the pure virtual function for Car 
      {
          std::cout << "Car started." << std::endl;
      }
};

class Bike : public Vehicle 
{
  public:
      void start() // Implementation of the pure virtual function for Bike
      {
          std::cout << "Bike started." << std::endl;
      }
};

int main() 
{
    Car myCar;
    Bike myBike;
    Vehicle* vehicle1 = &myCar;
    Vehicle* vehicle2 = &myBike;

    // Calls the overridden start functions
    vehicle1->start();  // Output: "Car started." 
    vehicle2->start();  // Output: "Bike started." 

    return 0;
}
```

**Key Distinction:** *virtual function has a default implementation in the base class but can be overridden, while a pure virtual function has no implementation in the base class and must be overridden in the derived classes to provide functionality.*
<br>
<br>

## 🍄Type Casting

**🌸 static_cast:** *- used on types* <br>
It implicit conversions between types (such as int to float, or pointer to void*). <br> 
It is unnecessary when casting upwards *(towards a base class)*, <br>
but when casting downwards it can be used as long as it doesn't cast through virtual inheritance. 

**🏵️ dynamic_cast:** *- used on classes* <br>
It's used to convert pointers or references of a base class to pointers or references of a derived class. <br>
Works only with **pointers or references** to polymorphic classes *(i.e., classes containing at least one virtual function)*. <br>
The dynamic_cast will seek out the desired object and return it if possible. <br>
- `dynamic_cast<Derived*>(basePointer) `*->* if the cast fails, it will return nullptr. <br>
- `dynamic_cast<Derived&>(baseReference)` *->* if the cast fails, it will throw std::bad_cast, *(use try/catch)* <br>

It doesn't work if you aren't using virtual inheritance and it will always fail to travel through protected or private inheritance *(can only go through public inheritance)*.

**💮 const_cast:** <br>
Can be used to remove or add const to a variable.

**🌼 reinterpret_cast:** <br>
It turns one type directly into another, such as casting the value from one pointer to another, or storing a pointer in an int, or all sorts of other nasty things.
<br>
<br>

## 🌠C++ Modules

<details>
  <summary><strong>Module 00:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Namespace, class, member functions, and some basic stuff...)</em></summary>
<br>
  
## Module 00
These exercises provide a range of practical skills and knowledge for working with C++ and building more complex programs, from basic string manipulation to object-oriented programming and debugging.

### 🔸Exercise 00 - Megaphone
This exercise is about string manipulation and basic C++ program structure. <br>
**You'll learn or practice:**
1. Command-line argument handling in C++.
2. Converting strings to uppercase.
3. Creating a simple C++ program structure with Makefile.

<br>

### 🔸Exercise 01 - My Awesome PhoneBook
This exercise focuses on creating a simple phonebook program in C++ and using classes.<br>
**You'll learn or practice:**
1. Object-oriented programming (OOP) concepts, including class design and encapsulation.
2. Input and output in C++, including formatting output.
3. Command-line interaction and implementing basic command parsing.
4. Memory management without dynamic allocation.

<br>

### 🔸Exercise 02 - The Job Of Your Dreams
In this exercise, you are tasked with recreating a missing source file based on provided header files and a log file. <br>
**You'll learn or practice:**
1. Reverse engineering C++ code from header files and expected output.
2. Debugging and fixing C++ code to match specified requirements.
3. Understanding code functionality and relationships between different code files.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2000)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 01:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> New, pointers to members, references, switch statement, Memory allocation)</em></summary>
  <br>

 ## Module 01
Each of these exercises in the C++ module teaches you different aspects of C++ programming, including object-oriented programming, memory management, file handling, and more. 

### 🔸Exercise 00 - BraiiiiiiinnnzzzZ
This exercise covers the fundamentals of object-oriented programming in C++ and memory management. <br>
**You'll learn or practice:**
1. Creation of a simple class with private attributes and member functions.
2. Memory management, including object creation on the stack and heap.
3. Practice with C++ class constructors and destructors.

<br>

### 🔸Exercise 01 - Moar brainz!
This exercise focuses on creating pointers to objects and arrays.<br>
**You'll learn or practice:**
1. Allocation and management of memory for an array of objects.
2. Usage of pointers to objects and arrays.
3. Initialization and utilization of objects within an array.

<br>

### 🔸Exercise 02 - HI THIS IS BRAIN
This exercise explores pointers and references in C++ through string manipulation. <br>
**You'll learn or practice:**
1. Understand the concept of pointers and references in C++.
2. Practice printing memory addresses and values of variables, pointers, and references.

**NOTE:**
- (*PTR) can change the value and the address without influencing the original variable.
- (&REF) can change the original value.

<br>

### 🔸Exercise 03 - Unnecessary violence
In this exercise, you'll work with classes and objects, emphasizing constructors and object interactions. <br>
**You'll learn or practice:**
1. Learn about classes and objects in C++.
2. Practice using constructors to initialize objects.
3. Experience with object composition and interactions.

**NOTE:**
- For HumanA, Weapon (&REF) is required to/cannot be NULL; it always needs a weapon.
- For HumanB, Weapon (*PTR) can be NULL, allowing you to call attack() without setting the Weapon.
<br>

### 🔸Exercise 04 -  Sed is for losers
This exercise involves file handling and string manipulation, requiring you to recreate a missing source file <br>
**You'll learn or practice:**
1. Handling files in C++ without using C file manipulation functions.
2. String manipulation and replacement.
3. Error handling and input validation.

**NOTE:** <br>
*Take care of:*
```bash
$ ./replace infile "" "hello"
$ ./replace infile "bee" "bee"
$ ./replace infile "bee" "been"
$ ./replace wrong_infile "hello" "Hello"
```
<br>

### 🔸Exercise 05 - Harl 2.0
In this exercise, you are tasked with recreating a missing source file based on provided header files and a log file. <br>
**You'll learn or practice:**
1. Usage of pointers to member functions in C++.
2. Implementation of a logging system with different log levels.

<br>

### 🔸Exercise 06 - Harl filter
This exercise focuses on program behavior control using the switch statement and log filtering. <br>
**You'll learn or practice:**
1. Application of the switch statement in C++.
2. Filtering and displaying messages based on log levels.
3. Gaining experience in controlling program behavior using conditional statements.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2001)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 02:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Ad-hoc polymorphism, operator overload and Orthodox Cononical classes)</em></summary>
  <br>
	
## Module 02
This exercises provide a structured progression of learning, starting from building a basic class and gradually extending its capabilities to solve more complex problems in the context of geometric calculations and computer graphics.

### 🔸Exercise 00 - My First Class in Orthodox Canonical Form
This program introduces you to the Orthodox Canonical Form.<br>
**You'll learn or practice:**
1. Create a class representing fixed-point numbers in Orthodox Canonical Form.
- `Default constructor`
- `Copy constructor`
- `Copy assignment operator`
- `Destructor`
2. You need to implementing member functions and operator overloading in C++.

<br>

### 🔸Exercise 01 - Towards a more useful fixed-point number class
You expand the functionality of your Fixed class to handle various constructors and conversions.<br>
**You'll learn or practice:**
1. You'll deal with operator overloading, including overloading the insertion *(<<)* operator for output stream.
2. You will learn how to convert between fixed-point numbers and floating-point numbers or integers.

<br>

### 🔸Exercise 02 - Now we’re talking
This exercise builds on the Fixed class by overloading comparison operators and arithmetic operators. <br>
**You'll learn or practice:**
1. You'll implement the 6 comparison operators: `>`, `<`, `>=`, `<=`, `==` and `!=`.
2. You'll implement the 4 arithmetic operators: `+`, `-`, `*`, and `/`.
3. You'll implement `(++i)`*pre-increment*, `(i++)`*post-increment, `(--i)*`pre-decrement* and `(i--)`*post-decrement* operators.
4. You need to create static member functions and use them for finding the minimum and maximum values among fixed-point numbers.
   
<br>

### 🔸Exercise 03 - BSP  (Binary Space Partitioning)
In this exercise, you apply the concepts you've learned in the previous exercises to solve a real-world problem, which involves checking if a point is inside a triangle. <br>
**You'll learn or practice:**
1. You'll implement a function that performs geometric calculations to determine if a point is inside a triangle using ***Binary Space Partitioning (BSP)***.
3. This exercise reinforces your understanding of classes, operators, and geometric calculations in C++.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2002)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 03:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Inheritance)</em></summary>
  <br>
	
## Module 03
This exercises offers a structured learning journey, providing insights into the mechanics of inheritance and the nuances of multiple inheritance.

### 🔸Exercise 00 - Aaaaand... OPEN!
This exercise guides you in creating the `ClapTrap` class, which incorporates private attributes with predefined default values and public member functions.<br>
**You'll learn or practice:**
1. Defining constructors and a destructor.
2. Managing class attributes.
3. Displaying informative messages during the class's operations.

<br>

### 🔸Exercise 01 - Serena, my love!
This exercise introduces the derived class `ScavTrap`, inheriting from the base class ClapTrap. <br>
**You'll learn or practice:**
1. Customizing and overriding member functions within the derived class.
2. Maintaining the correct order of construction and destruction.
3. Expanding the class with new attributes and functionality.

<br>

### 🔸Exercise 02 - Repetitive work
This exercise expands your knowledge by creating another derived class, `FragTrap`, which inherits from ClapTrap. 
<br>
**You'll learn or practice:**
1. Distinguishing the derived class from the base class with custom construction and destruction messages.
2. Ensuring proper class inheritance and conducting comprehensive testing.

<br>

### 🔸Exercise 03 - Now it’s weird!
In the final exercise, you'll create a hybrid class named `DiamondTrap` that inherits from both FragTrap and ScavTrap. 
<br>
**You'll learn or practice:**
1. Multiple inheritance, allowing a class to inherit attributes and functionality from two different base classes.
2. Hndling the intricacies of maintaining the ClapTrap subobject and adding additional unique features.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2003)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 04:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Subtype polymorphism, abstract classes, interfaces)</em></summary>
  <br>

## Module 04
This module focuses on mastering object-oriented concepts such as classes, inheritance, polymorphism, memory management, and abstract classes/interfaces. <br>Each exercise progressively builds upon the previous one, introducing new challenges and reinforcing concepts.

### 🔸Exercise 00 - Polymorphism
In this exercise you need to implements basic polymorphism. <br> 
You will make a Animal base class with Dog and Cat derived classes, <br> 
for each class you need to implementing makeSound(). <br>
Introduces WrongCat inheriting from WrongAnimal to demonstrate overriding behaviors.<br>
**You'll learn or practice:**
1. **Polymorphism:** Implementing inheritance, overriding functions, and utilizing base class pointers for derived class objects.
2. **Inheritance:** Creating base and derived classes *(Animal, Dog, Cat)* to showcase inheritance relationships.
3. **Virtual Functions:** Implementing and utilizing virtual functions *(makeSound())*.

<br>

### 🔸Exercise 01 - I don’t want to set the world on fire
This exercise focuses on memory allocation, deallocation, ensuring deep copying, and managing object destruction through inheritance. You'll handle dynamic memory for objects *(like the Brain class)*, ensure proper deep copying for derived classes *(Dog, Cat)*, and implement destructors to prevent memory leaks.<br>
**You'll learn or practice:**
1. **Memory Allocation and Deallocation:** Managing memory for objects with dynamic memory *(Brain class).*
2. **Deep Copy:** Ensuring objects of derived classes *(Dog, Cat)* are properly deep-copied.
3. **Destructors:** Implementing proper destructors to prevent memory leaks.

<br>

### 🔸Exercise 02 - Abstract class
This exercise involves preventing direct instantiation of the base class Animal by creating an abstract class. <br>
**You'll learn or practice:**
1. **Abstract Classes:** Creating an abstract base class *(Animal)* to prevent direct instantiation.
2. **Class Design:** Ensuring functionality remains intact while preventing direct instantiation.

<br>

### 🔸Exercise 03 - Interface & recap
Implement interfaces using pure abstract classes and recap concepts. <br>
**You'll learn or practice:**
1. **Pure Abstract Classes:** Implementing interfaces using pure abstract classes (*AMateria, ICharacter)*.
2. **Interface Design:** Designing interfaces and concrete classes that adhere to them *(Ice, Cure)*.
3. **Memory Management with Interfaces:** Managing object interactions and memory when using interfaces.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2004)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 05:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Repetition and Exceptions)</em></summary>
  <br>

## Module 05
These exercises are about repetition and exceptions *(throw exceptions)*, learing about try-catch blocks. 

### 🔸Exercise 00 - Mommy, when I grow up, I want to be a bureaucrat!
This exercise provides hands-on experience in designing a class with exception handling. <br>
**You'll learn or practice:**
1. Learn to implement custom exceptions *(GradeTooHighException and GradeTooLowException)* to handle invalid grade scenarios during the instantiation and grade modification of a Bureaucrat.
2.  Gain practical experience in using try and catch blocks to handle exceptions, ensuring robust error management in the program.

<br>

### 🔸Exercise 01 - Form up, maggots!
 This exercise provides practical experience in designing classes that interact with each other, handling exceptions, and ensuring proper member function implementation.<br>
**You'll learn or practice:**
1. Practice throwing and catching exceptions in the context of class methods, understanding how to propagate errors appropriately.
2. Understand how objects of different classes *(Form and Bureaucrat)* interact with each other through member function calls.
3. Initialization and utilization of objects within an array.

<br>

### 🔸Exercise 02 - No, you need form 28B, not 28C...
This exercise provides hands-on experience in designing and implementing abstract classes, handling exceptions in class hierarchies, and ensuring proper collaboration between classes. <br>
**You'll learn or practice:**
1.  Practice designing an **abstract class** *(AForm)* with private attributes, ensuring that it serves as a base class for concrete form implementations.

<br>

### 🔸Exercise 03 - At least this beats coffee-making
This exercise provides hands-on experience in designing a **utility class**, working with dynamic object creation, pointers, and error handling. <br>
**You'll learn or practice:**
1. Practice designing a **utility class** *(Intern)* with a specific purpose—creating forms based on given parameters.
2.  Learn to dynamically create objects *(forms)* within the **makeForm() function**, returning a pointer to the created object.
3.  Understand the use of pointers to manage and manipulate dynamically allocated objects, specifically in the context of creating and returning form objects.
4. Finding **alternatives to if/elseif/else** forests for efficient and maintainable code.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2005)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 06:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> C++ casts)</em></summary>
  <br>

## Module 06
These exercises will teach you different **typecast methods** *(static_cast, dynamic_cast, reinterpret_cast)*, how to implement them. 

### 🔸Exercise 00 - Conversion of scalar types
This exercise provides practical insights into designing a class with static methods, handling different scalar types. <br>
**You'll learn or practice:**
1. Implement the conversion of a string representation to various scalar types (char, int, float, double).
2. Practice validating and handling scenarios where a conversion may not make sense or overflows.

<br>

### 🔸Exercise 01 - Serialization
This exercise provides hands-on experience in handling memory addresses, implementing serialization and deserialization logic. <br>
**You'll learn or practice:**
1. Learn to implement a class *(Serializer)* with a static method *(serialize)* that **converts a pointer to an unsigned integer** *(uintptr_t)*.
2. Develop the counterpart static method *(deserialize)* that **converts an unsigned integer back to a pointer**.
3. Learn about the potential risks and considerations when converting between pointers and unsigned integers.

<br>

### 🔸Exercise 02 - Identify real type
This exercise provides practical exposure to polymorphism, virtual functions, and type identification without using the typeinfo header. <br>
**You'll learn or practice:**
1. Creating a function that prints the actual type of the object **pointed** to by a base pointer *(Base*)*.
2. Creating a function that prints the actual type of the object **referenced** by a base reference *(Base&)*.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2006)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 07:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> C++ templates)</em></summary>
  <br>

## Module 07
Each of these exercises in the C++ module teaches about how to use and implement templates functions and classes.

### 🔸Exercise 00 - Start with a few functions
This exercise provides a practical understanding of generic programming, enabling the creation of versatile functions that work seamlessly with different data types. <br>
**You'll learn or practice:**
1. Writing functions that can be called with any type of argument.
2. Gaining proficiency in the syntax and structure of function templates.

<br>

### 🔸Exercise 01 - Iter
This exercise emphasizes generic programming, showcasing how a single function template can be applied to arrays of different types.<br>
**You'll learn or practice:**
1. Practice dealing with memory addresses and understanding the nuances of working with arrays.
2. Gain proficiency in using pointers to access and manipulate elements within an array.
3. Understand how to pass a function as a parameter to your template, allowing for adaptable and versatile array processing.

<br>

### 🔸Exercise 02 - Array
This exercise provides a comprehensive understanding of class templates in C++, focusing on dynamic memory allocation, proper implementation of constructors and operators, and ensuring safe array access through exception handling. <br>
**You'll learn or practice:**
1. Practice creating a class template *(Array)* capable of storing elements of any type *(T)*.
2. Learn how to allocate memory dynamically using the **new[]** operator for flexible array sizing.
3. Implement error handling by throwing an **std::exception**.
4. Learn to implement different constructors and operators.

<br>

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2007)  ⬅️
<br>
<br>

</details>

---

<details>
  <summary><strong>Module 08:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Templated containers, iterators, algorithms)</em></summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary><strong>Module 09:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> STL)</em></summary>
  <br>
  <br>
  <br>

</br>

</details>
<br>


