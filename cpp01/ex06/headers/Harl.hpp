#include <iostream>
#include <string>

class Harl
{
  public:
	Harl();
	~Harl();
	void complain(std::string input);

  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	static const std::string complaints_info[4];
	typedef void (Harl::*HarlFunc)();
	HarlFunc array_of_pointers[4];
};
