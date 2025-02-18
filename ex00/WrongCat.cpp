#include "WrongCat.hpp"

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

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
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
