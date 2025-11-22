#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

  public:
    // Orthodox Canonical Form
    Form(void);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form(void);

    // Other methods
    Form(std::string const &name, int gradeToSign, int gradeToExecute);

    // Getters
    std::string const &getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getIsSigned() const;

    void beSigned(Bureaucrat const &b);

    // Exceptions
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif
