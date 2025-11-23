#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
  private:
    std::string target;

  public:
    // Orthodox Canonical Form
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    virtual ~ShrubberyCreationForm(void);

    // Other methods
    ShrubberyCreationForm(std::string const &target);

    virtual void execute(Bureaucrat const &executor) const;

    class FileNotOpenedException : public std::exception {
        const char *what() const throw();
    };

    // Getters
    std::string const &getTarget() const;
};

#endif
