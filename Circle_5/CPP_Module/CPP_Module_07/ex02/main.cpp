#include <iostream>
#include "Array.hpp"

class Person {
public:
    std::string name;
    int age;

    Person() : name("Unknown"), age(0) {}
    Person(std::string n, int a) : name(n), age(a) {}
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << " (" << p.age << ")";
    return os;
}

int main() {
    // Test with integers
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i;
    try {
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;
        std::cout << intArray[5] << std::endl;  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout<<std::endl;
    
    // Test with chars
    Array<char> charArray(3);
    charArray[0] = 'a';
    charArray[1] = 'b';
    charArray[2] = 'c';
    try {
        for (unsigned int i = 0; i < charArray.size(); i++)
            std::cout << charArray[i] << " ";
        std::cout << std::endl;
        std::cout << charArray[3] << std::endl;  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout<<std::endl;

    // Test with strings
    Array<std::string> strArray(2);
    strArray[0] = "hello";
    strArray[1] = "world";
    try {
        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;
        std::cout << strArray[2] << std::endl;  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout<<std::endl;

    // Test copy constructor and assignment operator
    Array<int> copyArray = intArray;
    try {
        for (unsigned int i = 0; i < copyArray.size(); i++)
            std::cout << copyArray[i] << " ";
        std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    Array<Person> peopleArray(3);    
    peopleArray[0] = Person("John", 30);
    peopleArray[1] = Person("Jane", 25);
    peopleArray[2] = Person("Jack", 35);

    try {
        for (unsigned int i = 0; i < peopleArray.size(); i++)
            std::cout << peopleArray[i] << "\n";
        std::cout << peopleArray[3] << std::endl;  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout<<std::endl;

    // Test copy constructor and assignment operator
    Array<Person> copyPeopleArray = peopleArray;
    try {
        for (unsigned int i = 0; i < copyPeopleArray.size(); i++)
            std::cout << copyPeopleArray[i] << "\n";
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout<<std::endl;

    // system("leaks a.out");
    return 0;    
}
