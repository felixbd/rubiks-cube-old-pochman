// Copyright (C) 2022 by Felix Drees | GNU GPLv2

#include <array>
#include <iostream>
#include <string>
#include "./rubiks-cube.hh"

// namespace rubikscube {

std::string printFace(std::array<std::array<int, 3>, 3> face) {
    std::string rvString = "";
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            rvString += '0' + face[x][y];
        }
        rvString += '\n';
    }
    return rvString;
}

// a cube hase 6 faces, 3 rows and 3 colums
// https://stackoverflow.com/a/62252088
// >>Note the extra set of braces. It seems a bit odd but ...<<
std::array<std::array<std::array<int, 3>, 3>, 6> SOLVED_BOARD = {
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


class Cube {
 protected:
        std::array<std::array<std::array<int, 3>, 3>, 6> board;

 public:
        Cube() {
            board = SOLVED_BOARD;
        }

        ~Cube() {
            std::cout << "del cube" << std::endl;
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        int* getBoard(void) {
            return &board[0][0][0];
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        int getBoardElement(const int x, const int y, const int z) {
            return board[x][y][z];  // TODO(me) check ...
        }

        /**
         * void setBoard(int* boardPtr) {}
         *
         * Setting a new board is not allowed, because not every permutation
         * of the cube is solvable with the allowed manipulations.
         */

        friend std::ostream& operator<<(std::ostream& ostr, Cube& c) {
            return ostr << printFace(c.board[0])
                        << printFace(c.board[1])
                        << printFace(c.board[2])
                        << printFace(c.board[3])
                        << printFace(c.board[3])
                        << printFace(c.board[5])
                        << std::endl;
        }
};


int main(void) {
    Cube abc = Cube();

    std::cout
        << "the 4,2, 1th element is:" << ('0' + abc.getBoardElement(4, 2, 1))
        << std::endl;  // TODO(me) check ... .

    std::cout << "test for printing the how board: \n\n" << abc << std::endl;

    return 0;
}

// }
