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

template <class T, class U> 
void	print_ideas(T &animal, U &animal2, std::string idea1, std::string idea2)
{
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
	std::cout << animal->getType() << "      = "
			  << animal 
			  << std::endl
			  << "Copy " << animal2->getType() << " = "
			  << animal2 << std::endl
			  << animal->getType() << "      = "
			  << animal->getBrain()->getIdeas(1) 
			  << std::endl 
			  << "Copy " << animal2->getType() << " = "
			  << animal2->getBrain()->getIdeas(1) 
			  << std::endl;
	animal->getBrain()->setIdeas(1, idea1);
	animal2->getBrain()->setIdeas(1, idea2);
	std::cout << animal->getType() << "      = "
			  << animal->getBrain()->getIdeas(1)
			  << std::endl
			  << "Copy " << animal2->getType() << " = "
			  << animal2->getBrain()->getIdeas(1) 
			  << std::endl;
}

int main()
{
	print_header("CONSTRUCTORS");
	// const AAnimal	*meta = instantiate_class<AAnimal>();
	const AAnimal	*j = instantiate_class<Dog>();
	const AAnimal	*i = instantiate_class<Cat>();
	const Cat		*cat;
	const Cat		*catCopy;
	const Dog		*dog;
	const Dog		*dogCopy;
	const AAnimal	*animals[5];

	cat = instantiate_class<Cat>();
	catCopy = new Cat(*cat);
	dog = instantiate_class<Dog>();
	dogCopy = new Dog(*dog);
	print_header("ARRAY OF ANIMALS");
	{
		for (int i = 0; i < 5; i++)
			animals[i] = instantiate_class<Dog>();

	}
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
	print_header("DESTRUCTORS");
	for (int i = 0; i < 5; i++)
		delete_class(animals[i]);
	delete_class(cat);
	delete_class(catCopy);
	delete_class(dog);
	delete_class(dogCopy);
	delete_class(j);
	delete_class(i);
	return (0);
}
