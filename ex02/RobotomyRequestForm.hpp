#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
  private:
    std::string target;

  public:
    // Orthodox Canonical Form
    RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    virtual ~RobotomyRequestForm(void);

    // Other methods
    RobotomyRequestForm(std::string const &target);

    virtual void execute(Bureaucrat const &executor) const;

    // Getters
    std::string const &getTarget() const;
};

#endif
