# Module 03

## 🌀 Exercise 00
### Description
In this exercise you need to create a class `ClapTrap` with private attributes, each with specific default values. And you are required to implement public member functions.
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
This exercise instructed to create a derived class `ScavTrap`, inheriting constructors and destructor from ClapTrap. <br>
The ScavTrap class has different attributes and a unique member function called **guardGate()**.
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
This exercise focuses on creating another derived class `FragTrap`, which also inherits from ClapTrap. <br>
FragTrap has its unique member function **highFivesGuys()**.
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
In this exercise,creates a class `DiamondTrap`, which inherits from both **FragTrap** and **ScavTrap**, making it a hybrid robot. <br>
DiamondTrap has a name private attribute and inherits attributes and member functions from its parent classes. It also has a unique member function called **whoAmI()**.
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
In this exercise you will convert float to int and vice versa.<br>
**You'll learn or practice:**
1. You expand the functionality of your Fixed class to handle various constructors and conversions.
2. You'll deal with operator overloading, including overloading the insertion *(<<)* operator for output stream.
3. You will learn how to convert between fixed-point numbers and floating-point numbers or integers.

<br>

### 🔸Exercise 02 - Now we’re talking
This exercise builds on the Fixed class by overloading comparison operators and arithmetic operators. <br>
**You'll learn or practice:**
1. You'll implement *pre-increment (++i)*, *post-increment (i++)*, *pre-decrement (--i)*, and *post-decrement (i--)* operators.
2. You need to create static member functions and use them for finding the minimum and maximum values among fixed-point numbers.

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


The two code snippets you provided are C++ operator overloading implementations for the assignment operator (operator=) in the context of a class called ScavTrap. The difference between them lies in how they perform the assignment operation and what they do in the assignment operator.

The first snippet:
cpp
Copy code
ScavTrap& ScavTrap::operator=(const ScavTrap& value)
{
    // Perform a deep copy
    _name = value._name;
    _hitPoints = value._hitPoints;
    _energyPoints = value._energyPoints;
    _damage = value._damage;
    return *this;
}
In this implementation, you are manually copying each member variable from the source object value to the target object (the instance on which the assignment operator is called). This approach is performing a deep copy, meaning that it creates new copies of all the data members of the source object to ensure that the two objects are entirely independent of each other.

The second snippet:
cpp
Copy code
ScavTrap& ScavTrap::operator=(const ScavTrap& value)
{
    ClapTrap::operator=(value);
    return *this;
}
In this implementation, the assignment operator is delegating the assignment operation to a base class, ClapTrap, by calling its assignment operator. This is often seen when the derived class ScavTrap inherits from a base class ClapTrap. By calling the base class's assignment operator, you are essentially reusing the assignment logic defined in the base class. The ClapTrap::operator= method should handle copying all the base class's members.

The key difference here is in the level of manual copying and how the assignment operator handles member variables. The first approach manually copies each member, making it a deep copy, whereas the second approach relies on the base class's assignment operator to handle the assignment, which can simplify the code and ensure consistency if the base class's assignment logic is correct.
####################################################################################################################

In C++, a virtual base class is a base class that is declared as "virtual" in a class hierarchy. When a class is marked as a virtual base class, it is used to ensure that there is only one instance of the base class shared among multiple derived classes. This helps to avoid ambiguity and diamond inheritance problems in multiple inheritance scenarios, like the one you are encountering with DiamondTrap.

In the context of your code, the error messages are pointing out issues related to diamond inheritance. You have a class hierarchy like this:

markdown
Copy code
      ClapTrap
     /        \
FragTrap    ScavTrap
     \        /
   DiamondTrap
Both FragTrap and ScavTrap inherit from ClapTrap, creating a diamond-shaped hierarchy. In this case, ClapTrap is a common base class for both FragTrap and ScavTrap. The issue is that when you construct DiamondTrap, it inherits ClapTrap from both FragTrap and ScavTrap, which can lead to ambiguity and problems when accessing members from ClapTrap.

To resolve this issue, you should use virtual inheritance for the ClapTrap base class in the FragTrap and ScavTrap classes. Here's how you can modify the code:

cpp
Copy code
class ClapTrap {
    // ... (no changes)
};

class FragTrap : virtual public ClapTrap { // Use virtual inheritance
    // ... (no changes)
};

class ScavTrap : virtual public ClapTrap { // Use virtual inheritance
    // ... (no changes)
};

class DiamondTrap : public FragTrap, public ScavTrap {
public:
    DiamondTrap(const std::string& name)
        : ClapTrap(name), FragTrap(name), ScavTrap(name) {
        std::cout << "DiamondTrap " << _name << " has been created!" << std::endl;
    }

    // ... (no changes in the rest of the code)
};
By using virtual inheritance for ClapTrap in both FragTrap and ScavTrap, you ensure that there is only one instance of ClapTrap shared among both derived classes and DiamondTrap. This resolves the ambiguity and diamond inheritance issues in your code.

######################################################################################################################

The -Wshadow and -Wno-shadow compiler flags are used to control warnings related to variable shadowing in C and C++ code. Variable shadowing occurs when a variable declared in an inner scope (such as a function or block) has the same name as a variable declared in an outer scope (such as a global variable or a variable in an enclosing function). When shadowing occurs, the inner variable can "hide" the outer variable within its scope, potentially leading to unexpected behavior.

Here's what these flags do and why you might want to use them:

-Wshadow (Enable Variable Shadowing Warnings):

When you use -Wshadow, the compiler will generate warnings whenever it detects variable shadowing in your code. These warnings serve as a helpful tool for identifying potential issues and making you aware of situations where you might be unintentionally modifying or using the wrong variable due to shadowing.
Example of shadowing warning:

c
Copy code
int x = 5;

void foo() {
    int x = 10; // Warning: variable 'x' shadows an outer variable
    // ...
}
Enabling this flag is a good practice as it helps you catch and fix potential bugs caused by shadowed variables.

-Wno-shadow (Disable Variable Shadowing Warnings):

On the other hand, using -Wno-shadow disables the variable shadowing warnings generated by the compiler. You might use this flag when you intentionally want to use variable shadowing, and you don't want to be bothered by the warnings.
Example of disabling shadowing warnings:

c
Copy code
int x = 5;

void foo() {
    int x = 10; // No warning with -Wno-shadow
    // ...
}
However, you should use this flag with caution and only in situations where you are confident that variable shadowing is intended and will not lead to confusion or bugs.

In general, it's a good practice to use -Wshadow to catch unintentional variable shadowing, as it can help prevent bugs and make your code more maintainable. If you are intentionally using shadowing for some reason, you can selectively disable warnings in specific parts of your code using -Wno-shadow.


########################################################################################################################

The key difference lies in what each set of assignments is doing:

_hitPoints = FragTrap::_hitPoints;

This assignment is copying the value of _hitPoints from the FragTrap class to the _hitPoints member of the current class (presumably DiamondTrap in your case).
FragTrap::_hitPoints = 100;

This assignment is directly setting the value of the static member _hitPoints in the FragTrap class to 100. Note that this is a static member, meaning it is shared among all instances of the class.
In the context of your DiamondTrap class, if _hitPoints is a non-static member, the first set of assignments (_hitPoints = FragTrap::_hitPoints;) would be more appropriate, as it copies the value of _hitPoints from the FragTrap class to the _hitPoints member of DiamondTrap. If _hitPoints is a static member, then the second set of assignments (FragTrap::_hitPoints = 100;) would be the correct way to initialize it.

#########################################################################################################################



https://www.geeksforgeeks.org/multiple-inheritance-in-c/


######################################################################################
