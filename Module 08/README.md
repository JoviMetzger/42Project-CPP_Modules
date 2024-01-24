

---

<details>
  <summary><strong>Module 01:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> New, pointers to members, references, switch statement, Memory allocation)</em></summary>
  <br>

## Module 08
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

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2008)  ⬅️
<br>
<br>

</details>

---


---

<details>
  <summary><strong>Module 01:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> New, pointers to members, references, switch statement, Memory allocation)</em></summary>
  <br>

## Module 09
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

➡️  [Installing/running the programs](https://github.com/JoviMetzger/42Project-CPP_Modules/tree/main/Module%2009)  ⬅️
<br>
<br>

</details>

---


# Module 08

## 🌀 Exercise 00
### Description
This exercise ia about finding a value in a container.
<br>
### Installation
1. Compile the program:
```bash 
$ make 
```
2. Run the program with input:
```bash 
$ ./ex00
```
<br>
<br>

## 🌀 Exercise 01
### Description
The exercise is about iterating through a container to find a the shortest/longest span *(distance between numbers)*.
<br>
### Installation
1. Compile the program:
```bash 
$ make 
```
2. Run the program:
```bash 
$ ./ex01
```
<br>
<br>

## 🌀 Exercise 02
### Description
This exercise is about inherit form the stack container and iterating through it to use member functions *(like, pop(), size(), top())*.
<br>
### Installation
1. Compile the program:
```bash 
$ make 
```
2. Run the program:
```bash 
$ ./ex02
```