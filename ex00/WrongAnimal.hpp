#pragma once

#include <string>

class WrongAnimal {
 public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal(const std::string& type);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;

 protected:
    std::string _type;
};
