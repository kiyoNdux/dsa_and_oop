#pragma once

namespace uiuc{
    class Cube{
        public:
            Cube();

            double getVolume();
            double setSurfaceArea();
            void setLength(double length);

        private:
            double length_;

    };
}
