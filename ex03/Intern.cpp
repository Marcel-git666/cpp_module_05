#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::formNames[3] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};
AForm *Intern::createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(std::string const &target) {
    return new PresidentialPardonForm(target);
}

// Orthodox Canonical Form
Intern::Intern(void) {}
Intern::Intern(Intern const &other) {}
Intern &Intern::operator=(Intern const &other) { return *this; }

Intern::~Intern(void) {}

// Other methods
AForm *Intern::makeForm(std::string name, std::string target) {
    FormCreator creators[3] = {&Intern::createShrubbery,
                               &Intern::createRobotomy, &Intern::createPardon};

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*creators[i])(target);
        }
    }

    std::cout << "Error: Unknown form name" << std::endl;
    return NULL;
}

std::string const &Intern::getFormName(int index) {
    if (index >= 0 && index < 3) {
        return formNames[index];
    } else {
        return "";
    }
}

std::ostream &operator<<(std::ostream &out, Intern const &i) {
    out << "Intern can create: ";
    for (int i = 0; i < 3; i++) {
        out << Intern::getFormName(i);
    }
    out << '\n';
    return out;
}
