#pragma once

#include <string>

class Brain {
 private:
    static const int IDEAS = 100;

 public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

 private:
    std::string _ideas[IDEAS];
};
