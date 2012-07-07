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
#include "ubongo/board.h"

namespace Ubongo {
    Board::Board()
	: width(0),
	  height(0), 
	  initial_blank_count(0),
	  current_blank_count(0),
	  initial_board(),
	  current_board() {
    }

    Board::Board(const char *shape)
	: width(0),
	  height(0), 
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
	  initial_blank_count(0),
	  current_blank_count(0),
	  initial_board(),
	  current_board() {
	set_shape(shape);
    }

    bool
    Board::has_shape() const {
	return (width > 0 && height > 0);
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
    Board::get_square_count() const {
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
    Board::get_square(const Location &location) const {
	if (location.x < 0 || location.x >= width)
	    return unavailable;
	if (location.y < 0 || location.y >= height)
	    return unavailable;

	return current_board[location.x + location.y * width];
    }

    bool
    Board::set_shape(const char *shape) {
	width  = 0;
	height = 0;
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

	initial_board.resize(width * height, unavailable);

	x = 0;
	y = 0;
	for (const char *p = shape; *p != '\0'; p++) {
	    if (*p == '\n') {
		y++;
		x = 0;
	    } else if (*p == blank) {
		initial_board[x + y * width] = blank;
		initial_blank_count++;
		x++;
	    } else if (*p == unavailable) {
		initial_board[x + y * width] = unavailable;
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
	initial_blank_count = 0;

	return false;
    }

    bool
    Board::set_shape(const std::string &shape) {
	return set_shape(shape.c_str());
    }

    bool
    Board::set_shape_by_file(const char *file_name) {
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
    Board::set_shape_by_file(const std::string &file_name) {
	return set_shape_by_file(file_name.c_str());
    }

    bool
    Board::locate_piece(const Piece &piece, const Location &location,
	Direction direction) {
	std::size_t size = piece.get_size();

	for (std::size_t i = 0; i < size; i++) {
	    Location square_location
		= location + piece.get_square(i, direction);
	    if (square_location.x < 0 || square_location.x >= width)
		return false;
	    if (square_location.y < 0 || square_location.y >= height)
		return false;
	    if (current_board[square_location.x + square_location.y * width]
		!= blank)
		return false;
	}

	for (std::size_t i = 0; i < size; i++) {
	    Location square_location
		= location + piece.get_square(i, direction);
	    current_board[square_location.x + square_location.y * width]
		= piece.get_id();
	}

	current_blank_count -= piece.get_size();
	return true;
    }

    bool
    Board::unlocate_piece(const Piece &piece) {
	std::size_t size = piece.get_size();

	for (std::size_t i = 0; i < size; i++) {
	    Location location = piece.get_located_square(i);
	    if (location.x < 0 || location.x >= width)
		return false;
	    if (location.y < 0 || location.y >= height)
		return false;
	    if (current_board[location.x + location.y * width]
		!= piece.get_id())
		return false;
	}

	for (std::size_t i = 0; i < size; i++) {
	    Location location = piece.get_located_square(i);
	    current_board[location.x + location.y * width] = blank;
	}

	current_blank_count += piece.get_size();
	return true;
    }

    std::string
    Board::dump() const {
	std::string result;

	for (int y = 0; y < height; y++) {
	    for (int x = 0; x < width; x++)
		result += current_board[x + y * width];
	    result += '\n';
	}

	return result;
    }
}
