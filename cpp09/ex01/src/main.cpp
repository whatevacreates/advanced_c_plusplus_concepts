
#include "RPN.hpp"
#include "Utils.hpp"

void	checkArguments(int argc, char *argv[])
{
	int digit_count = 0;
	int operant_count = 0;
	if (argc < 2)
		{
        std::cerr << LIGHT_RED << "Pass as an argument one string which represents the inverted Polish Notation" << RESET << std::endl;
        exit(1);
        }

	for(int k = 1; k < argc ; k++)
	{
		for(size_t i = 0; argv[k][i] != '\0' ; i++)
	{
		if(isdigit(argv[k][i]) && isdigit(argv[k][i+1]))
		{
			std::cerr << LIGHT_RED << "Your input contains numbers which is not allowed." << RESET << std::endl;
        	exit(1);
		}

if(isdigit(argv[k][i]))
		{
			digit_count++;
		}
		
		std::cout << argv[k][i] << std::endl;

		if(argv[k][i] != ' ' && argv[k][i] != '+' && argv[k][i] != '-' && argv[k][i] != '*' && argv[k][i] != '/' && !isdigit(argv[k][i]))
		{
			 std::cerr << LIGHT_RED << "Your input contains forbidden characters: " << argv[k][i] <<  RESET << std::endl;
        	exit(1);
		}
		if(!isdigit(argv[k][i]) && argv[k][i] != ' ')
		{
			operant_count++;
		}
		if(digit_count == 1 && operant_count == 1)
		{
			 std::cerr << LIGHT_RED << "Wrong syntax. Get familiat with the Reverse Polish Notation." << RESET << std::endl;
        	exit(1);

		}
	}
	}
	if(operant_count +1!= digit_count)
	{
		std::cerr << LIGHT_RED << "Operands : operators ratio is not right." << RESET << std::endl;
        	exit(1);
	}
	if(digit_count <= 1)
	{ std::cerr << LIGHT_RED << "Not enough operands." << RESET << std::endl;
        	exit(1);

	}
      
}

int	main(int argc, char *argv[])
{
	
	checkArguments(argc, argv);
	try{
			RPN go(argc, argv);
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Runtime  error: " << e.what() << std::endl;
	} catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() <<std::endl;
	} catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

}
