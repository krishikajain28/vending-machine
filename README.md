# Vending Machine C++ Project

This C++ program simulates a drink vending machine scenario. The user starts with a 5€ bill and can buy drinks for themselves and two friends. The vending machine offers Water, Cola, and Iced Tea, each with specific types or flavors.

The program demonstrates Object-Oriented Programming concepts such as inheritance, polymorphism, and virtual destructors while providing a creative and interactive menu-driven experience.

## Features

- Menu-driven program
- Buy drinks for yourself and two friends
- Drinks available:
  - **Water**: Still / Sparkling
  - **Coca Cola**: Regular / Sugar-Free
  - **Iced Tea**: Peach / Lemon
- Displays total amount spent and remaining change
- Demonstrates **polymorphism** with a `Drink` base class and child classes
- Uses dynamic memory allocation with proper cleanup using destructors

---

## Program Flow

1. **Main Menu**

   - Show drink list
   - Place orders
   - Show total & change
   - Exit program

2. **Place Orders**

   - Friends order first, then the user
   - Drink selection includes category and type
   - Program checks if enough budget is left before allowing purchase

3. **Billing**
   - Total spent and remaining balance displayed
   - Proper memory cleanup for dynamically allocated objects

---

## Code Structure

- `Drink` (Base class)
  - Properties: `name`, `price`
  - Virtual function: `prepare()`
  - Virtual destructor for proper cleanup
- Child classes: `Water`, `CocaCola`, `IcedTea`
  - Each overrides `prepare()` with specific messages
- `VendingMachine` class
  - Shows menu, handles orders, calculates total & change
  - Uses **polymorphism** to handle different drink types

---

## Sample output:

```bash
========= Welcome to the Drink Vending Machine =========

Main menu:
1.Show drink list
2.Place Orders
3.Show total & change
4.Exit program
What would you like to choose? (1,2,3,4): 1

======== The Drinks List =========
1. Water (Still)             $1.00
1. Water (Sparkling)         $1.25
2. Coca Cola (Regular)       $1.80
2. Coca Cola (Sugar-Free)    $1.90
3. Iced Tea (Peach)          $2.20
3. Iced Tea (Lemon)          $2.20
```

## How to Run

Compile the program using any C++ compiler:

```bash
g++ index.cpp -o index.exe
./index.exe
```

## Notes

Creative enhancements:

Sparkling Water priced slightly higher for realism
Fun personalized prompts for friends’ orders
Code is fully documented and uses proper OOP concepts

## Requirements:

C++11 or later
Standard C++ compiler (g++, clang++)

## Author

Krishika Jain
B.Sc. Computer Science, KC College, Mumbai
