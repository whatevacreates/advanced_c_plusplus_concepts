
#include "Harl.hpp"

const std::string Harl::complaints_info[4] = {"DEBUG: I love having extra bacon for"
												"my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!",
												"INFO: I cannot believe adding extra bacon costs more money. You didn’t put"
												"enough bacon in my burger! If you did,"
												"I wouldn’t be asking for more!",
												"WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for"
												"years whereas you started working here since last month.",
												"ERROR: This is unacceptable! I want to speak to the manager now."};

Harl::Harl()
{
	array_of_pointers[0] = &Harl::debug;
	array_of_pointers[1] = &Harl::info;
	array_of_pointers[2] = &Harl::warning;
	array_of_pointers[3] = &Harl::error;
	return ;
}

Harl::~Harl()
{
	return ;
}

void Harl::debug(void)
{
	std::cout << "Harl complaints: " << complaints_info[0] << std::endl;
};
void Harl::info(void)
{
	std::cout << "Harl complaints: " << complaints_info[1] << std::endl;
};
void Harl::warning(void)
{
	std::cout << "Harl complaints: " << complaints_info[2] << std::endl;
};
void Harl::error(void)
{
	std::cout << "Harl complaints: " << complaints_info[3] << std::endl;
};
void Harl::complain(std::string input)
{
	std::string inputs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (input.compare(inputs[i]) != 0)
		i++;
	std::cout << i << std::endl;
	switch (i)
	{
	case 0:
		(this->*array_of_pointers[0])();
	case 1:
		(this->*array_of_pointers[1])();
	case 2:
		(this->*array_of_pointers[2])();
	case 3:
		(this->*array_of_pointers[3])();
	}
};
