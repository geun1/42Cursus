#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iterator>
#include "easyfind.hpp"

int main() {
    try {
        // std::vector 예시 (push_back 사용)
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::vector<int>::iterator vecIt = easyfind(vec, 3);
        if (vecIt != vec.end()) {
            std::cout << "값 3을 찾았습니다. 인덱스: " << std::distance(vec.begin(), vecIt) << std::endl;
        }

        // std::list 예시 (push_back 사용)
        // std::list<int> lst;
        // lst.push_back(10);
        // lst.push_back(20);
        // lst.push_back(30);
        // lst.push_back(40);
        // lst.push_back(50);
        // std::list<int>::iterator lstIt = easyfind(lst, 40);
        // if (lstIt != lst.end()) {
        //     std::cout << "값 40을 찾았습니다. 인덱스: " << std::distance(lst.begin(), lstIt) << std::endl;
        // }

        // std::set 예시 (insert 사용)
        std::set<int> st;
        st.insert(100);
        st.insert(200);
        st.insert(300);
        st.insert(400);
        st.insert(500);
        std::set<int>::iterator stIt = easyfind(st, 200);
        if (stIt != st.end()) {
            std::cout << "값 200을 찾았습니다." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "오류 발생: " << e.what() << std::endl;
    }
    // system("leaks a.out");
    return 0;
}
