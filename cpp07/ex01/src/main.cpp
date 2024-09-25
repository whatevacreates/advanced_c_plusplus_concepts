#include "Iter.hpp"

// Template function to print elements
template<typename T>
void string(T element) {
    std::cout << "string: " << element << std::endl;
}

// Template function to print square of elements
template<typename T>
void square(T element) {
    std::cout << "Square: " << element * element << std::endl;
}

// Template function to print double of elements
template<typename T>
void doubleValue(T element) {
    std::cout << "Double Value: " << element * 2 << std::endl;
}

void test1() {
    std::string array1[3] = {"pineapple", "apple", "banana"};
    ::iter(array1, 3, string<std::string>);
}

void test2() {
    int array2[5] = {1, 2, 3, 4, 5};
    ::iter(array2, 5, square<int>);
}

void test3() {
    double array3[4] = {1.1, 2.2, 3.3, 4.4};
    ::iter(array3, 4, doubleValue<double>);
}

int main(void) {
    std::cout << ":::::::::::::::::::STRING:::::::::::::::::::" << std::endl;
    test1();
    
    std::cout << ":::::::::::::::::::INT:::::::::::::::::::" << std::endl;
    test2();
    
    std::cout << ":::::::::::::::::::DOUBLE:::::::::::::::::::" << std::endl;
    test3();

    return 0;
}
