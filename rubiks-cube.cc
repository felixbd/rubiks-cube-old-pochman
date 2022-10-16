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

std::string printFace(FACE face) {
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

// TODO(me) add test case and check if this func is correct
FACE rotateMatrix(FACE a, int num) {
    for (int index = 0; index < num; ++index) {
        // Transposing the matrix
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                std::swap(a[i][j], a[j][i]);
            }
        }
        // Reversing each row of the matrix
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3 / 2; ++j) {
                std::swap(a[i][j], a[i][3-j-1]);
            }
        }
    }
    return a;
}

    Cube::Cube() {
    board = SOLVED_BOARD;
}

Cube::~Cube() = default;

// std::array<std::array<std::array<int, 3>, 3>, 6> Cube::getBoard() {
//     return board;
// }

FACE Cube::getFace(int a) {
    if (a < 0 || a > 5) {
        throw std::invalid_argument("INDEX OF getFace out of bound");
    }
    return board[a];
}

int Cube::getBoardElement(int x, int y, int z) {
    return board[x][y][z];
}

std::ostream& operator<<(std::ostream& pOstream, Cube& c) {
    return pOstream << printFace(c.getFace(0))
                        << printFace(c.getFace(1))
                        << printFace(c.getFace(2))
                        << printFace(c.getFace(3))
                        << printFace(c.getFace(4))
                        << printFace(c.getFace(5))
                        << std::endl;
}

bool operator==(Cube a, Cube b) {
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
                default: std::cerr << "INVALID OP" << std::endl; break;
            }
        }
    }
}

void Cube::front() {
    // get the current relevant values
    std::array<int, 3> whiteRow = board[0][2];
    std::array<int, 3> orangeRow = {
            board[3][0][0], board[3][1][0], board[3][2][0]
    };
    std::array<int, 3> yellowRow = board[5][0];
    std::array<int, 3> redRow = {
            board[1][0][2], board[1][1][2], board[1][2][2]
    };

    // update the cube by rotating the blue face clockwise by 90°
    board[0][2] = {redRow[2], redRow[1], redRow[0]};
    for (int i = 0; i < 3; ++i) { board[3][i][0] = whiteRow[i]; }
    board[5][0] = {orangeRow[2], orangeRow[1], orangeRow[0]};
    for (int i = 0; i < 3; ++i) { board[1][i][2] = yellowRow[i]; }
    board[2] = rotateMatrix(board[2], 1);
}

// TODO(me) Implemented funcs ...
//  https://github.com/felixbd/rubiks_cube/blob/main/Cube.py

void Cube::back() {
    // std::cout << "B" << std::endl;
}

void Cube::up() {
    // std::cout << "U" << std::endl;
}

void Cube::down() {
    // std::cout << "D" << std::endl;
}

void Cube::left() {
    // std::cout << "L" << std::endl;
}

void Cube::right() {
    // std::cout << "R" << std::endl;
}

}  // namespace rubikscube
