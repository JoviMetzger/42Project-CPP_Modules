#include <iostream>
#include <fstream>
#include <string>

// COLORS
# define RED "\e[1;91m"
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

/* ft_executing();
 *	- Opens an input file (ifstream).
 *	- Creates an output file (ofstream).
 *		- ofstream/ifstream takes a const char*
 *		- convert the std::string to const char* with 'c_str'
 *	- Reads each line 'getline'
 *	- If it finds the text (old_str) in the line, 
 *	  it remembers where it found it (the position), 
 *	  which is stored in f_pos.
 *	- 'old_str' is being replaces with the new text (new_str).
 *	- Writes the modified line to the output file..
 *	- Finally, it closes both the input and output files.
 */
void	ft_executing(const char* filename, std::string old_str, std::string new_str)
{
	std::ifstream	infile(filename);				// Input File Stream
	if (!infile)
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return ;
	}

	std::string	output_filename = std::string(filename) + ".replace";
	const char*	conv_outfilename = output_filename.c_str();	// Converts to const char*

	std::ofstream	outfile(conv_outfilename);			// Output File Stream
	if (!outfile)
	{
		std::cout << "Error: Unable to create file" << std::endl;
		return ;
	}

	std::string	line;
	while (std::getline(infile, line))				// Replacing the lines
	{
		size_t	f_pos;
		while ((f_pos = line.find(old_str)) != std::string::npos)
			line.replace(f_pos, old_str.length(), new_str);
		outfile << line << '\n';
	}
	infile.close();
	outfile.close();

	return ;
}

/* main();
 *	- Checks if the correct number of arguments (four) is provided.
 *	- Verifies that the string to be replaced (argv[2]) is not empty.
 */
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string str = argv[2];
		if (str.empty())
		{
			std::cout << RED << "Wrong Input" << RESET << std::endl;
			std::cout << "The string to be replaced can't be empty" << std::endl;
		}
		else
			ft_executing(argv[1], argv[2], argv[3]);
	}
	else
	{
		std::cout << RED << "Wrong Input" << RESET << std::endl;
		std::cout << "Please try: ./replace " L_BLUE << "<" RESET 
		<< "filename" << L_BLUE "> <" << RESET << "string_to_replace" 
		<< L_BLUE << "> <" RESET << "string_to_replace_with" << L_BLUE 
		<< ">" << RESET << std::endl;
	}
	return 0;
}
