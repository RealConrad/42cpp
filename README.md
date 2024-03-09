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


# Concepts
- [Classes, Member functions and other basics (Module00)](#classes-member-functions-and-other-basics-module00)
- [Memory allocation, pointers to members, references (Module01)](#memory-allocation-pointers-to-members-and-references-module01)
- [Operator overloading and Orthodox Canonical class form (Module02)](#operator-overloading-and-orthodox-canonical-class-form-module02)
- [Inheritance (Module03)](#inheritance-module03)
- [Subtype polymorphism, abstract classes and interfaces (Module04)](#subtype-polymorphism-abstract-classes-and-interfaces-module04)

# Classes, Member functions and other basics (Module00)
### What is a class?
A class is a "blueprint" for creating objects. A class contains the following key aspects:
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



# Memory allocation, pointers to members and references (Module01)
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
    
    // Free memory
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
    
    // Free memory
    delete[] arr;
    return 0;
}

```

### Pointers vs Reference
**Pointers:**
  - **What is it:** A pointer is a variable that holds the memory address of another variable. 
  - **Syntax:** `dataType* pointerName = &variable`
  - **Nullability:** Can be `NULL` (can also be `nullptr` in C++11).
  - **Reassignment:** Can be reassignedd to point to another object
  - **Usage:** Dynamic memeory allocation (new/delete), optional function parameters, more complex data structures (e.g. linked lists)

**References:**
  - **What is it:** A reference acts as an "alias" for another variable. When you declare a reference to a variable, you are essentially creating a another variable that refers to the original variable. Any operations performed on the reference affect the original variable directly because both the reference and the original variable refer to the same memory location.
  - **Syntax:** `dataType& refName = variable`
  - **Nullability:** Cannot be `NULL`.
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



# Operator overloading and Orthodox Canonical class form (Module02)
### Operator overloading
Allows developers to redefine the way operators (e.g. `+, -, \, *, =, == etc..` work with classes. This works by defining a special member function which will be called when the operator is used on objects of that class. When overloading an operator like `+`, you essentially write a member function that specifies what should happen when an object of your class is added to another object.

How the define would look like for the `+` operator: \
`MyClassName operator+(const MyClassName& rhs) const;`


How the example below works:
1. The object on the left-hand side of the + operator (in this case, `a`) is implicitly represented by the `this pointer` inside the member function.
2. The object on the right-hand side of the + operator (in this case, `b`) is passed explicitly to the function as the parameter `rhs`.
3. The member function defines how to combine this object (the left-hand side) with the rhs object (the right-hand side) and returns a new object of the same type representing the result.

Example:
```cpp
#include <iostream>

class Complex {
  private:
      int a;
      int b;
  public:
      Complex(int r = 0, int i = 0) : a(r), b(i) {}
  
      // Overloading the + operator
      Complex operator+(const Complex& rhs) const {
          return Complex(a + rhs.a, b + rhs.b);
      }
  
      void display() const {
          std::cout << a << " + " << b << std::endl;
      }
};

int main() {
    Complex a(3, 2);
    Complex b(1, 3);

    Complex c = a + b; // Calls operator + on a with b as argument
    c.display();
    return 0;
}

OUTPUT:
4 + 5
```

### Orthodox Canonical Form
This is a C++ convention that states all classes should have atleast 4 special member functions (Constructor, copy constructor, copy assignment operator, and deconstructor).

- **Default Constructor** Initializes objects, often setting member variables to default values.
- **Copy Constructor:** Creates a new object as a copy of an existing object. It deep copies objects, preventing issues like double free, that other wise would be an issue with shallow copies
- **Copy Assignment Operator:** Allows one object to be assigned to another, replacing its current state. It is pretty similar to the copy constructor. The copy assignment operator must ensure that resources are copied safely, avoiding resource leaks and ensuring that each object maintains its own copy of the resources.
- **Destructor:** Cleans up resources that the object may have acquired during its lifetime. This function is called when the program ends or the object is explicitly deleted. It's essential for releasing resources like dynamic memory to prevent memory leaks.

### Example
```cpp
#include <iostream>

class SimpleResource {
  private:
      double* value;
  
  public:
      // Default Constructor
      SimpleResource() : value(new double(0.0)) {
          std::cout << "Default Constructor: Resource allocated." << std::endl;
      }
  
      // Parameterized Constructor for convenience
      SimpleResource(double val) : value(new double(val)) {
          std::cout << "Parameterized Constructor: Resource allocated with value " << *value << std::endl;
      }
  
      // Copy Constructor
      SimpleResource(const SimpleResource& src) : value(new double(*(src.value))) {
          std::cout << "Copy Constructor: Resource copied with value " << *value << std::endl;
      }
  
      // Copy Assignment Operator
      SimpleResource& operator=(const SimpleResource& src) {
          if (this != &src) {
              // Deallocate existing resource
              delete value;
              // Allocate new resource and copy
              value = new double(*(src.value));
              std::cout << "Copy Assignment Operator: Resource reallocated with value " << *value << std::endl;
          }
          return *this;
      }
  
      // Destructor
      ~SimpleResource() {
          delete value;
          std::cout << "Destructor: Resource deallocated." << std::endl;
      }
  
      // Utility function to display the value
      void display() const {
          std::cout << "Value: " << *value << std::endl;
      }
};

int main() {
    SimpleResource res1(10.5);   // Using the parameterized constructor
    SimpleResource res2 = res1;  // Copy constructor
    SimpleResource res3;         // Default constructor
    res3 = res2;                 // Copy assignment operator

    res1.display();
    res2.display();
    res3.display();
    return 0;
}

OUTPUT:
Parameterized Constructor: Resource allocated with value 10.5
Copy Constructor: Resource copied with value 10.5
Default Constructor: Resource allocated.
Copy Assignment Operator: Resource reallocated with value 10.5
Value: 10.5
Value: 10.5
Value: 10.5
Destructor: Resource deallocated.
Destructor: Resource deallocated.
Destructor: Resource deallocated.
```

# Inheritance (Module03)
Inheritance is a core concept in object-oriented programming that allows a class to inherit class properties (methods/attributes) from another class. The class whose properties are inherited is usually called the `Base class` and the class that inherits those properties is ususally called the `derived class`

Some key aspects/benefits of inheritance:
- **Reuseability:**: Derived classes reuse the code from their base classes without having to rewrite it. This is easier to maintain/less duplication.
- **Polymorphism:** A derived class can override functions of its base class.
- **Encapsulation:** Supports the encapsulation principle by allowing derived classes to access/modify data/behaviour of their base class while keeping certain attributes private/protected from outside access.

The types of inheritance:
- **Single inheritance:** A derived class inherits from one base class.
- **Multiple inheritance:** A derived class inherits from multiple base classes.
- **Multilevel inheritance:** A class is derived from a class which is also derived from another class.
- **Hierarchical Inheritance:** Multiple classes are derived from a single base class.
- **Hybrid Inheritance:** A combination of two or more types of inheritance.

### Example
In this simple example
```cpp
#include <iostream>

// Base class
class Vehicle {
public:
    void start() {
        std::cout << "Vehicle started." << std::endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    void displayType() {
        std::cout << "I am a Car." << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.start(); // Calling method from base class
    myCar.displayType(); // Calling method from derived class
    return 0;
}

OUTPUT:
Vehicle started.
I am a Car.
```

More complex example showing polymorphism:
```cpp
#include <iostream>

// Base class
class Vehicle {
public:
    // make method viritual to override it in derived classes
    virtual void start() const {
        std::cout << "Vehicle starts in a generic way." << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Vehicle() {}
};

// Derived class from Vehicle
class Car : public Vehicle {
public:
    // Override start function
    void start() const {
        std::cout << "Car starts with a smooth sound." << std::endl;
    }
};

// Another derived class from Vehicle
class Truck : public Vehicle {
public:
    // Override start function
    void start() const {
        std::cout << "Truck starts with a loud rumble." << std::endl;
    }
};

int main() {
    Vehicle* myCar = new Car();
    Vehicle* myTruck = new Truck();

    // Demonstrating polymorphism
    myCar->start(); // Calls Car's start()
    myTruck->start(); // Calls Truck's start()

    // Clean up
    delete myCar;
    delete myTruck;
    return 0;
}

OUTPUT:
Car starts with a smooth sound.
Truck starts with a loud rumble.
```

# Subtype polymorphism, abstract classes and interfaces (Module04)
### Subtype polymorphism
Subtype polymorphism, also known as runtime polymorphism or dynamic polymorphism. It allows a function to use objects of different types (subtypes) through a common "interface". Essentially, it lets you write more general and reusable code by interacting with the base class interface, while the actual operations performed can be specific to the derived class implementations. This is typically achieved through the use of virtual functions in C++.

### The Mechanism Behind Subtype Polymorphism
At the core of subtype polymorphism is the concept of a virtual function table (vtable), which is an implementation detail in C++ (and many other languages that support runtime polymorphism). 

- **Virtual Functions:** When you declare a method as virtual in a base class, C++ creates a vtable. This table maps virtual functions to their concrete implementations. Each class that overrides a virtual method or has virtual methods has its own version of this table.

- **Object Layout:** Each object of a class that has virtual methods (or inherits from a class with virtual methods) contains a hidden pointer (often called a vptr) that points to the vtable for its class. This vtable contains the addresses of the class's virtual functions as they should be called for that specific instance.

- **Method Dispatch:** When you call a virtual method on an object through a pointer or reference to a base class, the actual function that gets called is determined at runtime using the vtable of the object's actual class (i.e., the class of the instance).

Consider the the below example:
- The `Animal` class defines a virtual method `makeSound`.
- Both `Dog` and `Cat` classes override this method.
- When `makeSound` is called on `myPet`, which is an `Animal*`, the actual method that gets executed is determined by the type of object `myPet` points to at runtime.
- Despite `myPet` being a pointer to `Animal`, it can point to an object of any class derived from `Animal`, and the correct `makeSound` method (from `Dog` or `Cat`) is invoked. This is subtype polymorphism in action.

```cpp
class Animal {
  public:
      virtual void makeSound() const {
          std::cout << "Some generic animal sound" << std::endl;
      }
      virtual ~Animal() {} // Virtual destructor for safe polymorphic deletion
};

class Dog : public Animal {
  public:
      void makeSound() const override {
          std::cout << "Bark!" << std::endl;
      }
};

class Cat : public Animal {
  public:
      void makeSound() const override {
          std::cout << "Meow!" << std::endl;
      }
};

int main() {
  Animal* myPet = new Dog();
  myPet->makeSound(); // Outputs: Bark!
  
  delete myPet; // Clean up
  
  myPet = new Cat();
  myPet->makeSound(); // Outputs: Meow!
  
  delete myPet; // Clean up
}

OUTPUT:
Bark!
Meow!
```



