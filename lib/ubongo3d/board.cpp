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

#include "ubongo3d/board.h"

namespace Ubongo3d {
    Board::Board()
	: width(0),
	  height(0), 
	  depth(0), 
	  initial_blank_count(0),
	  current_blank_count(0),
	  initial_board(),
	  current_board() {
    }

    Board::Board(const char *shape)
	: width(0),
	  height(0), 
	  depth(0), 
	  initial_blank_count(0),
	  current_blank_count(0),
	  initial_board(),
	  current_board() {
	if (shape != NULL)
	    set_shape(shape);
    }

    Board::Board(const std::string &shape)
	: width(0),
	  height(0), 
	  depth(0), 
	  initial_blank_count(0),
	  current_blank_count(0),
	  initial_board(),
	  current_board() {
	set_shape(shape);
    }

    bool
    Board::has_shape() const {
	return (width > 0 && height > 0 && depth > 0);
    }

    int
    Board::get_width() const {
	return width;
    }

    int
    Board::get_height() const {
	return height;
    }

    int
    Board::get_depth() const {
	return depth;
    }

    int
    Board::get_cube_count() const {
	return initial_blank_count;
    }

    int
    Board::get_blank_count() const {
	return current_blank_count;
    }

    bool
    Board::is_complete() const {
	return (current_blank_count == 0);
    }

    void
    Board::restart() {
	current_board = initial_board;
	current_blank_count = initial_blank_count;
    }

    char
    Board::get_cube(const Location &location) const {
	if (location.x < 0 || location.x >= width)
	    return unavailable;
	if (location.y < 0 || location.y >= height)
	    return unavailable;
	if (location.z < 0 || location.z >= depth)
	    return unavailable;

	return current_board[location.x + location.y * width
	    + location.z * width * height];
    }

    bool
    Board::set_shape(const char *shape) {
	width  = 0;
	height = 0;
	depth  = 2;
	initial_blank_count = 0;

	int x = 0;
	int y = 0;
	for (const char *p = shape; *p != '\0'; p++) {
	    if (*p == '\n') {
		y++;
		x = 0;
	    } else {
		if (x >= width)
		    width = x + 1;
		if (y >= height)
		    height = y + 1;
		x++;
	    }
	}

	if (width == 0 || height == 0)
	    goto failed;

	initial_board.resize(width * height * depth, unavailable);

	x = 0;
	y = 0;
	for (const char *p = shape; *p != '\0'; p++) {
	    if (*p == '\n') {
		y++;
		x = 0;
	    } else if (*p == blank) {
		for (int z = 0; z < depth; z++) {
		    initial_board[x + y * width + width * height * z]
			= blank;
		}
		initial_blank_count += depth;
		x++;
	    } else if (*p == unavailable) {
		for (int z = 0; z < depth; z++) {
		    initial_board[x + y * width + width * height * z]
			= unavailable;
		}
		x++;
	    } else {
		goto failed;
	    }
	}

	current_board = initial_board;
	current_blank_count = initial_blank_count;

	return true;

	//
	// An error occurs.
	//
      failed:
	width  = 0;
	height = 0;
	depth  = 0;
	initial_blank_count = 0;

	return false;
    }

    bool
    Board::locate_piece(const Piece &piece, const Location &location,
	Direction direction) {
	std::size_t size = piece.get_size();

	for (std::size_t i = 0; i < size; i++) {
	    Location cube_location
		= location + piece.get_cube(i, direction);
	    if (cube_location.x < 0 || cube_location.x >= width)
		return false;
	    if (cube_location.y < 0 || cube_location.y >= height)
		return false;
	    if (cube_location.z < 0 || cube_location.z >= depth)
		return false;
	    if (current_board[cube_location.x + cube_location.y * width
		+ cube_location.z * width * height] != blank)
		return false;
	}

	for (std::size_t i = 0; i < size; i++) {
	    Location cube_location
		= location + piece.get_cube(i, direction);
	    current_board[cube_location.x + cube_location.y * width
		+ cube_location.z * width * height] = piece.get_id();
	}

	current_blank_count -= piece.get_size();
	return true;
    }

    bool
    Board::unlocate_piece(const Piece &piece) {
	std::size_t size = piece.get_size();

	for (std::size_t i = 0; i < size; i++) {
	    Location location = piece.get_located_cube(i);
	    if (location.x < 0 || location.x >= width)
		return false;
	    if (location.y < 0 || location.y >= height)
		return false;
	    if (location.z < 0 || location.z >= depth)
		return false;
	    if (current_board[location.x + location.y * width
		+ location.z * width * height] != piece.get_id())
		return false;
	}

	for (std::size_t i = 0; i < size; i++) {
	    Location location = piece.get_located_cube(i);
	    current_board[location.x + location.y * width
		+ location.z * width * height] = blank;
	}

	current_blank_count += piece.get_size();
	return true;
    }

    bool
    Board::set_shape(const std::string &shape) {
	return set_shape(shape.c_str());
    }

    std::string
    Board::dump() const {
	std::string result;

	for (int z = depth - 1; z >= 0; z--) {
	    if (z < depth - 1) {
		for (int x = 0; x < width; x++)
		    result += '=';
		result += '\n';
	    }
	    for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++)
		    result += current_board[x + y * width + z * width * height];
		result += '\n';
	    }
	}

	return result;
    }
}
