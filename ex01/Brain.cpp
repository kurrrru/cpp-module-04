#include "Brain.hpp"

#include <iomanip>
#include <iostream>
#include <string>

namespace {
	namespace color {
		const std::string red = "\033[1;31m";
		const std::string green = "\033[1;32m";
		const std::string yellow = "\033[1;33m";
		const std::string blue = "\033[1;34m";
		const std::string magenta = "\033[1;35m";
		const std::string cyan = "\033[1;36m";
		const std::string reset = "\033[0m";
	}
}

Brain::Brain() {
	std::cout << "Brain " << color::green << "default constructor"
		<< color::reset << " called" << std::endl;
	for (int i = 0; i < Brain::IDEAS; i++) {
		_ideas[i] = "default";
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain " << color::yellow << "copy constructor"
		<< color::reset << " called" << std::endl;
	for (int i = 0; i < Brain::IDEAS; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		std::cout << "Brain " << color::magenta << "assignation operator"
			<< color::reset << " called" << std::endl;
		for (int i = 0; i < Brain::IDEAS; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain " << color::red << "destructor"
		<< color::reset << " called" << std::endl;
}
