#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <cstdint>

// Data structure
struct	Data 
{
	std::string _dataValue;
	Data(std::string value)
	{
		_dataValue = value;
	}
	std::string getDataValue()
	{
		return (_dataValue);
	}
};

// Serializer class
class	Serializer
{
	private:
		// Private constructor to prevent instantiation
		Serializer();					// Default constructor
		Serializer(const Serializer& value);		// Copy constructor
		Serializer& operator=(const Serializer& value);	// Copy assignment operator
		~Serializer();					// Destructor
	public:
		// Static methods
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
