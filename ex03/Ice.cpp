#include "Ice.hpp"

#include <iomanip>
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
const char light_cyan[] = "\033[1;96m";
const char reset[] = "\033[0m";
}
}  // namespace

Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice " << color::cyan << _type
    //     << color::reset << color::green << " default constructor"
    //     << color::reset << " called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
    // std::cout << "Ice " << color::cyan << _type
    //     << color::reset << color::yellow << " copy constructor"
    //     << color::reset << " called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
    if (this != &other) {
        AMateria::operator=(other);
        // std::cout << "Ice " << color::cyan << _type
        //     << color::reset << color::magenta << " assignation operator"
        //     << color::reset << " called" << std::endl;
    }
    return *this;
}

Ice::~Ice() {
    // std::cout << "Ice " << color::cyan << _type
    //     << color::reset << color::red << " destructor"
    //     << color::reset << " called" << std::endl;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << color::light_cyan
        << target.getName() << color::reset << " *" << std::endl;
}
