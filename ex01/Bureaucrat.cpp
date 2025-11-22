#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : name("Default bureaucrat"), grade(100) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}
Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat(void) {}

// Other methods
Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : name(name), grade(grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::string const &Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    grade--;
}
void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

void Bureaucrat::signForm(Form &f) {
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't sign " << f.getName() << " because "
                  << e.what() << std::endl;
    }
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return out;
}
