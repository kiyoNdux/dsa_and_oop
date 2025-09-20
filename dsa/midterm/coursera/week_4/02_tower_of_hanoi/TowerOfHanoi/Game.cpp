#include "Game.h"
#include "Stack.h"
#include "Cube.h"
#include "HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

void Game::solve() {
    cout << *this << endl;

    //@TODO -- Finish solving the game!
}

Game::Game() {
    // Create the three empty stacks
    for (int i = 0; i < 3; i++) {
        Stack stackOfCubes;
        stacks_.push_back(stackOfCubes);
    }

    // Create the four cubes, placing each on the [0]th stack
    uiuc::Cube blue(4, uiuc::HSLAPixel::BLUE());
    stacks_[0].push_back(blue);

    uiuc::Cube orange(3, uiuc::HSLAPixel::ORANGE());
    stacks_[0].push_back(orange);

    uiuc::Cube purple(2, uiuc::HSLAPixel::PURPLE());
    stacks_[0].push_back(purple);

    uiuc::Cube yellow(1, uiuc::HSLAPixel::YELLOW());
    stacks_[0].push_back(yellow);
}
