#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void shrubberyTest(Bureaucrat b1, Bureaucrat b4) {
  std::cout << "||Shrubbery test||" << std::endl;
  AForm* f1 = new ShrubberyCreationForm("Christmas");
  AForm* f2 = new ShrubberyCreationForm("Tree");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl;
  std::cout << std::endl;
  std::cout << "Grade 141, can sign?" << std::endl;
  b4.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 141, can execute?" << std::endl;
  b4.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "||Shrubbery test finish||" << std::endl;
  std::cout << std::endl;
  delete f1;
  delete f2;
}

void robotomyTest(Bureaucrat b1, Bureaucrat b3) {
  std::cout << "||Robotomy test||" << std::endl;
  AForm* f1 = new RobotomyRequestForm("f1");
  AForm* f2 = new RobotomyRequestForm("f2");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl; 
  std::cout << std::endl;
  std::cout << "Grade 50, can sign?" << std::endl;
  b3.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 50, can execute?" << std::endl;
  b3.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "||Robotomy test finish||" << std::endl;
  std::cout << std::endl;
  delete f1;
  delete f2;
}

void presidentialTest(Bureaucrat b1, Bureaucrat b2) {
  std::cout << "||Presidential test||" << std::endl;
  AForm* f1 = new PresidentialPardonForm("f1");
  AForm* f2 = new PresidentialPardonForm("f2");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl; 
  std::cout << std::endl;
  std::cout << "Grade 15, can sign?" << std::endl;
  b2.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 15, can execute?" << std::endl;
  b2.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "||Presidential test finish||" << std::endl;
  std::cout << std::endl;
  delete f1;
  delete f2;
}

int main(void) {
  Bureaucrat b1("b1", 1);
  Bureaucrat b2("b2", 15);
  Bureaucrat b3("b3", 50);
  Bureaucrat b4("b4", 141);

  std::cout << b1 << b2 << b3 << b4 << std::endl;
  shrubberyTest(b1, b4);
  robotomyTest(b1, b3);
  presidentialTest(b1, b2);
  // system("leaks a.out");
  return 0;
}