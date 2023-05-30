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

static void print_song( std::string str, int id)
{
	if (id == 1)
		std::cout << ORANGE << "This sound is the sound of the: "<< str << RES << std::endl;
	else
		std::cout << ORANGE << "This sound is the sound of the unknown: " << str << RES << std::endl;
	std::cout << GREY << std::string(70, '-') << RES << std::endl;

}

int main()
{
	print_header("CONSTRUCTORS");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	print_header("LITTLE BIRD, WHAT SOUND, WHAT SOUND IS THIS? WHO KNOWS ITS NAME?");
	{
		i->makeSound();
		print_song(i->getType(), 1);
		j->makeSound();
		print_song(j->getType(), 1);
		meta->makeSound();
		print_song(meta->getType(), 1);

	}
	// std::cout << GREY << std::string(70, '-') << RES << std::endl;
	{		
		wrongAnimal->makeSound();
		print_song(wrongAnimal->getType(), 2);
		wrongCat->makeSound();
		print_song(wrongCat->getType(), 2);
	}
	print_header("DESTRUCTORS");
	delete meta;
	delete j;
	delete i;
	delete wrongAnimal;
	delete wrongCat;
	return (0);
}