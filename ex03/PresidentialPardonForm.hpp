#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {
  private:
    std::string target;

  protected:
    virtual void do_execute_checked(Bureaucrat const &executor) const;

  public:
    // Orthodox Canonical Form
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    virtual ~PresidentialPardonForm(void);

    // Other methods
    PresidentialPardonForm(std::string const &target);

    // Getters
    std::string const &getTarget() const;
};

#endif
