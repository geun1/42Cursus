#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <iostream>

Span::~Span(){}

Span::Span() : maxSize(0) {}

Span::Span(const Span& copy) : maxSize(copy.maxSize), numbers(copy.numbers) {}

Span& Span::operator=(const Span& ref)
{
    if (this != &ref)
    {
        maxSize = ref.maxSize;
        numbers = ref.numbers;
    }
    return *this;
}

Span::Span(unsigned int size) : maxSize(size) {}
void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
        throw std::runtime_error("용량초과");

    numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (numbers.size() <= 1)
        throw std::runtime_error("비교할 숫자 부족");

    std::sort(numbers.begin(), numbers.end());

    std::vector<int> spans;
    std::adjacent_difference(numbers.begin(), numbers.end(),std::back_inserter(spans));

    return *std::min_element(spans.begin() + 1, spans.end());
}

int Span::longestSpan()
{
    if (numbers.size() <= 1)
        throw std::runtime_error("비교할 숫자 부족");

    return *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());
}