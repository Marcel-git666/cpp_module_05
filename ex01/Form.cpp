#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Form::Form(void)
    : name("Default form"), isSigned(false), gradeToSign(150),
      gradeToExecute(150) {}

Form::Form(Form const &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(Form const &other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}
Form::~Form(void) {}

// Other methods
Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

// Getters
std::string const &Form::getName() const { return name; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }
bool Form::getIsSigned() const { return isSigned; }

void Form::beSigned(Bureaucrat const &b) {
    if (isSigned) {
        std::cout << "Form " << name << " is already signed.\n";
        return;
    }
    if (b.getGrade() > gradeToSign) {
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

std::ostream &operator<<(std::ostream &out, Form const &f) {
    out << "Form " << f.getName()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
