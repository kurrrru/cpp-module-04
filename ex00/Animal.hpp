#pragma once

#include <string>

class Animal {
 public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	~Animal();

	void makeSound() const;
	std::string getType() const;

 protected:
	std::string _type;
};