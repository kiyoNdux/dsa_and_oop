#pragma once

namespace uiuc {
    class Cube {
        public:
            Cube(double length);          // One-argument constructor
            Cube(const Cube & obj);       // Copy constructor

            double getVolume();
            double getSurfaceArea();
            void setLength(double length);

        private:
            double length_;
    };
}
