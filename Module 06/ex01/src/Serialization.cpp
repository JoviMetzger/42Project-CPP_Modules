#include "../header/Serialization.hpp"

// Static methods
// Data to uintptr_t
uintptr_t	Serializer::serialize(Data* ptr)
{
	// std::cout << "Serialize: " << reinterpret_cast<uintptr_t>(ptr) << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Uintptr_t to data
Data*	Serializer::deserialize(uintptr_t raw)
{
	// std::cout << "Deserialize: " << reinterpret_cast<Data*>(raw) << std::endl;
	return (reinterpret_cast<Data*>(raw));
}
