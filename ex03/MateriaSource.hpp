#pragma once

#include <string>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
 public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(const std::string& type);

 private:
    static const std::size_t _materiasMax = 4;
    AMateria* _materias[4];
    std::size_t _materiasCount;
};
