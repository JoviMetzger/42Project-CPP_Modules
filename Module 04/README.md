# Module 04

## 🌀 Exercise 00
### Description
In this exercise you need to implements basic polymorphism. You will make a Animal base class with Dog and Cat derived classes, for each class you need to implementing makeSound(). <br>
Introduces WrongCat inheriting from WrongAnimal to demonstrate overriding behaviors.
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
Focuses on memory management and deep copying. Involves a Brain class and both Dog and Cat classes have a private Brain* attribute.
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
Shifts focus to abstraction. Making it an **abstract class** (AAnimal).
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
<br>
<br>

## 🌀 Exercise 03
### Description
Implements interfaces using abstract classes. Make an abstract class (*AMateria)*, Ice and Cure as concrete classes inheriting from AMateria. <br>
Create *Character class* implementing the *ICharacter interface* and managing an inventory of
AMateria instances. <br>
Introduces MateriaSource class responsible for learning and creating Materia instances.
<br>
### Installation
1. Compile the program:
```bash 
$ make 
```
2. Run the program:
```bash 
$ ./ex03
```


//----------------------------------------------------------------------------------------



# CPP_Modules 🌊➕➕

## 	🌠 C++ Modules

<details>
  <summary><strong>Module 00:</strong> <br> &nbsp;&nbsp;&nbsp;<em>(<strong>Topics:</strong> Namespace, class, member functions, and some basic stuff...)</em></summary>
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
This exercise expands your knowledge by creating another derived class, `FragTrap`, which inherits from ClapTrap. <br>
**You'll learn or practice:**
1. Distinguishing the derived class from the base class with custom construction and destruction messages.
2. Ensuring proper class inheritance and conducting comprehensive testing.

<br>

### 🔸Exercise 03 - Now it’s weird!
In the final exercise, you'll create a hybrid class named `DiamondTrap` that inherits from both FragTrap and ScavTrap. <br>
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
  <summary>Module 01</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 02</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 03</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 04</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 05</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 06</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 07</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 08</summary>
  <br>
  <br>
  <br>

</br>

</details>

---

<details>
  <summary>Module 09</summary>
  <br>
  <br>
  <br>

</br>

</details>
<br>



######################################################################################

what does this mean ", the default Animal class should not be instantiable"?
ChatGPT
This phrase refers to a programming concept, specifically in object-oriented programming. The "default Animal class" likely refers to a generic or base class named "Animal" from which other specific animal classes might inherit.

When someone says that "the default Animal class should not be instantiable," it means that the base class representing animals should not be directly used to create objects. Instead, it might be designed as an abstract class or have certain methods that are meant to be overridden by its subclasses.

In languages like Java or C#, for instance, an abstract class can't be instantiated directly; it's meant to serve as a blueprint for other classes to inherit from and extend. This approach encourages developers to create specific instances of subclasses like "Dog," "Cat," or "Bird" rather than creating objects directly from the generic "Animal" class.


In the provided code, the line const AAnimal* meta = new AAnimal(); is attempting to instantiate an object of type AAnimal, which appears to be an abstract class with at least one pure virtual function (perhaps getBrain()). In C++, you cannot directly instantiate an object of an abstract class, especially if it contains pure virtual functions.

An abstract class is meant to be a blueprint for derived classes, and it often contains one or more pure virtual functions, which have no implementation in the base class but must be overridden by any concrete derived class. Attempting to create an instance of an abstract class directly results in a compilation error.

In the code provided, if AAnimal contains a pure virtual function like getBrain() or any other function without implementation marked as virtual and set to 0 (pure virtual function), attempting to create an object of AAnimal directly will indeed cause a compilation error.

The correct usage involves creating instances of concrete derived classes like Dog and Cat:

cpp
Copy code
const AAnimal* dog = new Dog();
const AAnimal* cat = new Cat();
This works because Dog and Cat are concrete classes that derive from AAnimal and provide implementations for all pure virtual functions inherited from AAnimal.

Regarding the deletion of dog and cat, since you're using new to allocate memory for these objects, remember to delete them properly after usage to avoid memory leaks:

