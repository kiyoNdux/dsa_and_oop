#include "Cube.h"
#include <iostream>

namespace uiuc {
    Cube::Cube(double length) {
        length_ = length;
        std::cout << "One-argument constructor invoked!" << std::endl;
    }

    Cube::Cube(const Cube & obj) {
        length_ = obj.length_;
        std::cout << "Copy constructor invoked!" << std::endl;
    }

    // (Optional, but if declared in Cube.h, you must define them)
    double Cube::getVolume() {
        return length_ * length_ * length_;
    }

    double Cube::getSurfaceArea() {
        return 6 * length_ * length_;
    }

    void Cube::setLength(double length) {
        length_ = length;
    }
}
