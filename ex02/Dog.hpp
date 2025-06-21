#pragma once

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    void makeSound() const;

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;

 private:
    Brain* _brain;
};
