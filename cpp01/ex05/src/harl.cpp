
#include "Harl.hpp"

const std::string Harl::complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const std::string Harl::complaints_info[4] = {"DEBUG: I love having extra bacon for"
												"my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!",
												"INFO: I cannot believe adding extra bacon costs more money. You didn’t put"
												"enough bacon in my burger! If you did,
													I wouldn’t be asking for more!",
												"WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for"
												"years whereas you started working here since last month.",
												"ERROR: This is unacceptable! I want to speak to the manager now."};

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void Harl::complain(std::string input)
{
	int i = 0;
	while (input.compare(complaints[i++]) != 0);
	std::cout << "Harl complaints: " << complaints_info[i - 1] << std::endl;
}