#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern {
  private:
    static const std::string formNames[3];
    typedef AForm *(Intern::*FormCreator)(std::string const &);
    AForm *createShrubbery(std::string const &target);
    AForm *createRobotomy(std::string const &target);
    AForm *createPardon(std::string const &target);

  public:
    // Orthodox Canonical Form
    Intern(void);
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern(void);

    // Other methods
    AForm *makeForm(std::string name, std::string target);
    static std::string const &getFormName(int index);
};

std::ostream &operator<<(std::ostream &out, Intern const &i);

#endif
