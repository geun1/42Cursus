#include "Base.hpp"

Base::~Base(){}

Base* generate(){
    int abc = std::time(NULL) % 3;

    if (abc == 0) {
        return new A();
        std::cout << "A 클래스 생성" << std::endl;
    } else if (abc == 1) {
        return new B();
        std::cout << "B 클래스 생성" << std::endl;
    } else if (abc == 2) {
        return new C();
        std::cout << "C 클래스 생성" << std::endl;
    }
    return NULL;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A pointer로 다운캐스팅" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B pointer로 다운캐스팅" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C pointer로 다운캐스팅" << std::endl;    
}

void identify(Base& p){
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A ref로 다운캐스팅" << std::endl;
        static_cast<void>(a);
    } catch (std::exception&) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B ref로 다운캐스팅" << std::endl;
            static_cast<void>(b);
        } catch (std::exception&) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "C ref로 다운캐스팅" << std::endl;
                static_cast<void>(c);
            } catch (std::exception&) {
                std::cout << "다운 캐스팅 실패" << std::endl;
            }
        }
    }
}

