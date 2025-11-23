#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
  private:
    std::string target;

  protected:
    virtual void do_execute_checked(Bureaucrat const &executor) const;

  public:
    // Orthodox Canonical Form
    RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    virtual ~RobotomyRequestForm(void);

    // Other methods
    RobotomyRequestForm(std::string const &target);

    // Getters
    std::string const &getTarget() const;
};

#endif
