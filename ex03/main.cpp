#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <exception>
#include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

int main() {
    srand(time(NULL)); // Inicializace random pro robotomy

    std::cout << BLUE << "=== ShrubberyCreationForm Tests ===" << NC
              << std::endl
              << std::endl;

    // Test 1: Shrubbery - vytvoření a zobrazení
    std::cout << GREEN << "[TEST] Creating ShrubberyCreationForm" << NC
              << std::endl;
    ShrubberyCreationForm shrubForm("garden");
    std::cout << shrubForm << std::endl << std::endl;

    // Test 2: Shrubbery - pokus o podpis s příliš nízkým grade
    std::cout << RED
              << "[TEST] Trying to sign with low grade bureaucrat (grade 150)"
              << NC << std::endl;
    try {
        Bureaucrat lowGuy("LowGuy", 150);
        std::cout << lowGuy;
        lowGuy.signForm(shrubForm);
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Shrubbery - úspěšný podpis
    std::cout << GREEN
              << "[TEST] Signing with sufficient grade bureaucrat (grade 140)"
              << NC << std::endl;
    Bureaucrat midGuy("MidGuy", 140);
    std::cout << midGuy;
    midGuy.signForm(shrubForm);
    std::cout << shrubForm << std::endl << std::endl;

    // Test 4: Shrubbery - pokus o exekuci nepodepsaného
    std::cout << RED << "[TEST] Trying to execute unsigned form" << NC
              << std::endl;
    try {
        ShrubberyCreationForm unsignedForm("unsigned_test");
        Bureaucrat executor("Executor", 6);
        unsignedForm.execute(executor);
        std::cout << YELLOW
                  << "WARNING: Should have thrown FormNotSignedException!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Shrubbery - pokus o exekuci s příliš nízkým grade
    std::cout << RED
              << "[TEST] Trying to execute with low grade executor (grade 150)"
              << NC << std::endl;
    try {
        Bureaucrat lowExecutor("LowExecutor", 150);
        std::cout << lowExecutor;
        shrubForm.execute(lowExecutor);
        std::cout << YELLOW
                  << "WARNING: Should have thrown GradeTooLowException!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Shrubbery - úspěšná exekuce
    std::cout << GREEN << "[TEST] Executing with sufficient grade (grade 130)"
              << NC << std::endl;
    try {
        Bureaucrat goodExecutor("GoodExecutor", 130);
        std::cout << goodExecutor;
        shrubForm.execute(goodExecutor);
        std::cout << GREEN << "✓ Form executed successfully!" << NC
                  << std::endl;
        std::cout << BLUE << "→ Check the file: garden_shrubbery" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "✗ Unexpected exception: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // ========== ROBOTOMY TESTS ==========
    std::cout << BLUE << "=== RobotomyRequestForm Tests ===" << NC << std::endl
              << std::endl;

    std::cout << GREEN << "[TEST] Creating RobotomyRequestForm" << NC
              << std::endl;
    RobotomyRequestForm robForm("Bender");
    std::cout << robForm << std::endl << std::endl;

    // Test: Robotomy - podpis a exekuce
    std::cout << GREEN << "[TEST] Signing and executing robotomy form (5x)"
              << NC << std::endl;
    try {
        Bureaucrat engineer("Engineer", 40);
        std::cout << engineer;
        engineer.signForm(robForm);
        std::cout << YELLOW << "--- Executing 5 times to see randomness ---"
                  << NC << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "Attempt " << (i + 1) << ": ";
            robForm.execute(engineer);
        }
        std::cout << NC;
    } catch (std::exception &e) {
        std::cout << RED << "✗ Unexpected exception: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // Test: Robotomy - příliš nízký grade pro exekuci
    std::cout << RED
              << "[TEST] Trying to execute robotomy with insufficient grade "
                 "(grade 50)"
              << NC << std::endl;
    try {
        RobotomyRequestForm robForm2("R2D2");
        Bureaucrat weakGuy("WeakGuy", 50);
        weakGuy.signForm(robForm2);
        robForm2.execute(weakGuy);
        std::cout << YELLOW
                  << "WARNING: Should have thrown GradeTooLowException!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // ========== PRESIDENTIAL PARDON TESTS ==========
    std::cout << BLUE << "=== PresidentialPardonForm Tests ===" << NC
              << std::endl
              << std::endl;

    std::cout << GREEN << "[TEST] Creating PresidentialPardonForm" << NC
              << std::endl;
    PresidentialPardonForm pardonForm("Arthur Dent");
    std::cout << pardonForm << std::endl << std::endl;

    // Test: Presidential - příliš nízký grade pro podpis
    std::cout << RED
              << "[TEST] Trying to sign with insufficient grade (grade 30)"
              << NC << std::endl;
    try {
        Bureaucrat normalGuy("NormalGuy", 30);
        std::cout << normalGuy;
        normalGuy.signForm(pardonForm);
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // Test: Presidential - úspěšný podpis a exekuce
    std::cout << GREEN << "[TEST] Signing and executing with Zaphod (grade 1)"
              << NC << std::endl;
    try {
        Bureaucrat zaphod("Zaphod", 1);
        std::cout << zaphod;
        zaphod.signForm(pardonForm);
        std::cout << YELLOW;
        pardonForm.execute(zaphod);
        std::cout << NC;
        std::cout << GREEN << "✓ Form executed successfully!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "✗ Unexpected exception: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    // Test: Presidential - příliš nízký grade pro exekuci
    std::cout << RED
              << "[TEST] Trying to execute with insufficient grade (grade 6)"
              << NC << std::endl;
    try {
        PresidentialPardonForm pardonForm2("Ford Prefect");
        Bureaucrat highRank("HighRank", 6);
        highRank.signForm(pardonForm2);
        pardonForm2.execute(highRank);
        std::cout << YELLOW
                  << "WARNING: Should have thrown GradeTooLowException!" << NC
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << NC
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== All tests completed ===" << NC << std::endl;
    std::cout << YELLOW
              << "Don't forget to check the generated shrubbery files!" << NC
              << std::endl;

    return 0;
}
