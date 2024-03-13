#include <iostream>
#include "iter.hpp"
#include <string>
class Person {
public:
    std::string name;
    
    Person(std::string n) : name(n) {}
};

void print(const Person& p){
    std::cout << p.name << " ";
}
int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArraySize = sizeof(intArray) / sizeof(int);
    std::cout << "Integer array\t:\t";
    iter(intArray, intArraySize, print_arr<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);
    std::cout << "Double array\t:\t";
    iter(doubleArray, doubleArraySize, print_arr<double>);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "This", "Is", "Test"};
    std::size_t strArraySize = sizeof(strArray) / sizeof(std::string);
    std::cout << "String array\t:\t";
    iter(strArray, strArraySize, print_arr<std::string>);
    std::cout << std::endl;

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::size_t charArraySize = sizeof(charArray) / sizeof(char);
    std::cout << "Char array\t:\t";
    iter(charArray, charArraySize, print_arr<char>);
    std::cout << std::endl;

    // system("leaks a.out");
    return 0;
}
