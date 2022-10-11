// Copyright (C) 2022 by Felix Drees | GNU GPLv2

#include <array>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include "./rubiks-cube.hh"

// namespace rubikscube {

// see rubiks-cube.hh /////////////////////////////////////////////////////////
std::string printFace(std::array<std::array<int, 3>, 3> face) {
    std::string rvString;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            // TODO(me)
            //  std::to_string('0' + face[x][y]) dose not work
            rvString += '0' + face[x][y];
        }
        rvString += '\n';
    }
    return rvString + "\n";
}

// a cube hase 6 faces, 3 rows and 3 columns
// https://stackoverflow.com/a/62252088
// >>Note the extra set of braces. It seems a bit odd but ...<<
const std::array<std::array<std::array<int, 3>, 3>, 6> SOLVED_BOARD = {
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

std::map<char, int> MANIPULATION_TO_INT = {
    {'F', 0}, {'B', 1}, {'U', 2},
    {'D', 3}, {'L', 4}, {'R', 5}
};

class Cube {
 protected:
        std::array<std::array<std::array<int, 3>, 3>, 6> board{};

 public:
        Cube() {
            board = SOLVED_BOARD;
        }

        ~Cube() = default;

        // see rubiks-cube.hh /////////////////////////////////////////////////
        int* getBoard(void) {
            return &board[0][0][0];
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        int getBoardElement(int x, int y, int z) {
            return board[x][y][z];
        }

        /**
         * void setBoard(int* boardPtr) {}
         *
         * Setting a new board is not allowed, because not every permutation
         * of the cube is solvable with the allowed manipulations.
         */

        // see rubiks-cube.hh /////////////////////////////////////////////////
        friend std::ostream& operator<<(std::ostream& pOstream, Cube& c) {
            return pOstream << printFace(c.board[0])
                                << printFace(c.board[1])
                                << printFace(c.board[2])
                                << printFace(c.board[3])
                                << printFace(c.board[4])
                                << printFace(c.board[5])
                                << std::endl;
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        void manipulation(std::vector<std::string> const& instructions) {
            // the number of times each manipulation should be performed
            int num;

            // loop over every instruction
            for (const std::string& instruction : instructions) {
                num = (instruction.length() == 1) ? 1 :
                        (instruction[1] == '2') ? 2 : 3;
                // perform manipulation (n times)
                for (int n = 0; n < num; n++) {
                    switch (MANIPULATION_TO_INT[instruction[0]]) {
                        case 0: front(); break;
                        case 1: back();  break;
                        case 2: up();    break;
                        case 3: down();  break;
                        case 4: left();  break;
                        case 5: right(); break;
                        default: std::cout << "INVALID OP" << std::endl; break;
                    }
                }
            }
        }

        // TODO(me) Implemented funcs ...

        // see rubiks-cube.hh /////////////////////////////////////////////////
        void front(void) {
            std::cout << "F" << std::endl;
            // TODO(me) should i use vectors or arrays?
            /*
            // get the current relevant values
            // std::array<int, 3> whiteRow = board[0][2];
            // std::array<int, 3> orangeRow = [i[0] for i in board[3]];
            // std::array<int, 3> yellowRow = board[5][0];
            // std::array<int, 3> redRow[3] = [i[2] for i in board[1]];
             */

            /*
             * update values
             * update the cube by rotating the blue face clockwise by 90°
             *
             * self._board[0][2] = red_row[::-1]
             *
             * for index in range(len(white_row)):
             *     self._board[3][index][0] = white_row[index]
             *
             * self._board[5][0] = orange_row[::-1]
             *
             * for index in range(len(yellow_row)):
             *     self._board[1][index][2] = yellow_row[index]
             *
             * self._board[2] = np.rot90(np.array(self._board[2]), 3).tolist()
             */
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        void back(void) {
            std::cout << "B" << std::endl;
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        void up(void) {
            std::cout << "U" << std::endl;
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        void down(void) {
            std::cout << "D" << std::endl;
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        void left(void) {
            std::cout << "L" << std::endl;
        }

        // see rubiks-cube.hh /////////////////////////////////////////////////
        void right(void) {
            std::cout << "R" << std::endl;
        }
};


int main(void) {
    // create a cube obj
    Cube abc = Cube();

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

// }
