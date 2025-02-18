#include "MateriaSource.hpp"

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

MateriaSource::MateriaSource() : _materiasCount(0) {
    // std::cout << "MateriaSource " << color::cyan << "default constructor"
    //     << color::reset << " called" << std::endl;
    for (std::size_t i = 0; i < _materiasMax; i++) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
        : _materiasCount(other._materiasCount) {
    // std::cout << "MateriaSource " << color::cyan << "copy constructor"
    //     << color::reset << " called" << std::endl;
    for (std::size_t i = 0; i < _materiasCount; i++) {
        _materias[i] = other._materias[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        _materiasCount = other._materiasCount;
        // std::cout << "MateriaSource " << color::cyan
        //     << "assignation operator" << color::reset
        //     << " called" << std::endl;
        for (std::size_t i = 0; i < _materiasCount; i++) {
            delete _materias[i];
            _materias[i] = other._materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    // std::cout << "MateriaSource " << color::cyan << "destructor"
    //     << color::reset << " called" << std::endl;
    for (std::size_t i = 0; i < _materiasMax; i++) {
        delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (!m) {
        return;
    }
    if (_materiasCount < _materiasMax) {
        _materias[_materiasCount] = m;
        _materiasCount++;
    }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (std::size_t i = 0; i < _materiasCount; i++) {
        if (_materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
    return NULL;
}
