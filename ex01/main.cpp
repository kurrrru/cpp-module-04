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
    Cat* cat2 = new Cat(*cat);
    cat2->makeSound();
    *cat2 = *cat;
    Cat cat3;
    cat3 = *cat;
    cat3.makeSound();
    delete cat;
    delete cat2;
    return 0;
}
