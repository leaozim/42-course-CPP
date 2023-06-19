#include "Serializer.hpp"

int	main( void )
{
	Data		*data = new Data();
	uintptr_t	dataSerialize;
	Data		*dataDeserialize;

	std::cout << *data << std::endl;
	dataSerialize = Serializer::serialize(data);
	std::cout << dataSerialize << std::endl;
	dataDeserialize = Serializer::deserialize(dataSerialize);
	std::cout << *dataDeserialize << std::endl;
}