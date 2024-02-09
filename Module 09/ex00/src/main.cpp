#include "../header/BitcoinExchange.hpp"

// Checks if both files (data.csv & input file) are valid. (can be opend, not empty, exist)
void openFiles(const char *inputFilename, const std::string& bitcoinDataFilename) 
{
	BitcoinDB bitcoinDB;

	// Check if the input file is opened successfully and exists
	// NOTE: file must be in the root directory.
	std::ifstream inputFile(inputFilename);
	if (!inputFile.is_open())
		throw std::runtime_error("Could not open file.");

	// Check if 'data.csv' is opened successfully and exists
	// NOTE: file must be in the root directory.
	std::ifstream bitcoinDataFile(bitcoinDataFilename);
	if (!bitcoinDataFile.is_open())
		throw std::runtime_error("Could not open data.csv file.");

	// Check if input file is empty
	inputFile.seekg(0, std::ios::end);
	if (inputFile.tellg() == 0)
		throw std::runtime_error("Input file is empty.");
	inputFile.seekg(0, std::ios::beg);		// Move back to the beginning of the file

	// Check if 'data.csv' file is empty
	bitcoinDataFile.seekg(0, std::ios::end);
	if (bitcoinDataFile.tellg() == 0)
		throw std::runtime_error("'data.csv' file is empty.");
	bitcoinDataFile.seekg(0, std::ios::beg);	 // Move back to the beginning of the file

	// Skip the first line 'date | value'
	std::string firstLine;
	if (!std::getline(inputFile, firstLine) || firstLine != "date | value")
		throw std::runtime_error("Input file invalid format: First line 'data | value'."); // firstLine must be 'date | value'

	// Loop through the file using getline
	std::string line;
	while (std::getline(inputFile, line))
		bitcoinDB.processInputLine(line, bitcoinDataFile);

	// Close file 
	// this is not strictly necessary as the ifstream will close itself when it goes out of scope
	inputFile.close();
	bitcoinDataFile.close();
}

// Checks if agruments are correct and opends + executes program
int	main(int argc, char **argv) 
{
	// Check for correct argument count
	if (argc != 2)
	{
		std::cerr << RED << "Error:" << RESET << " One file is required" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Getting/assigning files
	const char *inputFilename = argv[1];
	std::string bitcoinDataFilename = "data.csv";

	// Try/catch if something goes wrong while opening the files.
	try {
		openFiles(inputFilename, bitcoinDataFilename);
	} catch (const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return 0;
}
