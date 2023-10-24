#include <iostream>
#include <fstream>
#include <string>

// COLORS
# define RED "\e[1;91m"
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

/* ft_replacing();
 *	- Read lines from an input stream (infile).
 *	- Search for occurrences of a specified text (old_str) within each line.
 *	- Replace all instances of old_str with a new text (new_str).
 *	- Write the modified lines to an output stream (outfile).
 *	- (match != std::string::npos) npos returns 'match' if it can't find it.
 */
void	ft_replacing(std::istream &infile, std::ostream &outfile, std::string old_str, std::string new_str)
{
	std::string	line;
	while (std::getline(infile, line))
	{
		size_t	pos = 0;
		while (1)
		{
			size_t	match_pos = line.find(old_str, pos);
			if (match_pos != std::string::npos)
			{
				line.replace(match_pos, old_str.length(), new_str);
				pos = match_pos + new_str.length();
			}
			else
				break ;	// No more matches in the current line
		}
		outfile << line << '\n';
	}
}

/* ft_executing();
 *	- Opens an input file (ifstream).
 *	- Creates an output file (ofstream).
 *		- ofstream/ifstream takes a const char*
 *		- convert the std::string to const char* with 'c_str'
 *	- Replacing strings ft_replacing().
 *	- Finally, it closes both the input and output files.
 */
void	ft_executing(const char* filename, std::string old_str, std::string new_str)
{
	std::ifstream	infile;		// Input File Stream
	std::ofstream	outfile;	// Output File Stream

	std::string	output_filename = std::string(filename) + ".replace";
	const char*	conv_outfilename = output_filename.c_str();	// Converts to const char*

	// Some Error checking
	if (old_str == new_str)
	{
		std::cout << RED << "Error: " << RESET << "Why do you want to replace a string with the sameone?!" << std::endl;
		return ;
	}

	// Opening infile
	infile.open(filename);
	if (!infile)
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return ;
	}

	// Opening outfile
	outfile.open(conv_outfilename);
	if (!outfile)
	{
		std::cout << RED "Error: " << RESET << "Unable to create file" << std::endl;
		infile.close();
		return ;
	}

	// Replacing strings
	ft_replacing(infile, outfile, old_str, new_str);

	// Closing files
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
