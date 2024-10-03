#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
#include <stack>
#include <utility>
#include <algorithm>

class RPN
{
  private:
	std::stack<int> _nStack;

  public:
	RPN();
	RPN(int argc, char *argv[]);
	~RPN();
	RPN(const RPN &other);
	void doOperations(char op);
	RPN &operator=(const RPN &other);
};
#endif