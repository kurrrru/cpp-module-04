#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    {
        Animal** animals = new Animal*[6];
        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
                animals[i] = new Dog();
            } else {
                animals[i] = new Cat();
            }
        }
        for (int i = 0; i < 6; i++) {
            animals[i]->makeSound();
        }
        for (int i = 0; i < 6; i++) {
            delete animals[i];
        }
        delete[] animals;
    }

    Cat* cat = new Cat();
    cat->setIdea(0, "I want to chase a mouse");
    Cat* cat2 = new Cat(*cat);
    cat2->makeSound();
    *cat2 = *cat;
    Cat cat3;
    cat3.setIdea(0, "I want to sleep");
    std::cout << "Cat 1 idea: " << cat->getIdea(0) << std::endl;
    std::cout << "Cat 2 idea: " << cat2->getIdea(0) << std::endl;
    std::cout << "Cat 3 idea: " << cat3.getIdea(0) << std::endl;
    cat3 = *cat;
    cat2->setIdea(0, "I want to play with a ball");
    cat3.makeSound();
    std::cout << "Cat 1 idea: " << cat->getIdea(0) << std::endl;
    std::cout << "Cat 2 idea: " << cat2->getIdea(0) << std::endl;
    std::cout << "Cat 3 idea: " << cat3.getIdea(0) << std::endl;
    delete cat;
    delete cat2;
    return 0;
}
