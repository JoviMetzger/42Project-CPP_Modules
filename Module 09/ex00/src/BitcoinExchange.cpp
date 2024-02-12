#include "../header/BitcoinExchange.hpp"

// Default Constructor
BitcoinDB::BitcoinDB()
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
BitcoinDB::~BitcoinDB()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
BitcoinDB::BitcoinDB(const BitcoinDB& value)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
BitcoinDB	&BitcoinDB::operator=(const BitcoinDB& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_bitcoinPrice = value._bitcoinPrice;
	}
	return *this;
}

//------------------------------------------------------------------------------
// -- Member function --
// Processes the input file, checks if file input is correct and does the calculations 
void BitcoinDB::processInputLine(std::string line, std::ifstream& bitcoinDataFile)
{
	std::istringstream inputStream(line);	// converts line(string) to a stream input for getline
	std::string date;			// Stores the 'date' of the string 
	std::string value;			// Stores the 'value' of the string

	// Splits line into date and value using getline
	if (std::getline(inputStream, date, '|') && std::getline(inputStream, value, '|'))
	{
		// Trim whitespace at position 0 from value ('| 3" -> "|3")
		value.erase(0, value.find_first_not_of(" \n\r\t"));

		// Checks if the 'date' and 'value' are valid valid 
		if (!dateCheck(date, line) || !valueCheck(value)) 
			return ;
		calculateBitcoinPrice(date, value, bitcoinDataFile); // Does the calculation of the Bitcoin price (data.csv)
	}
	else 
		std::cerr << RED << "Error: " << RESET << "bad input => " << line << std::endl;
}

// ---------------------------------------------------------------------------------------

// ----------------------------------- DATE CHECK ----------------------------------------
// Checks if all characters are digits
static bool checkOnlyDigits(std::string year, std::string month, std::string day)
{
	// Combine all strings into one
	std::string combined = year + month + day;

	// Check if all characters in the combined string are digits
	for (char c : combined)
	{
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

// Checks if year, month and day are valid
static bool yearMonthDay(std::string date)
{
	// Extract substrings for year, month, and day
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	// Checking if year, month, day only have digits
	if (!checkOnlyDigits(year, month, day))
		return false;

	// Checking year
	int intYear = stoi(year);
	if (intYear < 2009 || intYear > 2025)
		return false;

	// Checking month
	int intMonth = stoi(month);
	if (intMonth < 1 || intMonth > 12)
		return false;

	// Checking day
	int intDay = stoi(day);
	switch (intMonth)
	{
		// Months with 31 days
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (intDay < 1 || intDay > 31)
				return false;

		// Months with 30 days
		case 4: case 6: case 9: case 11:
			if (intDay < 1 || intDay > 30)
				return false;

		// February - Without leap years
		case 2:
			if (intDay < 1 || intDay > 29)
				return false;
	}
	return true;
}

// Checks if the date is correct including the correct formart
bool BitcoinDB::dateCheck(std::string date, std::string line)
{
	// Check if date has the correct format 'Year-Month-Day'
	if (date.length() != 11 || date[4] != '-' || date[7] != '-' || !yearMonthDay(date)) 
	{
		std::cerr << RED << "Error: " << RESET << "bad input => " << line << std::endl;
		return false;
	}
	return true;
}
// ---------------------------------------------------------------------------------------

// ----------------------------------- VALUE CHECK ---------------------------------------
// Checks if double is correct (NOT: 2. or 2.2.0 or 2a.0)
static bool checkDoubelValue(std::string value)
{
	if (value[0] == '-')
	{
		// If input is negative, remove '-' and do all checks
		std::string positive_value = value.substr(1);
		return checkDoubelValue(positive_value);
	}
	else
	{
		// If first character is '.'
		if (value[0] == '.')
			return false;

		for (size_t i = 0; i < value.size(); i++)
		{
			// If there is no chararcter after '.'
			if (value[i] == '.')
			{
				if (!isprint(value[i + 1]))
					return false;
			}

			// Checking if all character before '.' are digits
			size_t j = 0;
			while (value[j] != '.')
			{
				if (!isdigit(value[j]))
					return false;
				j++;
			}

			// Checking if all characters after '.' are digits
			size_t k = value.find('.') + 1;
			while (k < value.size())
			{
				if (!isdigit(value[k]))
					return false;
				k++;
			}
		}
	}
	return true;
}

// Checks if the value is correct (NOT: 5 6 or -1 or 23b or <MAX_INT)
bool BitcoinDB::valueCheck(std::string value)
{
	// Check if the value is one number (no whitspace in between
	for (char currentPos : value)
	{
		if (std::isspace(currentPos))
		{
			std::cerr << RED << "Error: " << RESET << "The value is not valid." << std::endl;
			return false;
		}
	}

	// Checking if every character is a digit
	if (value.find('.') != std::string::npos)
	{
		if (!checkDoubelValue(value))
		{
			std::cerr << RED << "Error: " << RESET << "The value is not valid." << std::endl;
			return false;
		}
	}
	else
	{
		if (value[0] == '-')
		{
			const char *charValue = value.c_str();
			for (int i = 1; charValue[i] != '\0'; i++)
			{
				if (!std::isdigit(charValue[i]))
				{
					std::cerr << RED << "Error: " << RESET << "The value is not valid." << std::endl;
					return false;
				}
			}
		}
		else
		{
			for (char charValue : value)
			{
				if (!std::isdigit(charValue))
				{
					std::cerr << RED << "Error: " << RESET << "The value is not valid." << std::endl;
					return false;
				}
			}
		}
   	 }

	// Convert value to a double and check if the value is between 0 and 1000
	double doubleValue;
	std::istringstream(value) >> doubleValue;

	if (doubleValue < 0)
	{
		std::cerr << RED << "Error: " << RESET << "not a positive number." << std::endl;
		return false;
	} 
	else if (doubleValue > 1000)
	{
		std::cerr << RED << "Error: " << RESET << "too large a number." << std::endl;
		return false;
	}
	return true;
}
// ---------------------------------------------------------------------------------------

// ----------------------------------- CALCULATIONS --------------------------------------
// Searches for the closest date in the _bitcoinPrice map 
double BitcoinDB::getBitcoinPrice(std::string &date)
{
	// Find the iterator pointing to the first element with a key not less than 'date'
	std::map<std::string, double>::iterator it = _bitcoinPrice.lower_bound(date);

	// If 'it' is not pointing to the first element and the key is not equal to 'date'
	if (it != _bitcoinPrice.begin() && it->first != date)
		it--;
	return (it->second); // Return the bitcoin price associated with the closest date
}

// Calculates the value multiplied by the exchange rate according to the date indicated in your database.
void BitcoinDB::calculateBitcoinPrice(std::string date, std::string value, std::ifstream& bitcoinDataFile)
{
	// Convert value to a double
	double doubleValue;
	std::istringstream(value) >> doubleValue;

	std::string line;
	bool firstLineSkip = false; // Skip the first line
	// It extracts the date and price from the current line and inserts them into the _bitcoinPrice map
	while (getline(bitcoinDataFile, line))
	{
		if (firstLineSkip)
			_bitcoinPrice.insert(std::pair<std::string, double>(line.substr(0, line.find(',')), std::stod(line.substr(line.find(',') + 1, line.length()))));
		else
			firstLineSkip = true;
	}

	// Calculate output
	double result = doubleValue * getBitcoinPrice(date);

	// Print the output
	std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
}
