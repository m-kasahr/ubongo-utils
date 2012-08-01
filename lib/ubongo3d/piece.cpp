//                                                            -*- C++ -*-
// Copyright (c) 2009  Motoyuki Kasahara
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.
//

#include <fstream>
#include <iostream>
#include <stdexcept>
#include "ubongo3d/piece.h"

namespace Ubongo3d {
    void
    Piece::sort_cubes(std::vector<Location> &cubes) {
	for (std::size_t i = 0; i < cubes.size() - 1; i++) {
	    Location min = cubes[i];
	    std::size_t min_index = i;
	    for (std::size_t j = i + 1; j < cubes.size(); j++) {
		bool is_min_cube = false;
		if (min.z > cubes[j].z) {
		    is_min_cube = true;
		} else if (min.z == cubes[j].z) {
		    if (min.y > cubes[j].y) {
			is_min_cube = true;
		    } else if (min.y == cubes[j].y) {
			if (min.x > cubes[j].x)
			    is_min_cube = true;
		    }
		}
		if (is_min_cube) {
		    min = cubes[j];
		    min_index = j;
		}
	    }

	    cubes[min_index] = cubes[i];
	    cubes[i] = min;
	}
    }

    bool
    Piece::compare_cubes(std::vector<Location> &cubes1,
	std::vector<Location> &cubes2) {
	if (cubes1.size() != cubes2.size())
	    return false;

	std::vector<Location>::iterator it1 = cubes1.begin();
	std::vector<Location>::iterator it2 = cubes2.begin();
	while (it1 != cubes1.end()) {
	    if (it1->x != it2->x || it1->y != it2->y || it1->z != it2->z)
		return false;
	    it1++;
	    it2++;
	}

	return true;
    }

    void
    Piece::canonicalize_cubes(std::vector<Location> &cubes_arg) {
	if (cubes_arg.empty())
	    return;

	sort_cubes(cubes_arg);

	int min_x = cubes_arg[0].x;
	int min_y = cubes_arg[0].y;
	int min_z = cubes_arg[0].z;
	std::vector<Location>::iterator it = cubes_arg.begin();
	it++;
	while (it != cubes_arg.end()) {
	    if (min_x > it->x)
		min_x = it->x;
	    if (min_y > it->y)
		min_y = it->y;
	    if (min_z > it->z)
		min_z = it->z;
	    it++;
	}

	it = cubes_arg.begin();
	while (it != cubes_arg.end()) {
	    it->x -= min_x;
	    it->y -= min_y;
	    it->z -= min_z;
	    it++;
	}
    }

    void
    Piece::rotate_cubes(std::vector<Location> &to_cubes,
	std::vector<Location> &from_cubes, Direction direction) {
	static const int effects[direction_count][9] = {
	    { 1,  0,  0,   0,  1,  0,   0,  0,  1},
	    { 1,  0,  0,   0,  0, -1,   0,  1,  0},
	    { 1,  0,  0,   0, -1,  0,   0,  0, -1},
	    { 1,  0,  0,   0,  0,  1,   0, -1,  0},

	    { 0,  0,  1,   0,  1,  0,  -1,  0,  0},
	    { 0,  1,  0,   0,  0, -1,  -1,  0,  0},
	    { 0,  0, -1,   0, -1,  0,  -1,  0,  0},
	    { 0, -1,  0,   0,  0,  1,  -1,  0,  0},

	    {-1,  0,  0,   0,  1,  0,   0,  0, -1},
	    {-1,  0,  0,   0,  0, -1,   0, -1,  0},
	    {-1,  0,  0,   0, -1,  0,   0,  0,  1},
	    {-1,  0,  0,   0,  0,  1,   0,  1,  0},

	    { 0,  0, -1,   0,  1,  0,   1,  0,  0},
	    { 0, -1,  0,   0,  0, -1,   1,  0,  0},
	    { 0,  0,  1,   0, -1,  0,   1,  0,  0},
	    { 0,  1,  0,   0,  0,  1,   1,  0,  0},

	    { 0, -1,  0,   1,  0,  0,   0,  0,  1},
	    { 0,  0,  1,   1,  0,  0,   0,  1,  0},
	    { 0,  1,  0,   1,  0,  0,   0,  0, -1},
	    { 0,  0, -1,   1,  0,  0,   0, -1,  0},

	    { 0,  1,  0,  -1,  0,  0,   0,  0,  1},
	    { 0,  0, -1,  -1,  0,  0,   0,  1,  0},
	    { 0, -1,  0,  -1,  0,  0,   0,  0, -1},
	    { 0,  0,  1,  -1,  0,  0,   0, -1,  0}
	};
	const int *effect = effects[direction];

	to_cubes.resize(from_cubes.size());
	std::vector<Location>::iterator from_it = from_cubes.begin();
	std::vector<Location>::iterator to_it = to_cubes.begin();

	while (from_it != from_cubes.end()) {
	    to_it->x = from_it->x * effect[0]
		+ from_it->y * effect[1]
		+ from_it->z * effect[2];
	    to_it->y = from_it->x * effect[3]
		+ from_it->y * effect[4]
		+ from_it->z * effect[5];
	    to_it->z = from_it->x * effect[6]
		+ from_it->y * effect[7]
		+ from_it->z * effect[8];
	    from_it++;
	    to_it++;
	}

	canonicalize_cubes(to_cubes);
    }

