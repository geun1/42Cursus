#include "Form.hpp"

void prevTest() {
  std::cout << "||test0|| 쉬프트 연산자 오버로딩" << std::endl;
  Bureaucrat test0("test0", 1);
  std::cout << test0 << std::endl;
  std::cout << "||test1|| grade 범위 초과" << std::endl;
  try {
    Bureaucrat test1("test1", 200);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "||test2|| invalid increase" << std::endl;
  try {
    Bureaucrat test2("test2", 1);
    test2.incrementGrade();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
	
  std::cout << std::endl;
  std::cout << "||test3|| invalid decrease" << std::endl;
  try {
    Bureaucrat test3("test3", 150);
    test3.decrementGrade();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
	std::cout << std::endl;
  std::cout << "prev test complete" << std::endl;

}

int main() {
  prevTest();

  std::cout << std::endl << "||test1|| 불가능한 sign Grade" << std::endl;
  try {
    std::cout << "Form form1(\"form1\", 0, 75);" << std::endl;
    Form form2("form1", 0, 75);
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << std::endl;
    std::cout << "form2(\"form2\", 75, 151);" << std::endl;
    Form form2("form2", 75, 151);
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "||test2||  beSigned test" << std::endl;
  std::cout << "Form form3(\"form3\", 75, 75);" << std::endl;
  Form form3("form3", 75, 75);
  try {
    Bureaucrat burea3("burea3", 76);
    form3.beSigned(burea3);
    std::cout << "This message is not print." << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  
  try {
    Bureaucrat burea4("burea4", 74);
    form3.beSigned(burea4);
  } catch (std::exception& e) {
    std::cout << "This message is not print." << std::endl;
  }
  std::cout << form3 << std::endl;
  std::cout << std::endl;
  std::cout << "||test3|| signForm test" << std::endl;
  std::cout << "Form form3(\"form3\", 75, 75);" << std::endl;
  std::cout << "Bureaucrat burea5(\"burea5\", 74);" << std::endl;
  Bureaucrat burea5("burea5", 74);
  burea5.signForm(form3);

  std::cout << std::endl;
  std::cout << "Form form3(\"form3\", 75, 75);" << std::endl;
  std::cout << "Bureaucrat burea6(\"burea6\", 76);" << std::endl;
  Bureaucrat burea6("burea6", 76);
  burea6.signForm(form3);

  std::cout << "test complete" << std::endl;
  //system("leaks a.out");
	return 0;
}
