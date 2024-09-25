
#include "Array.hpp"












#include "Array.hpp"

void testBasicOperations() {
    std::cout << "==== Test 1: Basic Operations ====" << std::endl;
    
    Array<int> intArray(5); // Create an array of 5 integers
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10; // Assign values 0, 10, 20, 30, 40
    }

    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl; // Print the values
    }

    std::cout << "Array size: " << intArray.size() << std::endl; // Verify size
    std::cout << std::endl;
}






void testCopyAndAssignment() {
    std::cout << "==== Test 2: Copy Constructor and Assignment Operator ====" << std::endl;

    Array<int> array1(3);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;

    Array<int> array2 = array1; // Copy constructor
    Array<int> array3(5);
    array3 = array1; // Assignment operator

    // Modify array1 to check for deep copy
    array1[0] = 100;

    std::cout << "Original array1: ";
    for (unsigned int i = 0; i < array1.size(); i++) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied array2: ";
    for (unsigned int i = 0; i < array2.size(); i++) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Assigned array3: ";
    for (unsigned int i = 0; i < array3.size(); i++) {
        std::cout << array3[i] << " ";
    }
    std::cout << "csefsefes" << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
}










void testOutOfBounds() {
    std::cout << "==== Test 3: Out-of-Bounds Access ====" << std::endl;
    
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 2; // Assign values
    }

    try {
        std::cout << intArray[10] << std::endl; // Out-of-bounds access
    }
    catch (const std::out_of_range& e) {
    }

    try {
        std::cout << intArray[-1] << std::endl; // Out-of-bounds access
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}






int main() {
    testBasicOperations();   // Test 1: Basic operations
    testCopyAndAssignment(); // Test 2: Copy constructor and assignment operator
    testOutOfBounds();       // Test 3: Out-of-bounds access

    return 0;
}