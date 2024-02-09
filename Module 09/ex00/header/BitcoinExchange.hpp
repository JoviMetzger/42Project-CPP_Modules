#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <map>

// COLORS
# define BLUE "\e[1;34m"
# define RED "\e[1;91m"
# define RESET "\033[0m"

class	BitcoinDB
{
	private:
		std::map<std::string, double> _bitcoinPrice;
	public:
		BitcoinDB();					// Default constructor
		BitcoinDB(const BitcoinDB& value);		// Copy constructor
		BitcoinDB& operator=(const BitcoinDB& value);	// Copy assignment operator
		~BitcoinDB();					// Destructor

		// Member functions
		void	processInputLine(std::string line, std::ifstream& bitcoinDataFile);
		double	getBitcoinPrice(std::string &date);
		void	calculateBitcoinPrice(std::string date, std::string value, std::ifstream& bitcoinDataFile);
		bool	dateCheck(std::string date, std::string line);
		bool	valueCheck(std::string value);

};


#endif