    Piece::Piece()
	: id(blank),
	  cubes(),
	  located(false),
	  location(),
	  direction((Direction)0),
	  symmetry_ids() {
    }

    Piece::Piece(const char *shape)
	: id(blank),
	  cubes(),
	  located(false),
	  location(),
	  direction((Direction)0),
	  symmetry_ids() {
	if (shape != NULL)
	    set_shape(shape);
    }

    Piece::Piece(const std::string &shape)
	: id(blank),
	  cubes(),
	  located(false),
	  location(),
	  direction((Direction)0),
	  symmetry_ids() {
	set_shape(shape);
    }

    bool
    Piece::has_shape() const {
	return (cubes[0].size() > 0);
    }

    std::size_t
    Piece::get_size() const {
	return cubes[0].size();
    }

    Location
    Piece::get_cube(std::size_t index, Direction direction) const {
	if (direction < 0 || direction >= direction_count)
	    throw std::out_of_range("Ubongo3d::Piece::get_cube");
	if (index >= cubes[index].size())
	    throw std::out_of_range("Ubongo3d::Piece::get_cube");
	return cubes[direction][index];
    }

    char
    Piece::get_id() const {
	return id;
    }

    bool
    Piece::is_located() const {
	return located;
    }

    Direction
    Piece::get_symmetry_id() const {
	if (!located)
	    throw std::logic_error("Ubongo3d::Piece::get_symmetry_id");
	return symmetry_ids[direction];
    }

    Direction
    Piece::get_symmetry_id(Direction direction_arg) const {
	return symmetry_ids[direction_arg];
    }

    Location
    Piece::get_location() const {
	if (!located)
	    throw std::logic_error("Ubongo3d::Piece::get_location");
	return location;
    }

    Direction
    Piece::get_direction() const {
	if (!located)
	    throw std::logic_error("Ubongo3d::Piece::get_direction");
	return direction;
    }

    void
    Piece::locate(const Location &location_arg, Direction direction_arg) {
	if (direction < 0 || direction >= direction_count)
	    throw std::out_of_range("Ubongo3d::Piece::locate");
	located = true;
	location = location_arg;
	direction = direction_arg;
    }

    void
    Piece::unlocate() {
	located = false;
    }