cpp
Copy code
delete dog;
delete cat;
This ensures that the allocated memory for dog and cat is properly deallocated when they are no longer needed.

##############################################################################################

what is the difference between a clone and a deep copy?
ChatGPT
"Clone" and "deep copy" are terms often used in programming, especially when dealing with object-oriented languages. While both involve creating a copy of an object, there are nuances that differentiate them:

Clone:
Clone refers to creating an exact replica of an object, usually utilizing a method called clone() or a similar mechanism provided by the programming language.
In the context of object-oriented programming, a clone typically produces a new object with the same state as the original, but it might not necessarily create a new instance for every piece of data within the object.
The level of "sameness" can vary based on the implementation of the clone() method. Sometimes, it might copy references to objects within the original, resulting in two objects sharing some internal elements.
Deep Copy:
Deep copy involves creating a new object and recursively copying all the data from the original object, including any internal objects it might contain.
In a deep copy, each piece of data, including objects within objects, is copied to ensure that the new object is entirely independent of the original. This ensures that changes made to the copied object do not affect the original or vice versa.
Key Differences:
Depth of Copying: A clone might copy the top-level object and its references, while a deep copy ensures a complete duplication, including nested objects.
Independence: A clone might share references to internal objects, causing changes to reflect in both objects. A deep copy ensures complete independence between the original and the copy, preventing changes from affecting each other.
Level of Detail: Cloning might be less detailed, copying only what's required for a new instance, while a deep copy meticulously duplicates all data within the object hierarchy.
Application:
Cloning: Often used when an object needs to be copied quickly, retaining some relationships or references but not requiring a fully independent copy.
Deep Copying: Employed when a completely independent duplicate of an object is needed, ensuring modifications to one instance do not affect the other.
In summary, cloning tends to be less exhaustive and may retain some relationships or references, while a deep copy ensures a complete and independent duplication of an object and its internal structure.


########################################################################################################################

what is the difference between virtual and pure virtual? and what is a abstract class?
ChatGPT
In C++ (and other object-oriented languages), virtual and pure virtual functions are concepts related to polymorphism and class hierarchies. An abstract class is a class that contains at least one pure virtual function and cannot be instantiated directly, typically used as a base class for other derived classes.

Virtual Function:
Virtual functions are functions declared within a base class that can be redefined in derived classes.
When a function is declared as virtual in a base class and overridden in a derived class, the function to be executed is determined at runtime based on the actual object type (dynamic binding).
It allows for runtime polymorphism, enabling a derived class object to be treated as a base class object.
Pure Virtual Function:
A pure virtual function is a virtual function that is declared in a base class but has no implementation (no function body).
It is denoted by assigning it the value 0 in C++, like this: virtual void func() = 0;.
Classes containing pure virtual functions are known as abstract classes.
Abstract classes cannot be instantiated directly; they are meant to be inherited by derived classes, which must provide implementations for all pure virtual functions to become concrete classes.
Abstract Class:
An abstract class is a class that contains at least one pure virtual function.
It's designed to serve as a base class and provides an interface for derived classes to implement the pure virtual functions.
Objects of an abstract class cannot be created, but pointers and references to an abstract class can be used to refer to its derived classes.
Differences:
Virtual Function: Can have an implementation in the base class and can be overridden in derived classes. It is not mandatory for derived classes to provide an override.
Pure Virtual Function: Has no implementation in the base class and must be overridden by derived classes. It makes the class abstract and cannot be instantiated.
Use Cases:
Virtual Functions: Used when a default implementation is possible in the base class, and derived classes may or may not override it.
Pure Virtual Functions: Used when the base class provides only an interface, and derived classes must provide concrete implementations for these functions.
In summary, virtual functions enable polymorphic behavior and can have default implementations, while pure virtual functions make a class abstract and require derived classes to provide implementations, enforcing a specific interface. Abstract classes cannot be instantiated directly and are used as base classes for derived classes to implement required functionality.

#########################################################################################################################################



