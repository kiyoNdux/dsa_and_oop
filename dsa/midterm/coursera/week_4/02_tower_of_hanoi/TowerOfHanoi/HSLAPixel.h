#pragma once

namespace uiuc {
    class HSLAPixel {
    public:
        double h, s, l, a; // hue, saturation, lightness, alpha

        HSLAPixel(double hue = 0, double sat = 0, double light = 0, double alpha = 1.0)
            : h(hue), s(sat), l(light), a(alpha) {}

        // Some convenience colors
        static HSLAPixel BLUE()   { return HSLAPixel(240, 1, 0.5); }
        static HSLAPixel ORANGE() { return HSLAPixel(30, 1, 0.5); }
        static HSLAPixel PURPLE() { return HSLAPixel(270, 1, 0.5); }
        static HSLAPixel YELLOW() { return HSLAPixel(60, 1, 0.5); }
    };
}
