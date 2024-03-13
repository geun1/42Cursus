#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AForm.hpp"



class PresidentialPardonForm : public AForm{
  private:
    std::string _target;

    PresidentialPardonForm();

  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& ref);
    PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat &bureaucrat) const;
};

#endif
