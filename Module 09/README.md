

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


# Module 09

## 🌀 Exercise 00
### Description
This program outputs the value of a certain amount of bitcoin on a certain date. <br>
**Container: map**
<br>
### Installation
1. Compile the program:
```bash 
$ make 
```
2. Run the program with input:
```bash 
$  ./btc input.txt
```
<br>
<br>

## 🌀 Exercise 01
### Description
This program calculates the Reverse Polish Notation.<br>
**Container: stack** <br>
<br>
### Installation
1. Compile the program:
```bash 
$ make 
```
2. Run the program:
```bash 
$  ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```
<br>
<br>

## 🌀 Exercise 02
### Description
This program sorts a positive integer sequence with the Ford-Johnson algorithm. <br>
**Container: vector & list** <br>
<br>
### Installation
1. Compile the program:
```bash 
$ make 
```
2. Run the program:
```bash 
$  ./PmergeMe 3 5 9 7 4
```
OR
```bash 
$  ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```




https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort

https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md

https://www.tldraw.com/v/y9Y2Et7vl18fkPZT4UoEKTW?viewport=-288,-2539,2560,2368&page=page:jEhR30akJPWN_ZhTL5KgI




Book what adri send ofer slack page 180 explains johnsansort (page on PDF 191)
