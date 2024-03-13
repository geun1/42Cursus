#include "whatever.hpp"
#include <iostream>

class Person {
public:
    int age;
    
    Person(int a) : age(a) {}
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.age;
    return os;
}

int main() {
        // Test with integers
    int a = 10;
    int b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << min(a, b) << std::endl;
    std::cout << "max(a, b) = " << max(a, b) << std::endl;

    // Test with doubles
    double c = 1.5;
    double d = 2.5;
    std::cout << "\nBefore swap: c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << min(c, d) << std::endl;
    std::cout << "max(c, d) = " << max(c, d) << std::endl;

    // Test with characters
    char e = 'x';
    char f = 'y';
    std::cout << "\nBefore swap: e = " << e << ", f = " << f << std::endl;
    swap(e, f);
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << min(e, f) << std::endl;
    std::cout << "max(e, f) = " << max(e, f) << std::endl;

    // Test with strings
    std::string str1 = "apple";
    std::string str2 = "banana";
    std::cout << "\nBefore swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    std::cout << "min(str1, str2) = " << min(str1, str2) << std::endl;
    std::cout << "max(str1, str2) = " << max(str1, str2) << std::endl;

    // Test with user-defined types
    Person person1(30);
    Person person2(20);
    std::cout << "\nBefore swap: person1 = " << person1 << ", person2 = " << person2 << std::endl;
    swap(person1, person2);
    std::cout << "After swap: person1 = " << person1 << ", person2 = " << person2 << std::endl;
    std::cout << "min(person1, person2) = " << min(person1.age, person2.age) << std::endl;
    std::cout << "max(person1, person2) = " << max(person1.age, person2.age) << std::endl;

    return 0;
}
