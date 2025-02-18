#include "Ice.hpp"

#include <iomanip>
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
        const std::string light_cyan = "\033[1;96m";
        const std::string reset = "\033[0m";
    }
}

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice " << color::cyan << _type
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
    std::cout << "Ice " << color::cyan << _type
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
    if (this != &other) {
        AMateria::operator=(other);
        std::cout << "Ice " << color::cyan << _type
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
    }
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice " << color::cyan << _type
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
}

AMateria *Ice::clone() const {
    std::cout << "Ice " << color::cyan << _type
        << color::reset << color::blue << " clone"
        << color::reset << " called" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << color::light_cyan << target.getName()
        << color::reset << " *" << std::endl;
}
