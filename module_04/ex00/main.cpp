#include   "Animal.hpp"
#include  "Dog.hpp"
#include  "Cat.hpp"
#include  "WrongAnimal.hpp"
#include  "WrongCat.hpp"

static void print_header( std::string str )
{
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BLUE << str  << RES;
	if(str.size() == 64)
		std::cout << BLUE << " \u266B \u266C \u266B" << RES;
	std::cout << std::endl;
	std::cout << std::string(70, '=') << std::endl;
}

 void print_song( std::string str, int id)
{
	if (id == 1)
		std::cout << GREY << "This sound is the sound of the: "<< str << RES << std::endl;
	else
		std::cout << GREY << "This sound is the sound of the unknown: " << str << RES << std::endl;
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
}

template <class T> 
void	delete_class(T class_to_delete){
	delete class_to_delete;
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
}

template <class T>
const T* instantiate_class() {
	const T* new_class = new T();
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
	return new_class;
}

int main()
{
	print_header("CONSTRUCTORS");
	const Animal		*meta = instantiate_class<Animal>();
	const Animal		*j = instantiate_class<Dog>();
	const Animal		*i = instantiate_class<Cat>();
	const WrongAnimal	*wrongAnimal = instantiate_class<WrongAnimal>();
	const WrongAnimal	*wrongCat = instantiate_class<WrongCat>();

	print_header("LITTLE BIRD, WHAT SOUND, WHAT SOUND IS THIS? WHO KNOWS ITS NAME?");
	{
		i->makeSound();
		print_song(i->getType(), 1);
		j->makeSound();
		print_song(j->getType(), 1);
		meta->makeSound();
		print_song(meta->getType(), 1);
	}
	{
		wrongAnimal->makeSound();
		print_song(wrongAnimal->getType(), 2);
		wrongCat->makeSound();
		print_song(wrongCat->getType(), 2);
	}
	print_header("DESTRUCTORS");
	delete_class(j);
	delete_class(i);
	delete_class(meta);
	delete_class (wrongCat);
	delete_class(wrongAnimal);
	return (0);
}
