#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "=== Bureaucrat Creation ===" << std::endl;
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);
        std::cout << high << std::endl;
        std::cout << low << std::endl;

        std::cout << "\n=== Invalid Bureaucrat Creation ===" << std::endl;
        Bureaucrat invalid("Invalid", 0);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Form Creation ===" << std::endl;
        Form f1("Form1", 50, 100);
        std::cout << f1 << std::endl;

        std::cout << "\n=== Invalid Form Creation ===" << std::endl;
        Form f2("Form2", 0, 10);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Signing Forms ===" << std::endl;
        Bureaucrat alice("Alice", 10);
        Bureaucrat bob("Bob", 140);
        Form formA("FormA", 20, 100);
        Form formB("FormB", 130, 100);

        std::cout << formA << std::endl;
        alice.signForm(formA);
        std::cout << formA << std::endl;

        std::cout << formB << std::endl;
        bob.signForm(formB);
        std::cout << formB << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Increment/Decrement Tests ===" << std::endl;
        Bureaucrat top("Top", 1);
        top.increment();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrement();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}