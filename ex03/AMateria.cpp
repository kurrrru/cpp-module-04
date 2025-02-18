#include "AMateria.hpp"

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

AMateria::AMateria() : _type("default") {
    // std::cout << "AMateria " << color::cyan << _type
    //     << color::reset << color::green << " default constructor"
    //     << color::reset << " called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
    // std::cout << "AMateria " << color::cyan << _type
    //     << color::reset << color::yellow << " copy constructor"
    //     << color::reset << " called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        _type = other._type;
        // std::cout << "AMateria " << color::cyan << _type
        //     << color::reset << color::magenta << " assignation operator"
        //     << color::reset << " called" << std::endl;
    }
    return *this;
}

AMateria::AMateria(const std::string &type) : _type(type) {
    // std::cout << "AMateria " << color::cyan << _type
    //     << color::reset << color::blue << " type constructor"
    //     << color::reset << " called" << std::endl;
}

AMateria::~AMateria() {
    // std::cout << "AMateria " << color::cyan << _type
    //     << color::reset << color::red << " destructor"
    //     << color::reset << " called" << std::endl;
}

const std::string &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "* uses " << color::yellow << _type
        << color::reset << " on " << color::light_cyan << target.getName()
        << color::reset << " *" << std::endl;
}

