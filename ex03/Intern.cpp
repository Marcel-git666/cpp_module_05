#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::formNames[3] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};

const Intern::FormCreator Intern::creators[3] = {
    &Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon};

AForm *Intern::createShrubbery(std::string const &target) const {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string const &target) const {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(std::string const &target) const {
    return new PresidentialPardonForm(target);
}

// Orthodox Canonical Form
Intern::Intern(void) {}
Intern::Intern(Intern const &) {}
Intern &Intern::operator=(Intern const &) { return *this; }

Intern::~Intern(void) {}

// Other methods
AForm *Intern::makeForm(std::string const &name,
                        std::string const &target) const {
    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*creators[i])(target);
        }
    }

    std::cout << "Error: Unknown form name" << std::endl;
    return NULL;
}

std::ostream &operator<<(std::ostream &out, Intern const &) {
    out << "Intern can create: ";
    for (int idx = 0; idx < 3; idx++) {
        out << Intern::formNames[idx];
        if (idx < 2) {
            out << ", ";
        }
    }
    out << '\n';
    return out;
}
