#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

  public:
    // Orthodox Canonical Form
    AForm(void);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm(void);

    // Other methods
    AForm(std::string const &name, int gradeToSign, int gradeToExecute);

    // Getters
    std::string const &getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getIsSigned() const;

    void beSigned(Bureaucrat const &b);
    virtual void execute(Bureaucrat const &executor) const = 0;

    // Exceptions
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &f);

#endif
