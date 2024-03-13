#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "AForm.hpp"



class ShrubberyCreationForm : public AForm {
  private:
    static const std::string _treeOfAscii;
    std::string _target;

    ShrubberyCreationForm();

  public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat& bureaucrat) const;
};

#endif 
