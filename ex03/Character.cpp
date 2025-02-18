#include "Character.hpp"

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
        const std::string reset = "\033[0m";
    }
}

Character::Character() : _name("default"), _materiasCount(0) {
    std::cout << "Character " << color::cyan << _name
        << color::reset << color::green << " default constructor"
        << color::reset << " called" << std::endl;
    for (std::size_t i = 0; i < _materiasMax; i++) {
        _materias[i] = NULL;
    }
}

Character::Character(const Character &other) : _name(other._name), _materiasCount(other._materiasCount) {
    std::cout << "Character " << color::cyan << _name
        << color::reset << color::yellow << " copy constructor"
        << color::reset << " called" << std::endl;
    for (std::size_t i = 0; i < _materiasMax; i++) {
        if (other._materias[i]) {
            _materias[i] = other._materias[i]->clone();
        } else {
            _materias[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other._name;
        _materiasCount = other._materiasCount;
        std::cout << "Character " << color::cyan << _name
            << color::reset << color::magenta << " assignation operator"
            << color::reset << " called" << std::endl;
        for (std::size_t i = 0; i < _materiasMax; i++) {
            delete _materias[i];
            if (other._materias[i]) {
                _materias[i] = other._materias[i]->clone();
            } else {
                _materias[i] = NULL;
            }
        }
    }
    return *this;
}

Character::Character(const std::string &name) : _name(name), _materiasCount(0) {
    std::cout << "Character " << color::cyan << _name
        << color::reset << color::blue << " type constructor"
        << color::reset << " called" << std::endl;
    for (std::size_t i = 0; i < _materiasMax; i++) {
        _materias[i] = NULL;
    }
}

Character::~Character() {
    std::cout << "Character " << color::cyan << _name
        << color::reset << color::red << " destructor"
        << color::reset << " called" << std::endl;
    for (std::size_t i = 0; i < _materiasMax; i++) {
        delete _materias[i];
    }
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    if (_materiasCount < _materiasMax) {
        _materias[_materiasCount] = m;
        _materiasCount++;
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < static_cast<int>(_materiasCount)) {
        delete _materias[idx];
        for (std::size_t i = idx; i < _materiasCount - 1; i++) {
            _materias[i] = _materias[i + 1];
        }
        _materias[_materiasCount - 1] = NULL;
        _materiasCount--;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < static_cast<int>(_materiasCount)) {
        _materias[idx]->use(target);
    }
}
