#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

// Orthodox Canonical Form
RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), target("Default_target") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if (this != &other) {
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// Other methods
RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "* Bzzz.... [drilling noises]\n";
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully.\n";
    } else {
        std::cout << "Robotomy on " << target << " failed.\n";
    }
}

// Getters
std::string const &RobotomyRequestForm::getTarget() const { return target; }
