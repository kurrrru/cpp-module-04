#include "WrongCat.hpp"

#include <iostream>
#include <string>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        std::cout << "WrongCat " << color::cyan << _type
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat " << color::cyan << _type
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat " << color::cyan << _type
        << color::reset << " says: Meow meow" << std::endl;
}
