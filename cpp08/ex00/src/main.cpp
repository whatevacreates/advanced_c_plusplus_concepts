#include <iostream>
#include <algorithm>
#include <string>



template <typename Iterator>
bool next_permutation_func(Iterator first, Iterator last) {
    if (first == last) return false;
    Iterator i = last;
    if (first == --i) return false;

    // Find the rightmost element that is smaller than its next element
    while (true) {
        Iterator i1, i2;

        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}
int main() {
    std::string str = "abc";  // Input string

    // Sort the string to start with the lexicographically smallest permutation
    std::sort(str.begin(), str.end());

    do {
        std::cout << str << std::endl;
    } while (next_permutation_func(str.begin(), str.end()));

    return 0;
}