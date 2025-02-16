#pragma once

#include <string>

namespace color {
    const std::string red = "\033[1;31m";
    const std::string green = "\033[1;32m";
    const std::string yellow = "\033[1;33m";
    const std::string blue = "\033[1;34m";
    const std::string magenta = "\033[1;35m";
    const std::string cyan = "\033[1;36m";
    const std::string reset = "\033[0m";
}

class Animal {
 public:
    Animal();
    Animal(const Animal &other);
    Animal(const std::string &type);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const;
    const std::string &getType() const;

 protected:
    std::string _type;
};