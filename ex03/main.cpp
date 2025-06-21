#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>
#include <stdexcept>

int main(void) {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(NULL);
    src->learnMateria(new Ice());
    src->learnMateria(NULL);
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob); // Invalid index, should not crash

    ICharacter* me_copy;
    try {
        const Character* character = dynamic_cast<const Character*>(me);
        me_copy = new Character(*character);
        me->equip(src->createMateria("ice"));
        me->use(2, *bob);
        me_copy->use(2, *bob); // Invalid index, should not crash
        delete me_copy;
    } catch (const std::exception& e) {
        std::cerr << "Failed to copy character: " << e.what() << std::endl;
        delete me;
        delete bob;
        delete src;
        return 1;
    }

    delete bob;
    delete me;
    delete src;
    return 0;
}
