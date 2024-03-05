<div align="center">
  <h1>
    📗 CPP
  </h1>
  <p>
    <b><i>An introduction to Object-Oriented Programming with C++.</i></b>
  </p>
  <p>
    Developed using&nbsp&nbsp
    <a href="https://skillicons.dev">
      <img src="https://skillicons.dev/icons?i=cpp" />
    </a>
  </p>
</div>

<br />

## Table Of Contents
- [Overview](#overview)
- [Concepts](#concepts)


## Overview
This repository serves as a personal roadmap through the fascinating world of C++, documenting my progress from the very basics to advanced concepts. Starting with fundamental syntax and basic data types, I delve into the core of C++ programming, exploring variables, operators, and control structures to lay a solid foundation. As my journey advances, I tackle more complex topics such as functions, arrays, pointers, and memory management, crucial for understanding the language's depth. The adventure doesn't stop there; I further immerse myself in object-oriented programming, mastering classes, inheritance, and polymorphism.


## Concepts
- [Classes, Member functions and other basics (Module00)](#classes-member-functions-and-other-basics-module00)
- [Memory allocation, pointers to members, references (Module01)](#memory-allocation-pointers-to-members-and-references-module01)

## Classes, Member functions and other basics (Module00)
### What is a class?
A class is a "blueprint" for creating objects. It defines a new data type. A class contains the following key aspects:
- **Data encapsulation:** A class can contain private, protected and public members. Private are only accessible from within other members of the same class. Protected members are accessible from the class itself and its derived classes. Public members are accessible from anywhere/anyone.
- **Member functions:** These are essentially functions defined inside a class. They can manipulate data members of the class or perform other actions. They are defined/declared inside the class.
- **Constructors/Deconstructors:** These are special members functions that get called when the object is created/destroyed respectively. They are used for initializing/cleaning up objects.
- **Inheritance:** This is a more advanced c++ topic that is basically creating a modified version of an existing class. The new class (derived class) inherits the members of the exisiting class (base class). The derived class can add new members/override existing ones.

### Example
Basic example of how a class would look like:
> NOTE: Due to [42](https://www.42network.org/) rules, we have to create the actual function in a `.cpp` file, but its also valid to write function definitions inside the class itself
```cpp
class MyClass {
    private: // declare anything that should not be accessed outside the class
        std::string myVar1;
        int         myVar2;
    public:
        MyClass(); // constructor
        ~MyClass(); // deconstructor
        void myFunction(); // Member function
};
```

## Memory allocation, pointers to members and references (Module01)
### Memory allocation
In C++ you allocate memory using the `new` keyword and free/cleanup using the `delete` keyword.
```cpp
#include <iostream>

int main() {
    // Dynamically allocate memory for a single integer
    int* ptr = new int;
    
    // Assign a value to the allocated memory
    *ptr = 10;
    std::cout << "Value of dynamically allocated integer: " << *ptr << std::endl;
    
    // Deallocate the memory
    delete ptr;
    return 0;
}
```

Allocating an array
```cpp
#include <iostream>

int main() {
    // Dynamically allocate memory for an array of 5 integers
    int* arr = new int[5];
    
    // Assign values to the array
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2; // Initialize elements with even numbers
    }
    
    // Print the values
    std::cout << "Values in dynamically allocated array: ";
    for(int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Deallocate the memory allocated for the array
    delete[] arr;
    return 0;
}

```

### Pointers vs Reference
- **Pointers:**
  - **What is it:** A pointer is a variable that holds the memory address of another variable. 
  - **Syntax:** `dataType* pointerName = &variable`
  - **Nullability:** Can be `NULL` (can also be `nullptr` in C++11).
  - **Reassignment:** Can be reassignedd to point to another object
  - **Usage:** Dynamic memeory allocation (new/delete), optional function parameters, more complex data structures (e.g. linked lists)

- **References:**
  - **What is it:** A reference acts as an "alias" for another variable. When you declare a reference to a variable, you are essentially creating a second name that refers to the original variable. Any operations performed on the reference affect the original variable directly because both the reference and the original variable refer to the same memory location.
  - **Syntax:** `dataType& refName = variable`
  - **Nullability:** Cannot be null.
  - **Reassignment:** Cannot be changed to refer to another variable after initialization.
  - **Usage:**
    - Passing objects to functions when you want to avoid copying the object but still want to modify the original object.
    - Returning multiple values from a function through references.
    - Implementing operator overloads in classes.

### When to use each one?
Use pointers when you need the same variable to point to multiple objects or no objects at all, manage memory dynamically or implement complex data types. \
You typically use references when you want a simpler, more readable syntax or when you need an alias for an exisiting variable. It is also more efficient to pass a reference to a function to avoid unnessary copying.

### Example
```cpp
#include <iostream>

int main() {
    int number = 10; // Original variable

    // Pointer to number
    int* ptr = &number;
    *ptr = 20; // Modifying number through the pointer
    std::cout << "After modification through pointer: " << number << std::endl;

    // Reference to number
    int& ref = number;
    ref = 30; // Modifying number through the reference
    std::cout << "After modification through reference: " << number << std::endl;

    return 0;
}

Output:
After modification through pointer: 20
After modification through reference: 30
```




### Polymorphism, abstract classes, interfaces (Module04)

