#include "Cube.h"

namespace uiuc{
    Cube::Cube() {
        length_ = 1;
    }

    double Cube::getVolume() {
        return length_ * length_ * length_;
    }
}
