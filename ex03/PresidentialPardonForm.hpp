#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {
  private:
    std::string target;

  public:
    // Orthodox Canonical Form
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    virtual ~PresidentialPardonForm(void);

    // Other methods
    PresidentialPardonForm(std::string const &target);

    virtual void execute(Bureaucrat const &executor) const;

    // Getters
    std::string const &getTarget() const;
};

#endif
