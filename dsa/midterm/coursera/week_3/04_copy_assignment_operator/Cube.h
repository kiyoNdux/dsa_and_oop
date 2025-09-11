#pragma once

namespace uiuc {
    class Cube {
        public:
            Cube();                              // Default constructor
            Cube(const Cube & obj);              // Copy constructor
            Cube & operator=(const Cube & obj);  // Copy assignment operator

            double getVolume();
            double getSurfaceArea();
            void setLength(double length);

        private:
            double length_;
    };
}
