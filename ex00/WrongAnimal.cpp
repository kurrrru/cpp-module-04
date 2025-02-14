#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : _type("default") {
    std::cout << "WrongAnimal " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
    std::cout << "WrongAnimal " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "WrongAnimal " << color::cyan << _type
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
    }
    return *this;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
    std::cout << "WrongAnimal " << color::cyan << _type
        << color::reset << color::blue << " type constructor"
        << color::reset << " called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal " << color::cyan << _type
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal " << color::cyan << _type
        << color::reset << " says: ..." << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}
