/**
 * @file HSLAPixel.h
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#pragma once

#include <iostream>
#include <sstream>

namespace uiuc {
    class HSLAPixel {
    public:
        double h; // hue (0–360)
        double s; // saturation (0.0–1.0)
        double l; // luminance (0.0–1.0)
        double a; // alpha (0.0–1.0)
    };
}
