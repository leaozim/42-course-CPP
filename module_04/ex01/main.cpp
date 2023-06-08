#include   "Animal.hpp"
#include  "Dog.hpp"
#include  "Cat.hpp"
#include  "WrongAnimal.hpp"
#include  "WrongCat.hpp"


static void printHeader(std::string str)
{
    std::cout << "============================================================\n"
              << str
              << "\n============================================================\n";
}

int main(void)
{
    const int amount = 4;
    const int half = amount / 2;

    printHeader("Constructors");
    const Animal *animals[amount];

    for (int i = 0; i < half; i++)
    {
        animals[i] = new Dog();
        animals[i + half] = new Cat();
    }

    printHeader("Make sound");
    for (int i = 0; i < half; i++)
    {
        animals[i]->makeSound();
        animals[i + half]->makeSound();
    }

    printHeader("Get type");
    for (int i = 0; i < half; i++)
    {
        std::cout << "Type: " << animals[i]->getType() << '\n';
        std::cout << "Type: " << animals[i + half]->getType() << '\n';
    }

    printHeader("Get brain");
    for (int i = 0; i < half; i++)
    {
        std::cout << "Dog brain: " << *dynamic_cast<Dog const *>(animals[i])->getBrain() << '\n';
        std::cout << "Cat brain: " << *dynamic_cast<Cat const *>(animals[i + half])->getBrain() << '\n';
    }

    printHeader("Copy constructors");
    const Animal *copyAnimals[amount];
    for (int i = 0; i < half; i++)
    {
        copyAnimals[i] = new Dog(dynamic_cast<Dog const &>(*animals[i]));
        copyAnimals[i + half] = new Cat(dynamic_cast<Cat const &>(*animals[i + half]));
    }

    printHeader("Copy make sound");
    for (int i = 0; i < half; i++)
    {
        copyAnimals[i]->makeSound();
        copyAnimals[i + half]->makeSound();
    }

    printHeader("Copy get type");

    for (int i = 0; i < half; i++)
    {
        std::cout << "Copy type: " << copyAnimals[i]->getType() << '\n';
        std::cout << "Copy type: " << copyAnimals[i + half]->getType() << '\n';
    }

    printHeader("Copy get brain");
    for (int i = 0; i < half; i++)
    {
        std::cout << "Copy dog brain: " << *dynamic_cast<Dog const *>(copyAnimals[i])->getBrain() << '\n';
        std::cout << "Copy cat brain: " << *dynamic_cast<Cat const *>(copyAnimals[i + half])->getBrain() << '\n';
    }

    printHeader("Destructors");
    for (int i = 0; i < amount; i++)
    {
        delete animals[i];
        delete copyAnimals[i];
    }

    return 0;
}