#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
AForm::AForm(void)
    : name("Default form"), isSigned(false), gradeToSign(150),
      gradeToExecute(150) {}

AForm::AForm(AForm const &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(AForm const &other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}
AForm::~AForm(void) {}

// Other methods
AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

// Getters
std::string const &AForm::getName() const { return name; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }
bool AForm::getIsSigned() const { return isSigned; }

void AForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    do_execute_checked(executor);
}

void AForm::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    isSigned = true;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed, can't execute!";
}

std::ostream &operator<<(std::ostream &out, AForm const &f) {
    out << "Form " << f.getName()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
