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
	static const std::string complaints[4];
	static const std::string complaints_info[4];
};


