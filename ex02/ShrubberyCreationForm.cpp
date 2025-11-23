#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), target("Default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this != &other) {
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// Other methods
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream myfile;
    myfile.open((target + "_shrubbery").c_str());
    if (!myfile.is_open()) {
        throw ShrubberyCreationForm::FileNotOpenedException();
    }
    const std::string tree = "       *\n"
                             "      ***\n"
                             "     *****\n"
                             "    *******\n"
                             "   *********\n"
                             "      |||\n\n";

    for (int i = 0; i < 10; i++) {
        myfile << tree;
    }

    myfile << '\n';
    myfile.close();
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const
    throw() {
    return "File can't be open - critical error!";
}

// Getters
std::string const &ShrubberyCreationForm::getTarget() const { return target; }
