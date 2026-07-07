*This project has been created as part of the 42 curriculum by smolines.*

# CPP Module 00

## Description

This repository contains the exercises of **Module 00** of the C++ curriculum at 42, the very first step into **Object-Oriented Programming**. Following the C++98 standard, this module introduces namespaces, classes, member functions, `stdio` streams, initialization lists, `static`, `const`, and a few other basic C++ building blocks — the foundations everything else in the C++ modules will build on.

### Exercise 00 — Megaphone

A short program that turns every argument it receives into uppercase and prints them, separated by spaces. If no argument is given, it prints a default message instead. A simple warm-up to get used to `std::string` and I/O streams in C++.

### Exercise 01 — My Awesome PhoneBook

An interactive command-line phonebook, built around two classes:
- **`Contact`** — represents a single phonebook entry (first name, last name, nickname, phone number, darkest secret).
- **`PhoneBook`** — holds a fixed-size array of up to 8 `Contact` instances, using no dynamic allocation. Adding a 9th contact overwrites the oldest one.

The program loops, waiting for one of three commands:
- `ADD` — prompts the user for each field of a new contact and stores it.
- `SEARCH` — displays all saved contacts in a formatted, right-aligned, 4-column table (index, first name, last name, nickname), then lets the user pick an entry by index to see its full details.
- `EXIT` — quits the program.

Any other input is ignored.

## Instructions

### Compilation

```bash
make
```

Run inside each exercise's directory (`ex00/`, `ex01/`). Each Makefile compiles the corresponding source files with `c++ -Wall -Wextra -Werror` (compatible with `-std=c++98`), and includes the required `$(NAME)`, `all`, `clean`, `fclean`, and `re` rules.

### Running

**Exercise 00:**

```bash
./megaphone "shhhhh... I think the students are asleep..."
```

```
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

With no arguments:

```bash
./megaphone
```

```
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Exercise 01:**

```bash
./phonebook
```

Then follow the prompts to `ADD`, `SEARCH`, or `EXIT`.

## Resources

- [cplusplus.com — `std::string` reference](http://www.cplusplus.com/reference/string/string/)
- [cplusplus.com — `<iomanip>` reference](http://www.cplusplus.com/reference/iomanip/)
- General documentation on Object-Oriented Programming concepts (classes, encapsulation, member functions) as applied to C++98

**AI usage:** AI assistance was used to help draft and structure this README file (organizing sections, describing each exercise's behavior and usage) based on the actual project source code and the official subject requirements. No AI-generated code was used in the implementation of the exercises themselves; all class design and logic were written and understood by the author.

## Project Structure

```
.
├── ex00/
│   ├── Makefile
│   └── src/
│       └── megaphone.cpp
└── ex01/
    ├── Makefile
    ├── includes/
    │   ├── Contact.hpp
    │   └── PhoneBook.hpp
    └── src/
        ├── Contact.cpp
        ├── PhoneBook.cpp
        └── main.cpp
```
