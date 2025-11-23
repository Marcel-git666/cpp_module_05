#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
  private:
    std::string target;

  protected:
    virtual void do_execute_checked(Bureaucrat const &executor) const;

  public:
    // Orthodox Canonical Form
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    virtual ~ShrubberyCreationForm(void);

    // Other methods
    ShrubberyCreationForm(std::string const &target);

    class FileNotOpenedException : public std::exception {
        const char *what() const throw();
    };

    // Getters
    std::string const &getTarget() const;
};

#endif
