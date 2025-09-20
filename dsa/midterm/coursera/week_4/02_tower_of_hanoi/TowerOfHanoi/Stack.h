#pragma once
#include <vector>
#include <ostream>
#include "Cube.h"

class Stack {
public:
    void push_back(const uiuc::Cube & cube);
    uiuc::Cube removeTop();
    uiuc::Cube & peekTop();
    unsigned size() const;

    friend std::ostream& operator<<(std::ostream & os,
                                    const Stack & stack);

private:
    std::vector<uiuc::Cube> cubes_;  // added semicolon + member name
};
