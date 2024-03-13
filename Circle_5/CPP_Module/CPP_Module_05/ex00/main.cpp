#include "Bureaucrat.hpp"

int main() {
  std::cout << "||test0|| 쉬프트 연산자 오버로딩" << std::endl;
  Bureaucrat test0("test0", 1);
  std::cout << test0 << std::endl;
  std::cout << "||test1|| grade 범위 초과" << std::endl;
  try {
    Bureaucrat test1("test1", 200);
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "||test2|| invalid increase" << std::endl;
  try {
    Bureaucrat test2("test2", 1);
    test2.incrementGrade();
    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
	
  std::cout << std::endl;
  std::cout << "||test3|| invalid decrease" << std::endl;
  try {
    Bureaucrat test3("test3", 150);
    test3.decrementGrade();
    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
	std::cout << std::endl;
  std::cout << "test complete" << std::endl;
	return 0;
}