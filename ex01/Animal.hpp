#pragma once

#include <string>

class Animal {
 public:
    Animal();
    Animal(const Animal &other);
    Animal(const std::string &type);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

 protected:
    std::string _type;
};