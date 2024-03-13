#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
class ScalarConverter {
    private:
    public:
        ScalarConverter();
        ScalarConverter(const std::string& copy);
        ScalarConverter& operator=(const ScalarConverter& ref);
        ~ScalarConverter();
};
#endif