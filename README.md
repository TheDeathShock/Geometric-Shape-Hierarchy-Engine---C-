# Geometric Shape Hierarchy Engine — C++

Object-oriented C++ project that models a hierarchy of geometric shapes using inheritance, polymorphism, constructors, copy constructors, dynamic memory management, and coordinate-based calculations.

## Description

This project implements a geometric shape system with classes for points, polygons, quadrilaterals, parallelograms, rectangles, rhombuses, squares, and trapezoids. Each shape class validates its geometric properties and provides shape-specific functionality where needed.

The project also includes a test driver to verify area calculations, side lengths, angle calculations, and shape behavior.

## Files

Driver.cpp
Point.cpp / Point.h
Polygon.cpp / Polygon.h
Quadrilateral.cpp / Quadrilateral.h
Parallelogram.cpp / Parallelogram.h
Rectangle.cpp / Rectangle.h
Rhombus.cpp / Rhombus.h
Square.cpp / Square.h
Trapezoid.cpp / Trapezoid.h
testDriver.cpp / testDriver.h

## Features

- Object-oriented shape hierarchy
- Inheritance-based class design
- Dynamic memory management for polygon points
- Custom constructors and copy constructors
- Area calculation using coordinate-based geometry
- Shape validation logic
- Parallelogram, rectangle, rhombus, square, and trapezoid-specific behavior
- Test driver for validating program functionality

## Build Instructions

Compile with:

g++ -std=c++17 Driver.cpp Point.cpp Polygon.cpp Quadrilateral.cpp Parallelogram.cpp Rectangle.cpp Rhombus.cpp Square.cpp Trapezoid.cpp testDriver.cpp -o program

## Run Instructions

On Linux/macOS:

./program

On Windows:

program.exe

## Main Concepts Used

- C++
- Object-Oriented Programming
- Inheritance
- Polymorphism
- Dynamic Memory Management
- Copy Constructors
- Geometry Calculations
- Testing and Debugging
