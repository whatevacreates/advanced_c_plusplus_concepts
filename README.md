C++ Modules 42 – Advanced Exercises

A curated collection of C++ modules from the 42 Lausanne curriculum. Each directory (cppXX/exYY) contains a self‑contained exercise exploring language features, algorithmic thinking, and robust software design.

📖 About the Project

This repository aggregates the more challenging modules from the 42 C++ program. The goal is to cement understanding of object‑oriented design, memory management, templates, and algorithmic efficiency under the constraints of older C++ standards (C++98/03).

You’ll move from pointer basics to advanced container patterns, handling everything from string parsing to generic algorithms and even custom sorting routines. Each module follows the Orthodox Canonical Form and encourages good practices like exception safety, clean code, and self‑testing.

🧠 Module Overview
Module	Key Concepts	Sample Exercises
00	Basic I/O, classes, streams	Simple phone book CLI
01	Pointers, references, memory, simple classes	Weapon / Human classes; string replacement program
02	Fixed‑point arithmetic, canonical form, geometry	Fixed class, 2D Point class, point‑in‑triangle test
03	Inheritance, polymorphism, overloaded operators	Base ClapTrap and derived ScavTrap/FragTrap
04	Abstract classes, deep copy, dynamic memory	Animal, Dog, Cat with Brain member
05	Exception handling, nested classes	Bureaucrat and Form with grade validation
06	Type conversions, casts, reinterpretation	scalarConversion program for dynamic/static casts
07	Templates, iterators, generic arrays	Template Array<T> class and iter function
08	STL containers & algorithms	easyFind, Span, MutantStack
09	File parsing & algorithms	Bitcoin price lookup; RPN calculator; Ford–Johnson sorting
🔍 Requirements

Standard: C++98 (or specified per module)

Compile flags: -Wall -Wextra -Werror

No external libraries beyond the standard library

🚀 Getting Started
# clone the repository
git clone https://github.com/whatevacreates/cplusplus_modules42.git
cd cplusplus_modules42

# navigate to a module and exercise, then build
cd cpp01/ex03
make

# run the resulting program
./program_name


Each exercise lives in its own exXX directory with its own Makefile. Follow the instructions inside the assignment file to understand the expected behavior and constraints.

📊 Relative Complexity of Module 09 Tasks

💡 Tips

Read the assignment (assignment.txt or similar) in each exercise before coding.

Follow the Orthodox Canonical Form (canonical constructors, copy assignment, destructor).

Write your own tests and handle edge cases gracefully.

Avoid memory leaks by pairing every new with a delete or, better yet, using automatic storage and RAII.

For sorting or numeric tasks, think about algorithmic complexity (O(n), O(n log n)).
