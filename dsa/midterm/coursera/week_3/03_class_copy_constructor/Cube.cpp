#include "Cube.h"
#include <iostream>

namespace uiuc {
    Cube::Cube() {
        length_ = 1;
        std::cout << "Default constructor invoked!" << std::endl;
    }

    Cube::Cube(const Cube & obj) {
        length_ = obj.length_;
        std::cout << "Copy constructor invoked!" << std::endl;
    }
}
