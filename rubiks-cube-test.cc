// Copyright (C) 2022 by Felix Drees | GNU GPLv2
// Created by felix on 11.10.22.
//

#include <gtest/gtest.h>
#include <vector>
#include "./rubiks-cube.hh"

/**
 * Test if the constructor of the Cube class works.
 */
TEST(MainCubeTest, checkInit) {
    rubikscube::Cube c1 = rubikscube::Cube();
}

TEST(MainCubeTest, checkManipulationReaction) {
    ASSERT_EQ(true, 1) << "true should eq to 1";

    rubikscube::Cube c2 = rubikscube::Cube();

    // TODO(me) manipulate the cube c2 (J Perm)
    /*
    std::vector<std::string> instructions = {
            "R'", "U", "L'", "U2", "R", "U'", "R'", "U2", "RL"
    };
    c2.manipulation(instructions);
    */

    // TODO(me) check if the cube is correctly manipulated
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
