#pragma once

namespace uiuc {
    class Cube {
        public:
            Cube();                       // Default constructor
            Cube(const Cube & obj);       // Copy constructor

        private:
            double length_;
    };
}
