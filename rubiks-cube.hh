// Copyright (C) 2022 by Felix Drees | GNU GPLv2

#ifndef RUBIKS_CUBE_HH_
#define RUBIKS_CUBE_HH_

namespace rubikscube {

// TODO(me)

/**
 * Returns a string with all Values of the given Face of the Cube.
 * */
std::string printFace(std::array<std::array<int, 3>, 3> face);

}  // namespace rubikscube

#endif  // RUBIKS_CUBE_HH_
