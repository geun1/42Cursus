#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T* array, std::size_t lengthOfArray, void (*f)(F &)) {
    for (std::size_t idx = 0; idx < lengthOfArray; idx++)
        f(array[idx]);
}

template <typename T>
void print_arr(T& arr){
    std::cout << arr << " ";
    return ;
}

#endif