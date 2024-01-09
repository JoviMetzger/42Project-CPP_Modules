#include "../header/Serialization.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"


// Convert pointers to unsigned integers and vice versa
int	main(void)
{
	// Create a Data object
	Data	myData("my data");

	// Serialize the address of the Data object
	uintptr_t	serializedPtr = Serializer::serialize(&myData);

	// Deserialize the serialized pointer
	Data	*deserializedPtr = Serializer::deserialize(serializedPtr);
	
	// Comparing adresse and value
	std::cout << BLUE << " ----- Adresses Compared -----" << RESET << std::endl;
	std::cout << "MyData address: "<< &myData << std::endl;
	std::cout << "Deserialized address: "<< deserializedPtr << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << BLUE << " ----- Values of the data -----" << RESET << std::endl;
	std::cout << "myData value: " << myData.getDataValue() << std::endl;
	std::cout << "Deserialized value: " << (*deserializedPtr).getDataValue() << std::endl;
	std::cout << std::endl << std::endl;

	// Check if deserialized pointer is equal to the original pointer
	if (deserializedPtr == &myData)
		std::cout << "Serialization and deserialization successful! Pointers match." << std::endl;
	else
		std::cout << "Pointers don't match. Serialization or deserialization failed." << std::endl;
	return (0);
}
