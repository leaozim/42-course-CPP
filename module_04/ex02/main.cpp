#include   "AAnimal.hpp"
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

void print_song( std::string str, int id )
{
	if (id == 1)
		std::cout << GREY << "This sound is the sound of the: "<< str << RES << std::endl;
	else
		std::cout << GREY << "This sound is the sound of the unknown: " << str << RES << std::endl;
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
}

template <class T> 
void	delete_class( T class_to_delete ){
	delete class_to_delete;
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
}

template <class T>
const T* instantiate_class( void ) {
	const T* new_class = new T();
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
	return new_class;
}

template <class T, class U> 
void	print_ideas( T &animal, U &animalCopy, std::string idea1, std::string idea2 )
{
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
	std::cout << animal->getType() << "      = "
			  << animal 
			  << std::endl
			  << "Copy " << animalCopy->getType() << " = "
			  << animalCopy << std::endl
			  << animal->getType() << "      = "
			  << animal->getBrain()->getIdeas(1) 
			  << std::endl 
			  << "Copy " << animalCopy->getType() << " = "
			  << animalCopy->getBrain()->getIdeas(1) 
			  << std::endl;
	animal->getBrain()->setIdeas(1, idea1);
	animalCopy->getBrain()->setIdeas(1, idea2);
	std::cout << animal->getType() << "      = "
			  << animal->getBrain()->getIdeas(1)
			  << std::endl
			  << "Copy " << animalCopy->getType() << " = "
			  << animalCopy->getBrain()->getIdeas(1) 
			  << std::endl;
}

int main()
{
	print_header("CONSTRUCTORS");
	// const AAnimal		*meta = new AAnimal(); commented to not give error :x
	const AAnimal		*j = instantiate_class<Dog>();
	const AAnimal		*i = instantiate_class<Cat>();
	const WrongAnimal	*wrongAnimal = instantiate_class<WrongAnimal>();
	const WrongAnimal	*wrongCat = instantiate_class<WrongCat>();

	const Cat			*cat;
	const Cat			*catCopy;
	cat = instantiate_class<Cat>();
	catCopy = new Cat(*cat);
	
	const Dog			*dog;
	const Dog			*dogCopy;
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
	dog = instantiate_class<Dog>();
	dogCopy = new Dog(*dog);

	print_header("COPY CAT AND DOG");
	{
		print_ideas(
			cat,
			catCopy,
			"We cats will purr as we watch the downfall of human foolishness.", 
			"Humans are insolent worms."
		);
		print_ideas(
			dog,
			dogCopy,
			"Squirrel!",
			"My name is Dug. I just met you but I adore you now."
		);
	}
	print_header("LITTLE BIRD, WHAT SOUND, WHAT SOUND IS THIS? WHO KNOWS ITS NAME?");
	{
		i->makeSound();
		print_song(i->getType(), 1);
		j->makeSound();
		print_song(j->getType(), 1);
	}
	{
		wrongAnimal->makeSound();
		print_song(wrongAnimal->getType(), 2);
		wrongCat->makeSound();
		print_song(wrongCat->getType(), 2);
	}
	print_header("DESTRUCTORS");

	delete_class(cat);
	delete_class(catCopy);
	delete_class(dog);
	delete_class(dogCopy);
	delete_class(j);
	delete_class(i);
	delete_class (wrongCat);
	delete_class(wrongAnimal);
	// delete_class(meta);
	return (0);
}
