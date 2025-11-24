#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern {
  private:
    typedef AForm *(Intern::*FormCreator)(std::string const &) const;
    static const FormCreator creators[3];
    AForm *createShrubbery(std::string const &target) const;
    AForm *createRobotomy(std::string const &target) const;
    AForm *createPardon(std::string const &target) const;

  public:
    static const std::string formNames[3];
    // Orthodox Canonical Form
    Intern(void);
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern(void);

    // Other methods
    AForm *makeForm(std::string const &name, std::string const &target) const;
};

std::ostream &operator<<(std::ostream &out, Intern const &i);

#endif
