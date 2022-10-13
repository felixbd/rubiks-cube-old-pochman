// Copyright (C) 2022 by Felix Drees | GNU GPLv2
// Created by felix on 12.10.22.
//

#include <array>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

#include "./rubiks-cube.hh"

namespace rubikscube {

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

Cube::Cube() {
    board = SOLVED_BOARD;
}

Cube::~Cube() = default;

// std::array<std::array<std::array<int, 3>, 3>, 6> Cube::getBoard() {
//     return board;
// }

std::array<std::array<int, 3>, 3> Cube::getFace(int a) {
    if (a < 0 || a > 5) {
        throw std::invalid_argument("INDEX OF getFace out of bound");
    }
    return board[a];
}

int Cube::getBoardElement(int x, int y, int z) {
    return board[x][y][z];
}

std::ostream& operator<<(std::ostream& pOstream, Cube& c) {
    // return pOstream << printFace(c.board[0])
    return pOstream << printFace(c.getFace(0))
                        << printFace(c.getFace(1))
                        << printFace(c.getFace(2))
                        << printFace(c.getFace(3))
                        << printFace(c.getFace(4))
                        << printFace(c.getFace(5))
                        << std::endl;
}

bool operator==(Cube &a, Cube &b) {
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 4; ++y) {
            for (int z = 0; z < 4; ++z) {
                if (a.getBoardElement(x, y, z) !=
                    b.getBoardElement(x, y, z)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Cube::manipulation(std::vector<std::string> const& instructions) {
    // the number of times each manipulation should be performed
    int num;

    // loop over every instruction
    for (const std::string& instruction : instructions) {
        num = (instruction.length() == 1) ? 1 :
                (instruction[1] == '2') ? 2 : 3;
        // perform manipulation (n times)
        for (int n = 0; n < num; n++) {
            switch (MANIPULATION_TO_INT.at(instruction[0])) {
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

void Cube::front() {
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

void Cube::back() {
    std::cout << "B" << std::endl;
}

void Cube::up() {
    std::cout << "U" << std::endl;
}

void Cube::down() {
    std::cout << "D" << std::endl;
}

void Cube::left() {
    std::cout << "L" << std::endl;
}

void Cube::right() {
    std::cout << "R" << std::endl;
}

}  // namespace rubikscube
