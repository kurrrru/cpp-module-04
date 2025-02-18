#include "Cat.hpp"

#include <iostream>
#include <string>

namespace {
    namespace color {
        const std::string red = "\033[1;31m";
        const std::string green = "\033[1;32m";
        const std::string yellow = "\033[1;33m";
        const std::string blue = "\033[1;34m";
        const std::string magenta = "\033[1;35m";
        const std::string cyan = "\033[1;36m";
        const std::string reset = "\033[0m";
    }
}

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Cat " << color::cyan << _type
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "Cat " << color::cyan << _type
        << color::reset << " says: Meow meow" << std::endl;
}
