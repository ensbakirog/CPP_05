# C++ - Module 05: Repetition and Exceptions

This repository contains the implementation of **Module 05** from the École 42 C++ curriculum. The focus is on mastering **exceptions**, **abstract classes**, and **polymorphism** through a layered bureaucratic simulation.

---

## 📁 Structure

* **ex00** – `Bureaucrat`: grading system, validation, and exception handling
* **ex01** – `Form`: signing logic, grade checks, and integration with `Bureaucrat`
* **ex02** – `AForm` (abstract) + concrete forms:

  * `ShrubberyCreationForm`
  * `RobotomyRequestForm`
  * `PresidentialPardonForm`
* **ex03** – `Intern`: dynamic form creation using `makeForm()`

---

## ⚙️ Build

Each exercise folder includes a `Makefile`. To build and run:

```bash
cd ex00/
make
./program
```

Compilation flags used:

```bash
-Wall -Wextra -Werror -std=c++98
```

---

## 🚫 Rules

* No use of STL containers or algorithms before Module 08
* Forbidden: `printf`, `malloc`, `free`, `using namespace`, `friend`
* Classes must follow the **Orthodox Canonical Form**
* Memory leaks will lead to failure

---

## ✅ Testing

Test all features, including:

* Exception handling
* Signing and executing forms
* Dynamic form creation by `Intern`
  Use clear and meaningful output as shown in module instructions.
