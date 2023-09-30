#include <iostream>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int j = 1; char *str = argv[j]; j++)
		{
			for (int i = 0; str[i] != '\0'; i++)
				std::cout << char(toupper(str[i]));
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return 0;
}
