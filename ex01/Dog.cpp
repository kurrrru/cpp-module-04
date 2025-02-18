#include "Dog.hpp"

#include <iostream>
#include <string>

namespace {
namespace color {
const char red[] = "\033[1;31m";
const char green[] = "\033[1;32m";
const char yellow[] = "\033[1;33m";
const char blue[] = "\033[1;34m";
const char magenta[] = "\033[1;35m";
const char cyan[] = "\033[1;36m";
const char reset[] = "\033[0m";
}
}  // namespace

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Dog " << color::cyan << _type
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog " << color::cyan << _type
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    std::cout << "Dog " << color::cyan << _type
        << color::reset << " says: Woof woof" << std::endl;
}
