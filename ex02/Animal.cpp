#include "Animal.hpp"

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

Animal::Animal() : _type("default") {
    std::cout << "Animal " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "Animal " << color::cyan << _type
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
    }
    return *this;
}

Animal::Animal(const std::string &type) : _type(type) {
    std::cout << "Animal " << color::cyan << _type
        << color::reset << color::blue << " type constructor"
        << color::reset << " called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal " << color::cyan << _type
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal " << color::cyan << _type
        << color::reset << " says: ..." << std::endl;
}

const std::string &Animal::getType() const {
    return _type;
}
