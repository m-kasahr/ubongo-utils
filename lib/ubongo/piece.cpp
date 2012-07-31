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
#include "ubongo/piece.h"

namespace Ubongo {
    void
    Piece::sort_squares(std::vector<Location> &squares) {
	for (std::size_t i = 0; i < squares.size() - 1; i++) {
	    Location min = squares[i];
	    std::size_t min_index = i;
	    for (std::size_t j = i + 1; j < squares.size(); j++) {
		if (min.y > squares[j].y
		    || (min.y == squares[j].y && min.x > squares[j].x)) {
		    min = squares[j];
		    min_index = j;
		}
	    }

	    squares[min_index] = squares[i];
	    squares[i] = min;
	}
    }

    bool
    Piece::compare_squares(std::vector<Location> &squares1,
	std::vector<Location> &squares2) {
	if (squares1.size() != squares2.size())
	    return false;

	std::vector<Location>::iterator it1 = squares1.begin();
	std::vector<Location>::iterator it2 = squares2.begin();
	while (it1 != squares1.end()) {
	    if (it1->x != it2->x || it1->y != it2->y)
		return false;
	    it1++;
	    it2++;
	}

	return true;
    }

    void
    Piece::canonicalize_squares(std::vector<Location> &squares_arg) {
	if (squares_arg.empty())
	    return;

	sort_squares(squares_arg);

	int min_x = squares_arg[0].x;
	int min_y = squares_arg[0].y;
	std::vector<Location>::iterator it = squares_arg.begin();
	it++;
	while (it != squares_arg.end()) {
	    if (min_x > it->x)
		min_x = it->x;
	    if (min_y > it->y)
		min_y = it->y;
	    it++;
	}

	if (min_x == 0 && min_y == 0)
	    return;

	it = squares_arg.begin();
	while (it != squares_arg.end()) {
	    it->x -= min_x;
	    it->y -= min_y;
	    it++;
	}
    }

    void
    Piece::rotate_squares(std::vector<Location> &to_squares,
	std::vector<Location> &from_squares, Direction direction) {
	static const int effects[direction_count][4] = {
	    { 1,  0,  0,  1},  // right0
	    { 0, -1,  1,  0},  // right90
	    {-1,  0,  0, -1},  // right180
	    { 0,  1, -1,  0},  // right270
	    {-1,  0,  0,  1},  // mirror_right0
	    { 0, -1, -1,  0},  // mirror_right90
	    { 1,  0,  0, -1},  // mirror_right180
	    { 0,  1,  1,  0},  // mirror_right270
	};
	const int *effect = effects[direction];

	to_squares.resize(from_squares.size());
	std::vector<Location>::iterator from_it = from_squares.begin();
	std::vector<Location>::iterator to_it = to_squares.begin();

	while (from_it != from_squares.end()) {
	    to_it->x = from_it->x * effect[0] + from_it->y * effect[1];
	    to_it->y = from_it->x * effect[2] + from_it->y * effect[3];
	    from_it++;
	    to_it++;
	}

	canonicalize_squares(to_squares);
    }

    Piece::Piece()
	: id(blank),
	  squares(),
	  located(false),
	  location(),
	  direction(right0),
	  symmetries() {
    }

    Piece::Piece(const char *shape)
	: id(blank),
	  squares(),
	  located(false),
	  location(),
	  direction(right0),
	  symmetries() {
	if (shape != NULL)
	    set_shape(shape);
    }

    Piece::Piece(const std::string &shape)
	: id(blank),
	  squares(),
	  located(false),
	  location(),
	  direction(right0),
	  symmetries() {
	set_shape(shape);
    }

    bool
    Piece::has_shape() const {
	return (squares[right0].size() > 0);
    }

    std::size_t
    Piece::get_size() const {
	return squares[right0].size();
    }

    Location
    Piece::get_square(std::size_t index, Direction direction) const {
	if (direction < 0 || direction >= direction_count)
	    throw std::out_of_range("Ubongo::Piece::get_square");
	if (index >= squares[index].size())
	    throw std::out_of_range("Ubongo::Piece::get_square");
	return squares[direction][index];
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
    Piece::get_symmetry() const {
	if (!located)
	    throw std::logic_error("Ubongo::Piece::get_symmetry");
	return symmetries[direction];
    }

    Direction
    Piece::get_symmetry(Direction direction_arg) const {
	return symmetries[direction_arg];
    }

    Location
    Piece::get_location() const {
	if (!located)
	    throw std::logic_error("Ubongo::Piece::get_location");
	return location;
    }

    Direction
    Piece::get_direction() const {
	if (!located)
	    throw std::logic_error("Ubongo::Piece::get_direction");
	return direction;
    }

    void
    Piece::locate(const Location &location_arg, Direction direction_arg) {
	if (direction < 0 || direction >= direction_count)
	    throw std::out_of_range("Ubongo::Piece::locate");
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
	    squares[i].clear();

	//
	// Set 'shape' as the shape of right0 direction.
	//
	Location square;
	square.x = 0;
	square.y = 0;
	char tmp_id = blank;

	for (const char *p = shape; *p != '\0'; p++) {
	    if (*p == '\n') {
		square.y++;
		square.x = 0;
	    } else if (*p == blank) {
		square.x++;
	    } else if ('A' <= *p && *p <= 'Z') {
		if (tmp_id == blank)
		    tmp_id = *p;
		else if (tmp_id != *p)
		    goto failed;
		squares[right0].push_back(square);
		square.x++;
	    } else {
		goto failed;
	    }
	}

	if (tmp_id == blank)
	    goto failed;

	id = tmp_id;
	canonicalize_squares(squares[right0]);

	//
	// Register shapes data of other directions.
	//
	for (int i = right90; i < direction_count; i++)
	    rotate_squares(squares[i], squares[0], (Direction)i);

	//
	// Inspect symmetry of the shape.
	//
	symmetries[right0] = right0;
	for (int i = right90; i < direction_count; i++) {
	    symmetries[i] = (Direction)i;
	    for (int j = right0; j < i; j++) {
		if (compare_squares(squares[i], squares[j])) {
		    symmetries[i] = (Direction)j;
		    break;
		}
	    }
	}

	return true;

	//
	// An error occurs.
	//
      failed:
	squares[right0].clear();
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
    Piece::get_located_square(std::size_t index) const {
	if (!located)
	    throw std::logic_error("Ubongo::Piece::get_located_square");
	if (index >= squares[index].size())
	    throw std::out_of_range("Ubongo::Piece::get_located_square");

	return squares[direction][index] + location;
    }
}
