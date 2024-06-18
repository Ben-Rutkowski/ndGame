#include <iostream>
#include "test.hpp"

Debug::Debug() {
    std::cout << "Creating Debug" << std::endl;
}

Debug::~Debug() {
    std::cout << "Destroying Debug" << std::endl;
}

void Debug::print() {
    std::cout << "DEBUG from test case" << std::endl;
}
