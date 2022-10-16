// Copyright (C) 2022 by Felix Drees | GNU GPLv2
// Created by felix on 12.10.22.
//

#ifndef RUBIKS_CUBE_HH_
#define RUBIKS_CUBE_HH_

#include <string>
#include <map>
#include <vector>

namespace rubikscube {

#define FACE std::array<std::array<int, 3>, 3>
#define BOARD std::array<std::array<std::array<int, 3>, 3>, 6>

/**
 * Returns a string with all Values of the given Face of the Cube.
 * */
std::string printFace(FACE face);

/**
 * Rotate 3x3 Matrix n-times by 90⁰ Clockwise.
 * */
FACE rotateMatrix(FACE a, int num);

/**
 * SOLVED_BOARD contains a list of all faces of a solved cube.
 * https://stackoverflow.com/a/62252088
 * >>Note the extra set of braces. It seems a bit odd but ...<<
 * */
const BOARD SOLVED_BOARD = {
        {
                {
                        {
                                {0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}
                        }
                },
                {
                        {
                                {1, 1, 1},
                                {1, 1, 1},
                                {1, 1, 1}
                        }
                },
                {
                        {
                                {2, 2, 2},
                                {2, 2, 2},
                                {2, 2, 2}
                        }
                },
                {
                        {
                                {3, 3, 3},
                                {3, 3, 3},
                                {3, 3, 3}
                        }
                },
                {
                        {
                                {4, 4, 4},
                                {4, 4, 4},
                                {4, 4, 4}
                        }
                },
                {
                        {
                                {5, 5, 5},
                                {5, 5, 5},
                                {5, 5, 5}
                        }
                }
        }
};

/**
 * MANIPULATION_TO_INT contains all allowed manipulations and there corresponding id.
 * */
const std::map<char, int> MANIPULATION_TO_INT = {
        {'F', 0}, {'B', 1}, {'U', 2},
        {'D', 3}, {'L', 4}, {'R', 5}
};

/**
 * A class that represents a Rubik's Cube.
 * */
class Cube {
 protected:
    /**
     * Nested array witch contains the current cube state.
     * The Rubik's Cube contains fo 6 Faces with each 3 Rows
     * and 3 Columns.
     * */
    BOARD board{};

 public:
    Cube();
    ~Cube();

    /**
     * Returns a ptr to the current board.
     * */
    // std::array<std::array<std::array<int, 3>, 3>, 6> getBoard();

    /**
     * Return the selected Face of the Cube.
     * */
    FACE getFace(int a);

     /**
      * Returns a selected Face of the cube.
      * */
      // int

    /**
     * Update the current board.
     * TODO(me) how to check if a given board is solvable and valid
     * */
     // void setBoard(int* pBoard);

    /**
     * Get the element at a given index (x, y, z)
     * */
    int getBoardElement(int x, int y, int z);

    /**
     * Manipulate the Rubik's Cube Class with the given Cube notation.
     * For mor information about the notation refer to the README.md
     * */
    void manipulation(std::vector<std::string> const& instructions);

    /**
     * Atomic cube manipulations.
     * */

    // rotate the front face of the cube by 90⁰ clockwise
    void front();

    // rotate the back face of the cube by 90⁰ counterclockwise
    void back();

    // rotate the up face of the cube by 90⁰ clockwise
    void up();

    // rotate the down face of the cube by 90⁰ clockwise
    void down();

    // rotate the left face of the cube by 90⁰ clockwise
    void left();

    // rotate the right face of the cube by 90⁰ clockwise
    void right();
};  // end-class Cube

/**
 * Printing the current board of the cube.
 * */
std::ostream& operator<<(std::ostream& pOstream, Cube& c);

/**
 * Check if tow Cube objects are representing the same Cube.
 * @return true if cubes are eq else false
 * */
bool operator==(Cube a, Cube b);

}  // namespace rubikscube

#endif  // RUBIKS_CUBE_HH_
