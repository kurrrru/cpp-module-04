#include "Cat.hpp"

#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Cat " << color::cyan << _type
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << " says: Meow meow" << std::endl;
}
