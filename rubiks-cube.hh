// Copyright (C) 2022 by Felix Drees | GNU GPLv2

#ifndef RUBIKS_CUBE_HH_
#define RUBIKS_CUBE_HH_

namespace rubikscube {

#include <string>
#include <map>

/**
 * Returns a string with all Values of the given Face of the Cube.
 * */
std::string printFace(std::array<std::array<int, 3>, 3> face);

/**
 * SOLVED_BOARD contains a list of all faces of a solved cube.
 * */
const std::array<std::array<std::array<int, 3>, 3>, 6> SOLVED_BOARD{};

/**
 * A class that represents a Rubik's Cube.
 * */
// class Cube;

/**
 * MANIPULATION_TO_INT contains all allowed manipulations and there corresponding id.
 * */
std::map<char, int> MANIPULATION_TO_INT;

/**
 * Returns a pointer to the current board of the cube.
 * */
// int* Cube::getBoard(void);

/**
 *
 * */
// std::ostream& operator<<(std::ostream& pOstream, Cube& c);

/**
 * Manipulate the Rubik's Cube Class with the given Cube notation.
 * For mor information about the notation refer to the README.md
 * */
// void Cube::manipulation(std::vector<std::string> const& instructions);

/**
 * Atomic cube manipulations.
 * */

// rotate the front face of the cube by 90⁰ clockwise
// void Cube::front(vodi);

// rotate the back face of the cube by 90⁰ counterclockwise
// void Cube::back(vodi);

// rotate the up face of the cube by 90⁰ clockwise
// void Cube::up(vodi);

// rotate the down face of the cube by 90⁰ clockwise
// void Cube::down(vodi);

// rotate the left face of the cube by 90⁰ clockwise
// void Cube::left(vodi);

// rotate the right face of the cube by 90⁰ clockwise
// void Cube::right(vodi);

}  // namespace rubikscube

#endif  // RUBIKS_CUBE_HH_
