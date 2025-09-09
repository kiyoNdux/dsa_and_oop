#pragma once

namespace uiuc{
    class Cube{
        public:
            Cube(); // Custom Default Constructor
            Cube(double length); // One argument Constructor

            double getVolume();
            double setSurfaceArea();
            void setLength(double length);

        private:
            double length_;

    };
}
