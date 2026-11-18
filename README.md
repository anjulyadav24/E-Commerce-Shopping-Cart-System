# E-Commerce Shopping Cart System

**Author:** Anjul Yadav  
**Language:** C  
**Project Type:** PPS / Beginner C Programming Project

## About
A menu-driven shopping cart application written in C. Users can view products, add products to their cart, view the bill, and checkout.

## Features
- Display product catalogue and available stock
- Add items to a shopping cart
- Validate quantity and stock availability
- Dynamically allocate cart memory using `realloc()`
- Display cart items and calculate total
- Apply discounts based on total purchase amount
- Checkout and reset cart

## Concepts Used
- Structures (`struct`)
- Functions
- Arrays
- Pointers
- Dynamic memory allocation (`realloc()` and `free()`)
- Conditional statements and loops
- Input/output using `stdio.h`

## Compile and Run
Using GCC:

```bash
gcc main.c -o shopping_cart
./shopping_cart
```

On Windows:

```bash
gcc main.c -o shopping_cart.exe
shopping_cart.exe
```

## Discount Rules
| Total Purchase | Discount |
|---|---:|
| ₹1,000 or more | 5% |
| ₹2,000 or more | 10% |
| ₹5,000 or more | 20% |

The highest qualifying discount is applied.

## Author
Anjul Yadav
