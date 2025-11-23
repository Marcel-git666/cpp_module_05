#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

// Orthodox Canonical Form
PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5), target("Default_target") {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other)
    : AForm(other), target(other.target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    if (this != &other) {
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

// Other methods
PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

// Getters
std::string const &PresidentialPardonForm::getTarget() const { return target; }
