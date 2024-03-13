#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }
int main(){
    try
    {
        // Span span1= Span(6);
        // Span span2(12);
        // span1.addNumber(1);
        // span1.addNumber(2);
        // span1.addNumber(3);
        // span1.addNumber(4);
        // span2.addNumber(21);
        // span2.addNumber(32);

        // std::cout << span1.longestSpan() << std::endl;
        // span1 = span2;
        // std::cout << span1.longestSpan() << std::endl;

        const int size = 10000;
        Span span(size);

        std::srand(std::time(NULL));

        for (int i = 0; i < size; i++)
        {
            int randomNumber = std::rand();
            span.addNumber(randomNumber);
        }

        int shortestSpan = span.shortestSpan();
        std::cout << "Shortest span: " << shortestSpan << std::endl;

        int longestSpan = span.longestSpan();
        std::cout << "Longest span: " << longestSpan << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }
    // system("leaks a.out");
    return 0;
}