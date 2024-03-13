
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
    unsigned int maxSize;
    std::vector<int> numbers;

public:
    Span();
    Span(const Span& copy);
    Span& operator=(const Span& ref);
    Span(unsigned int size);
    ~Span();
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

};

#endif