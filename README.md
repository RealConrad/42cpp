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
- [Exceptions (Module05)](#exceptions-module05)
- [Type casting (Module06)](#type-casting-module06)
- [Templates (Module07)](#templates-module07)
- [General concepts](#general-concepts)

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

class MyClass {
  private:
      int a;
      int b;
  public:
      MyClass(int r = 0, int i = 0) : a(r), b(i) {}
  
      // Overloading the + operator
      MyClass operator+(const MyClass& rhs) const {
          return MyClass(this->a + rhs.a, this->b + rhs.b);
      }
  
      void display() const {
          std::cout << a << " + " << b << std::endl;
      }
};

int main() {
    MyClass a(3, 2);
    MyClass b(1, 3);

    MyClass c = a + b; // Calls operator+() on `a` with `b` as argument
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
Simple example
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
class Car : public Vehicle { // Car inherits from Vehicle
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

More complex example showing polymorphism/data encapsulation:
```cpp
#include <iostream>
#include <string>

// Base class
class Vehicle {
  private:
      // Encapsulated member variable
      std::string licensePlate;
  
  public:
      // Constructor to initialize licensePlate
      Vehicle(const std::string& licensePlate) : licensePlate(licensePlate) {}
  
      // Virtual method to be overridden by derived classes
      virtual void start() const {
          std::cout << "Vehicle starts in a generic way." << std::endl;
      }
  
      // Virtual destructor for proper cleanup
      virtual ~Vehicle() {}
  
      // Public getter for licensePlate
      std::string getLicensePlate() const {
          return licensePlate;
      }
  
      // Public setter for licensePlate
      void setLicensePlate(const std::string& plate) {
          licensePlate = plate;
      }
};

// Derived class from Vehicle
class Car : public Vehicle {
  public:
      // Using Vehicle's constructor
      Car(const std::string& licensePlate) : Vehicle(licensePlate) {}
  
      // Override start function
      virtual void start() const {
          std::cout << "Car starts with a smooth sound." << std::endl;
      }
};

// Another derived class from Vehicle
class Truck : public Vehicle {
  public:
      // Using Vehicle's constructor
      Truck(const std::string& licensePlate) : Vehicle(licensePlate) {}
  
      // Override start function
      virtual void start() const {
          std::cout << "Truck starts with a loud rumble." << std::endl;
      }
};

int main() {
    Vehicle* myCar = new Car("ABC123");
    Vehicle* myTruck = new Truck("XYZ789");

    // Demonstrating polymorphism
    myCar->start(); // Calls Car's start()
    std::cout << "Car license plate: " << myCar->getLicensePlate() << std::endl;

    myTruck->start(); // Calls Truck's start()
    std::cout << "Truck license plate: " << myTruck->getLicensePlate() << std::endl;

    // Clean up
    delete myCar;
    delete myTruck;
    return 0;
}

// Expected OUTPUT:
// Car starts with a smooth sound.
// Car license plate: ABC123
// Truck starts with a loud rumble.
// Truck license plate: XYZ789
```

# Subtype polymorphism, abstract classes and interfaces (Module04)
### Subtype polymorphism
Subtype polymorphism, also known as runtime polymorphism or dynamic polymorphism. It allows a function to use objects of different types (subtypes) through a common "interface". Essentially, it lets you write more general and reusable code by interacting with the base class interface, while the actual operations performed can be specific to the derived class implementations. This is typically achieved through the use of virtual functions in C++.

### The Mechanism Behind Subtype Polymorphism
At the core of subtype polymorphism is the concept of a virtual function table (vtable), which is an implementation detail in C++ (and many other languages that support runtime polymorphism). 

- **Virtual Functions:** If you mark a class method as virtual, C++ sets up a special lookup table (kind of like a directory) for those methods. This is called a virtual function table, or vtable for short.

- **Object Layout:** Each object of a class that uses virtual functions gets a hidden pointer. This pointer points to its class's vtable. The vtable has information on how to find the actual functions the object should use.

- **Method Dispatch:** When you call a virtual method on a class object, C++ checks the object's vtable to find out which specific function to execute. This lets the program decide which function to run while it's running, based on the actual type of the object, even if you're using a pointer or reference to a more general base class.

To summarise: C++ uses this vtable system to make sure that when you call a function on an object. It runs the correct version of the function for that specific type of object, even in complex cases with inheritance.

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
      void makeSound() const {
          std::cout << "Bark!" << std::endl;
      }
};

class Cat : public Animal {
  public:
      void makeSound() const {
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

### Virtual Functions
Virtual functions are member functions that are declared in a base class and can be overridden in derived classes. They are needed to achieve runtime polymorphism. The virtual keyword is used to declare a function as virtual, override (introduced in C++11, but the concept is still the same in C++98) indicates that the function is intended to override a virtual function in a base class.

```cpp
class Base {
public:
    virtual void display() const { std::cout << "Base display" << std::endl; }
};

class Derived : public Base {
public:
    void display() const { std::cout << "Derived display" << std::endl; } // Overrides Base's display
};

int main() {
  Base* basePtr = new Derived();
  basePtr->display(); // Calls Derived::display
  delete basePtr;
}
OUTPUT:
Derived display
```

### Abstract classes
Abstract classes are classes that cannot be instantiated on their own. They are typically used as base classes in inheritance hierarchies. An abstract class is made abstract by declaring at least one of its functions as pure virtual (using = 0). Interfaces in C++ are a special case of abstract classes where all the methods are pure virtual.

```cpp
class IShape { // Interface/Abstract class
  public:
      virtual double area() const = 0; // make function purely virtual
      virtual ~IShape() {}
};

class Circle : public IShape { // Inherit from IShape
  private:
      double radius;
  public:
      Circle(double r) : radius(r) {}
      double area() const { return 3.14 * radius * radius; }
};
```

# Exceptions (Module05)
In C++, exceptions are used for handling errors in a flexible/consistent way. This involves three keywords: `try, catch, and throw`. A try block must be followed by one or more catch blocks.
If an exception is thrown and not caught within the same function, it propagates (is passed on) to the function that called it. If no suitable catch block is found there, the propagation continues up the call stack.
It's possible to catch all exceptions by using `catch (...) {}`, but it's generally better practice to catch specific exceptions so you can handle each one individually.

- **try:** A block of code that might throw an exception. It's a way of saying "I'm going to attempt this code, but it might fail."
- **catch:** This block is used to handle the exception. You can have multiple catch blocks to handle different types of exceptions. Each catch block is designed to catch a specific type of exception or a range of them.
- **throw:** Used to actually throw an exception when a problem is detected. You can throw any object as an exception, but it's common practice to use objects of classes that inherit from std::exception.


Example
```cpp
#include <iostream>
#include <stdexcept> // Include for std::runtime_error

int main() {
    try {
        std::cout << "Trying to divide by zero!" << std::endl;
        int denominator = 0;
        if (denominator == 0) {
            throw std::runtime_error("Division by zero!");
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
OUTPUT:
Caught an exception: Division by zero!
```

### Custom Exceptions
You can also define your own exception classes. These should inherit from `std::exception` and override the `what()` method to return a message.

Example
```cpp
#include <iostream>
#include <exception>

// Custom exception class
class MyException : public std::exception {
public:
    virtual const char* what() const throw() { // override what()
        return "Custom Exception occurred!";
    }
};

int main() {
    try {
        throw MyException();
    } catch (const MyException& e) { // catch cusom exception
        std::cout << "Caught MyException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // This catch block can catch all other std::exception-based exceptions
        std::cout << "Standard exception: " << e.what() << std::endl;
    }

    return 0;
}
OUTPUT:
Caught MyException: Custom Exception occurred!
```

# Type casting (Module06)
### Static Casting (static_cast):
It is the most commonly used casting type in C++. It performs implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion operators. The validaity of a `static_cast` is determined at compile time.

Example:
```cpp
int i = 10;
float f = static_cast<float>(i); // Converts i to float
```
**Safety and Polymorphism:** While `static_cast` can be used to convert between pointers or references to base and derived classes, it does not check the actual type of the object at runtime. Therefore, using `static_cast` to downcast (convert a base class pointer/reference to a derived class pointer/reference) is inherently **_UNSAFE_** without external guarantees about the object's type. It assumes that the programmer knows the type of the derived class and does not perform any runtime checks to verify this.

### Dynamic Casting (dynamic_cast):
Primarily used with pointers and references to classes (or class objects). It safely converts pointers/references of a base class into pointers/references of a derived class. It’s used in polymorphism to determine the correct type of the derived class object at runtime.

Example:
```cpp
class Base { virtual void print() {} };
class Derived : public Base {};

Base* basePtr = new Derived;
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Safe downcasting
```
**Safety and Polymorphism:** `dynamic_cast` is safe in the context of polymorphism. It checks the actual type of the object at runtime to ensure the requested cast is valid. If a `dynamic_cast` is used to downcast to a pointer type and the cast is invalid, it returns `nullptr/NULL`. If it is used to downcast to a reference type and the cast is invalid, it throws a `std::bad_cast exception`. This makes `dynamic_cast` good for scenarios where the exact type of an object is not known at compile time.

### Reinterpret Cast (reinterpret_cast):
Changes one pointer type to another, an integral type to a pointer type or vice versa. There is little to no safety to ensure the conversion, so it should be used with caution and avoided if possible and is prone to undefined behaviour when used inappropriately (e.g. dereferencing a pointer from converting an integer, due to Invalid memory access, pointing to deallocated memory etc.)

Exmaple:
```cpp
int* p = new int(10);
uintptr_t intPtr = reinterpret_cast<uintptr_t>(p); // Converts pointer to integer
```

### Const cast (const_cast):
Used mainly to add or remove the const qualifer from a variable.

Example:
```cpp
const int i = 10;
int* modifiable = const_cast<int*>(&i);
*modifiable = 5; // Modifies the value of i (although modifying a const is undefined behavior)
```

Example
```cpp
#include <iostream>

class Animal {
  public:
      virtual void makeSound() { std::cout << "Some animal sound" << std::endl; }
      virtual ~Animal() {}
};

class Dog : public Animal {
  public:
      virtual void makeSound() { std::cout << "Woof" << std::endl; }
      void fetch() { std::cout << "Fetching!" << std::endl; }
};

class Cat : public Animal {
  public:
      virtual void makeSound() { std::cout << "Meow" << std::endl; }
};

int main() {
    Animal* animalPtr = new Cat(); // Animal pointer actually points to a Cat
    animalPtr->makeSound(); // Polymorphism, will output: Meow

    // Using static_cast (no runtime check, assumes programmer knows the conversion is safe)
    Dog* dogPtr = static_cast<Dog*>(animalPtr); 
    // dogPtr->fetch(); // Undefined behavior because animalPtr actually points to a Cat

    // Using dynamic_cast (runtime type check)
    Dog* anotherDogPtr = dynamic_cast<Dog*>(animalPtr);
    if (anotherDogPtr) {
        anotherDogPtr->fetch(); // This block won't execute because animalPtr is not pointing to a Dog
    } else {
        std::cout << "The dynamic_cast failed because animalPtr is not a Dog." << std::endl;
    }

    delete animalPtr; // Clean up
    return 0;
}
```

# Templates (Module07)
Templates allow use to write generic and reusable code. They allow us to define classes, functions, and methods that work with any data type.

### How Templates Work
Templates work by allowing us to "parameterize" our code with one or more types. When you instantiate a template with a specific type, the compiler generates a new class/function from the template, replacing the template parameters with the actual type provided. This is called template instantiation.

Example:
```cpp
template <typename T>
T min(const T x, const T y) {
    return x < y ? x : y;
}

#include <iostream>
int main() {
  int a = min(1, -5);
  std::cout << a << std::endl;
  return 0;
}
OUTPUT:
-5
```
In the above example, behind the scenes, the compiler generates a specific version (an instantiation) on the `min()` function for the data type `int`, based on the template. The original template remains unchanged. It does not necessarily replace every instance of `T` with `int`, but rather creates a new function that looks as if it were specifically written for `int` types:
```cpp
int min(const int x, const int y) {
  return x < y ? x : y;
}
```

### Template Claasses
A template class defines a blueprint for a class where the data type of its members can be specified as template parameters. There are also `Template Functions` as shown in the above example. 

```cpp
template <typename T>
class Box {
  private:
      T content;
  public:
      Box(T content) : content(content) {}
      T getContent() const { return this->content; }
};

#include <iostream>
int main() {
	Box<int> intBox(123);
	Box<std::string> stringBox("Hello Templates");
	std::cout << intBox.getContent() << std::endl;
	std::cout << stringBox.getContent() << std::endl;
	return 0;
}

OUTPUT:
123
Hello Templates
```

### Template Specialization
Template specialization in C++ allows you to define a different implementation of a template for a specific type. This is particularly useful when a generic implementation does not suit a particular type or when a type requires special handling.


The reason to use template specialization is to optimize or customize behavior for specific types while maintaining the general template's flexibility for all other types

In the Example below: \
There's a generic `Box` template that works for any type `T`, storing a value and providing a method to access it. However, for the character type `char`, a specialized version of the `Box` class is provided. This specialization offers a different functionality, `specialDisplay()`, not available in the generic template.

Example:
```cpp
template <typename T>
class Box {
  private:
      T content;
  public:
      Box(T content) : content(content) {}
      T getContent() const { return this->content; }
};

template <>
class Box<char> {
	private:
    	char content;
public:
    Box(char content) : content(content) {}
    void specialDisplay() const {
        std::cout << "Special Box for char: " << this->content << std::endl;
    }
};

int main() {
	Box<int> a('b');
	Box<char> b('b');
	Box<double> c(69.12);

	std::cout << a.getContent() << std::endl;
	std::cout << c.getContent() << std::endl;
	b.specialDisplay(); // Works becuasse its of type char
	// a.specialDisplay(); // This will not work as the object `a` is `Box<int>` 

	return 0;
}

OUTPUT:
98
69.12
Special Box for char: b
```


# General Concepts
## Declaring functions as const
When you declare a member funciton as const, it means the funciton cannot modify any class member variables of the class (except mutable ones).

```cpp
class MyClass {
  public:
      int value = 0;
      mutable int mutableValue = 0;
  
      void setValue(int v) { value = v; }  // Non-const function, can modify the object.
      int getValue() const { return value; }  // Const function, cannot modify the object (except mutable members).
  
      void updateCache() const {
          // value = 5; // This would cause a compiler error, cannot modify 'value' in a const function.
          mutableValue = 5; // Allowed, because 'mutableValue' is mutable.
      }
};
```
