#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AForm.hpp"



class Intern {
  private:

  public:    
    Intern();
    Intern(const Intern& copy);
    Intern&	operator=(const Intern& ref);
    ~Intern();

    AForm* makeForm(std::string name, std::string target);
};


#endif
