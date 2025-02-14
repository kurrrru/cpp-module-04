#pragma once

#include <string>

#include "Animal.hpp"

// namespace color {
//     const std::string red = "\033[1;31m";
//     const std::string green = "\033[1;32m";
//     const std::string yellow = "\033[1;33m";
//     const std::string blue = "\033[1;34m";
//     const std::string magenta = "\033[1;35m";
//     const std::string cyan = "\033[1;36m";
//     const std::string reset = "\033[0m";
// }

class WrongAnimal {
 public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal(const std::string &type);
    WrongAnimal &operator=(const WrongAnimal &other);
    ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;

 protected:
    std::string _type;
};
