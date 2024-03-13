#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template<typename T>
class Array {
    private:
        T* array;
        unsigned int capacity;
    public:
        Array():array(NULL), capacity(0){
            this->array = new T[0];
        }

        Array(unsigned int n): array(NULL), capacity(n){
            if (this->capacity)
                this->array = new T[this->capacity];
        }

        Array(const Array& copy): array(NULL), capacity(copy.size()){
            if (this->capacity)
                this->array = new T[this->capacity];
            for (unsigned int i = 0; i < this->capacity; i++)
                this->array[i] = copy[i];
        }

        ~Array() {
            if (this-> capacity)
                delete [] this-> array;
            this-> array = NULL;
            this-> capacity = 0;
        }
        unsigned int size() const {
            return this->capacity;
        }

        Array& operator=(const Array& ref){
            if (this != &ref) {
                this -> capacity = ref.size();
                if (this-> capacity)
                    this->array = new T[this->capacity];
                for (unsigned int i = 0; i < this-> capacity; i++)
                    this->array[i] = ref[i];
            }
            return *this;
        }

        T& operator[](unsigned int i){
            if (i < 0 || i > this-> capacity -1) 
                throw OverRange();
            return this->array[i];
        }

        const T& operator[](unsigned int i) const {
            if (i < 0 || i > this-> capacity -1) 
                throw OverRange();
            return this->array[i];
        }

        class OverRange : public std::exception {
            public:
                const char* what() const throw() {
                    return "error - range over";
                }
        };        
};
#endif