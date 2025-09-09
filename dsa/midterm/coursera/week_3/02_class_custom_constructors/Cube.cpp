    #include "Cube.h"

namespace uiuc{
    Cube::Cube() {
        length_ = 1;
    }

    Cube::Cube(double length) {
        length_ = length;
    }

    double Cube::getVolume() {
        return length_ * length_ * length_;
    }
}
