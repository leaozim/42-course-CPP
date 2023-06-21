#include "Serializer.hpp"

int	main( void )
{
	Data		*data = new Data();
	uintptr_t	dataSerialize;
	Data		*dataDeserialize;

	std::cout << CYAN << "Original value maintained at Data: " << RES << *data << std::endl;
	dataSerialize = Serializer::serialize(data);
	std::cout << CYAN << "Value before cast from Data to uintptr_t: " << RES << dataSerialize << std::endl;
	dataDeserialize = Serializer::deserialize(dataSerialize);
	std::cout << CYAN << "Value after casting uintptr_t to Data: " << RES << *dataDeserialize << std::endl;
	delete data;
}