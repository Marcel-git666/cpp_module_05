#include "Bureaucrat.hpp"
#include <exception>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

int main(void) {
    std::cout << BLUE << "=== Bureaucrat Tests ===" << NC << std::endl
              << std::endl;

    std::cout << GREEN << "[TEST] Creating bureaucrat with valid grade (42)"
              << NC << std::endl;
    Bureaucrat b("John", 42);
    std::cout << b << std::endl;

    std::cout << RED << "[TEST] Creating bureaucrat with grade 0 (should fail)"
              << NC << std::endl;
    try {
        Bureaucrat c("Kate", 0);
        std::cout << YELLOW << "WARNING: Should have thrown exception!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << RED
              << "[TEST] Creating bureaucrat with grade 151 (should fail)" << NC
              << std::endl;
    try {
        Bureaucrat invalid("Bob", 151);
        std::cout << YELLOW << "WARNING: Should have thrown exception!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << RED
              << "[TEST] Decrementing bureaucrat at grade 150 (should fail)"
              << NC << std::endl;
    try {
        Bureaucrat d("Eve", 150);
        std::cout << "Before: " << d;
        d.decrementGrade();
        std::cout << YELLOW << "WARNING: Should have thrown exception!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << RED
              << "[TEST] Incrementing bureaucrat at grade 1 (should fail)" << NC
              << std::endl;
    try {
        Bureaucrat e("Alice", 1);
        std::cout << "Before: " << e;
        e.incrementGrade();
        std::cout << YELLOW << "WARNING: Should have thrown exception!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << GREEN << "[TEST] Normal increment and decrement operations"
              << NC << std::endl;
    Bureaucrat f("Tom", 75);
    std::cout << "Initial: " << f;
    f.incrementGrade();
    std::cout << "After increment: " << f;
    f.decrementGrade();
    std::cout << "After decrement: " << f;
    std::cout << std::endl;

    std::cout << BLUE << "=== All tests completed ===" << NC << std::endl;

    return 0;
}
