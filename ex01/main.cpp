#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

int main() {
    std::cout << BLUE << "=== Quick Bureaucrat Tests ===" << NC << std::endl;
    Bureaucrat b("Bob", 42);
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
    try {
        Bureaucrat c("Charlize", -3);
        std::cout << YELLOW << "WARNING: Should have thrown exception!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }

    std::cout << BLUE << "=== Form Creation Tests ===" << NC << std::endl;
    Form f1("F1", 41, 42);
    std::cout << f1 << std::endl;
    try {
        Form f2("F2", -10, 42);
        std::cout << YELLOW << "WARNING: Should have thrown exception!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }

    try {
        Form f3("F2", 10, 420);
        std::cout << YELLOW << "WARNING: Should have thrown exception!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }

    std::cout << BLUE << "=== Form Signing Tests ===" << NC << std::endl;
    b.signForm(f1);
    std::cout << f1 << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    b.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << RED << "[TEST] Signing with insufficient grade" << NC
              << std::endl;
    Bureaucrat lowGuy("LowGuy", 100);
    Form strictForm("StrictForm", 50, 50);
    lowGuy.signForm(strictForm);
    std::cout << strictForm << std::endl;

    std::cout << GREEN << "[TEST] Signing with sufficient grade" << NC
              << std::endl;
    Bureaucrat highGuy("HighGuy", 40);
    highGuy.signForm(strictForm);
    std::cout << strictForm << std::endl;

    std::cout << YELLOW << "[TEST] Signing already signed form" << NC
              << std::endl;
    highGuy.signForm(strictForm);

    std::cout << BLUE << "=== All tests completed ===" << NC << std::endl;

    return 0;
}
