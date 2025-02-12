#include "Dog.hpp"

#include <iostream>
#include <string>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog " << color::cyan << _type
		<< color::reset << color::green << " default constructor"
		<< color::reset << " called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog " << color::cyan << _type
		<< color::reset << color::yellow << " copy constructor"
		<< color::reset << " called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Dog " << color::cyan << _type
			<< color::reset << color::magenta << " assignation operator"
			<< color::reset << " called" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog " << color::cyan << _type
		<< color::reset << color::red << " destructor"
		<< color::reset << " called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog " << color::cyan << _type
		<< color::reset << " says: Woof woof" << std::endl;
}
