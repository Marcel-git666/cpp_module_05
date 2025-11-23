#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <iostream>

#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define NC "\033[0m"

int main() {
    srand(time(NULL));

    std::cout << BLUE << "=== Intern Tests ===" << NC << std::endl << std::endl;

    Intern intern;
    std::cout << intern << std::endl;

    // Test 1: Shrubbery
    std::cout << GREEN << "[TEST] Creating shrubbery form via Intern" << NC
              << std::endl;
    AForm *shrub = intern.makeForm("shrubbery creation", "home");
    if (shrub) {
        std::cout << *shrub << std::endl;
        Bureaucrat bob("Bob", 1);
        bob.signForm(*shrub);
        bob.executeForm(*shrub);
        delete shrub;
    }
    std::cout << std::endl;

    // Test 2: Robotomy
    std::cout << GREEN << "[TEST] Creating robotomy form via Intern" << NC
              << std::endl;
    AForm *robot = intern.makeForm("robotomy request", "Bender");
    if (robot) {
        std::cout << *robot << std::endl;
        Bureaucrat alice("Alice", 1);
        alice.signForm(*robot);
        alice.executeForm(*robot);
        delete robot;
    }
    std::cout << std::endl;

    // Test 3: Presidential
    std::cout << GREEN << "[TEST] Creating presidential form via Intern" << NC
              << std::endl;
    AForm *pardon = intern.makeForm("presidential pardon", "Arthur");
    if (pardon) {
        std::cout << *pardon << std::endl;
        Bureaucrat zaphod("Zaphod", 1);
        zaphod.signForm(*pardon);
        zaphod.executeForm(*pardon);
        delete pardon;
    }
    std::cout << std::endl;

    // Test 4: Unknown form
    std::cout << RED << "[TEST] Creating unknown form" << NC << std::endl;
    AForm *unknown = intern.makeForm("unknown form", "target");
    if (!unknown) {
        std::cout << "Form was not created (as expected)" << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== All tests completed ===" << NC << std::endl;

    return 0;
}
