#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "AForm.hpp"



class RobotomyRequestForm : public AForm{
  private:
    std::string _target;

    RobotomyRequestForm();

  public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);
    ~RobotomyRequestForm();

    void execute(const Bureaucrat &bureaucrat) const;
};

#endif