    bool
    Piece::set_shape(const char *shape) {
	for (int i = 0; i < direction_count; i++)
	    cubes[i].clear();

	//
	// Set 'shape' as the shape of direction ID 0.
	//
	Location cube;
	cube.x = 0;
	cube.y = 0;
	cube.z = 0;
	char tmp_id = blank;
	bool horizontal_line = false;

	for (const char *p = shape; *p != '\0'; p++) {
	    if (horizontal_line) {
		if (*p == '\n')
		    horizontal_line = false;
	    } else {
		if (*p == '=') {
		    horizontal_line = true;
		    cube.z--;
		    cube.x = 0;
		    cube.y = 0;
		} else if (*p == '\n') {
		    cube.y++;
		    cube.x = 0;
		} else if (*p == blank) {
		    cube.x++;
		} else if ('A' <= *p && *p <= 'Z') {
		    if (tmp_id == blank)
			tmp_id = *p;
		    else if (tmp_id != *p)
			goto failed;
		    cubes[0].push_back(cube);
		    cube.x++;
		} else {
		    goto failed;
		}
	    }
	}

	if (tmp_id == blank)
	    goto failed;

	id = tmp_id;
	canonicalize_cubes(cubes[0]);

	//
	// Register shapes data of other directions.
	//
	for (int i = 0; i < direction_count; i++)
	    rotate_cubes(cubes[i], cubes[0], (Direction)i);

	//
	// Inspect symmetry of the shape.
	//
	symmetry_ids[0] = (Direction)0;
	for (int i = 0; i < direction_count; i++) {
	    symmetry_ids[i] = (Direction)i;
	    for (int j = 0; j < i; j++) {
		if (compare_cubes(cubes[i], cubes[j])) {
		    symmetry_ids[i] = (Direction)j;
		    break;
		}
	    }
	}

	return true;

	//
	// An error occurs.
	//
      failed:
	cubes[0].clear();
	return false;
    }

    bool
    Piece::set_shape(const std::string &shape) {
	return set_shape(shape.c_str());
    }

    bool
    Piece::set_shape_by_file(const char *file_name) {
	std::fstream fs;
	fs.open(file_name, std::ios::in);
	if (!fs.is_open()) {
	    std::string message = "failed to open the file: ";
	    message += file_name;
	    throw std::ios_base::failure(message);
	}

	std::string shape;
	char line[max_file_line_length];
	while (fs.getline(line, sizeof(line))) {
	    shape += line;
	    shape += "\n";
	}
	fs.close();
	return set_shape(shape);
    }

    bool
    Piece::set_shape_by_file(const std::string &file_name) {
	return set_shape_by_file(file_name.c_str());
    }

    Location
    Piece::get_located_cube(std::size_t index) const {
	if (!located)
	    throw std::logic_error("Ubongo3d::Piece::get_located_cube");
	if (index >= cubes[index].size())
	    throw std::out_of_range("Ubongo3d::Piece::get_located_cube");

	return cubes[direction][index] + location;
    }

    std::string
    Piece::dump(Direction direction_arg) const {
	std::string result;
	int width = 0;
	int height = 0;
	int depth = 0;

	//
	// Calculate 'width', 'height' and 'depth' of the piece.
	//
	std::vector<Location>::const_iterator it
	    = cubes[direction_arg].begin();
	while (it != cubes[direction_arg].end()) {
	    if (it->x >= width)
		width = it->x + 1;
	    if (it->y >= height)
		height = it->y + 1;
	    if (it->z >= depth)
		depth = it->z + 1;
	    it++;
	}

	//
	// Set 'result' to blank.
	// In case width=7, hegiht=3 and depth=2 that 'result' (blank)
	// looks like:
	//
	//   ".......\n"
	//   ".......\n"
	//   ".......\n"
	//   "=======\n"
	//   ".......\n"
	//   ".......\n"
	//   ".......\n"
	//
	result.resize((width + 1) * (height + 1) * depth - (width + 1), blank);

	for (int z = depth - 1; z > 0; z--) {
	    size_t offset = z * (width + 1) * (height + 1) - (width + 1);
	    for (int x = 0; x < width; x++)
		result[offset + x] = '=';
	}

	for (int z = depth - 1; z >= 0; z--) {
	    for (int y = 0; y < height + 1; y++) {
		size_t offset =
		      y * (width + 1)
		    + z * (width + 1) * (height + 1)
		    - 1;
		result[offset] = '\n';
	    }
	}

	it = cubes[direction_arg].begin();
	while (it != cubes[direction_arg].end()) {
	    size_t offset =
		  it->x
		+ it->y * (width + 1)
		+ (depth - 1 - it->z) * (width + 1) * (height + 1);
	    result[offset] = id;
	    it++;
	}

	return result;
    }

    std::string
    Piece::dump() const {
	if (!located)
	    throw std::logic_error("Ubongo3d::Piece::dump");
	return dump(direction);
    }
}
