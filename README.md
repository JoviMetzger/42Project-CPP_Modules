# CPP_Modules 🌊➕➕

Welcome to the C++ Modules! <br>
These modules are an introduction to **Object-Oriented Programming** in C++.
<br>
<br>

## 🌠Table of Contents

- [Orthodox Canonical Form](#Orthodox-Canonical-Form)
- [Deep copy & Shallow copy](#Deep-copy--Shallow-copy)
- [Stack & Heap allocation](#Stack--Heap-allocation)
- [Reference & Pointer](#Reference--Pointer)
- [const](#const)
- [Floating-Point & Fixed-Point](#Floating-Point--Fixed-Point)
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

### 🎆 Default Constructor:

***Constructor();***
- A default constructor is a special member function of a class <br>
  that is called when an object is created without any arguments. <br>
- It initializes the object's data members, <br>
  to a default value (usually 0 or a specified value). <br>
- It's called automatically when you create an object of the class <br>
  without providing any explicit constructor arguments.

### 🎆 Copy Constructor:

***Constructor(const Constructor& value);***
- A copy constructor is a member function that creates a new object <br>
  by copying the values of another object of the same class.
- It's used to initialize a new object with the same data as an existing object.

### 🎆 Copy Assignment Operator Overload:

***Constructor& operator(const Constructor& value);***
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

### 🎆 Destructor:

***~Constructor();***
- A destructor is a special member function that is called when <br>
  an object is destroyed or goes out of scope.
- It is used to perform cleanup operations, <br>
  such as releasing resources or deallocating memory, <br>
  and is the opposite of a constructor.
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
Tis exercises provide a structured progression of learning, starting from building a basic class and gradually extending its capabilities to solve more complex problems in the context of geometric calculations and computer graphics.

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
  <br>
  <br>

</br>

</details>

---

<details>
  <summary><strong>Module 04:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Subtype polymorphism, abstract classes, interfaces)</em></summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary><strong>Module 05:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Repetition and Exceptions)</em></summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary><strong>Module 06:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> C++ casts)</em></summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary><strong>Module 07:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> C++ templates)</em></summary>
  <br>
  <br>
  <br>

</br>

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
  <summary><strong>Module 09:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> )</em></summary>
  <br>
  <br>
  <br>

</br>

</details>
<br>


