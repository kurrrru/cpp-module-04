#pragma once

#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
    Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    Character(const std::string& name);

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

 private:
    static const std::size_t _materiasMax = 4;
    std::string _name;
    AMateria* _materias[_materiasMax];
    std::size_t _materiasCount;
};
