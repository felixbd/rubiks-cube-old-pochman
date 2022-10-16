// Copyright (C) 2022 by Felix Drees | GNU GPLv2
// Created by felix on 12.10.22.
//


#include <array>
#include <vector>
#include <iostream>
#include <string>

#include "./main.hh"
#include "./rubiks-cube.hh"

int main() {
    // create a cube obj
    rubikscube::Cube abc = rubikscube::Cube();

    // printing out the current element at a given point
    std::cout
            << "the element at (4,2,1) is: "
            << abc.getBoardElement(4, 2, 1)
            << std::endl;

    // printing all elements
    std::cout << "\nprinting the board:\n\n" << abc << std::endl;

    // performing manipulations
    std::cout << "performing manipulations: U B2 B'\n" << std::endl;
    std::vector<std::string> testMan = {"U", "B2", "D'"};
    abc.manipulation(testMan);

    // printing all elements
    std::cout << "\nprinting the board:\n\n" << abc << std::endl;

    return 0;
}
