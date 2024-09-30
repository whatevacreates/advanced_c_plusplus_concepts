#include "Utils.hpp"
#include "Span.hpp"
#include <vector>

int main()
{
    Span sp = Span(5);
    Span test = Span(5);
    std::vector<int> arrayInt;
    arrayInt.push_back(6);
     arrayInt.push_back(3);
      arrayInt.push_back(1);
       arrayInt.push_back(9);

    sp.addNumber(6);
     sp.addNumber(3);
      sp.addNumber(17);
       sp.addNumber(9);
        sp.addNumber(11);

        std::cout <<sp.shortestSpan() << std::endl;
         std::cout <<sp.longestSpan() << std::endl;
         std::cout << BOLD << B_DUSTY_ROSE << ":::::::::::::::::::: TEST ::::::::::::::::::::" << RESET << std::endl;
          sp.addNumber(80);
          test.addNumber(6);
          std::cout <<test.shortestSpan() << std::endl;
test.addRange(arrayInt.begin(), arrayInt.end());
 std::cout <<test.shortestSpan() << std::endl;
         std::cout <<test.longestSpan() << std::endl;

         return 0;

}