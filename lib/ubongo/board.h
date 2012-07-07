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

#ifndef UBONGO_BOARD_H
#define UBONGO_BOARD_H

#include <string>
#include <vector>
#include "ubongo/common.h"
#include "ubongo/piece.h"

namespace Ubongo {
    /// 
    /// A board used in Ubongo.
    ///
    /// The object represents the shape of the board; its width, its
    /// height and the initial status of squares in it.  It also
    /// represents the "current status" of squares during a play.
    ///
    /// In the initial status, each square is either "blank" or
    /// "unavailable" (not used in a game).  In the current status,
    /// squares become the status "occupied by a piece" in addition
    /// with "blank" and "unavailable".
    ///
    class Board {
    private:
	// Width of the board.
	int width;

	// Height of the board.
	int height;

	// The number of blank squares at start of the game.
	int initial_blank_count;

	// The number of blank squares the current status.
	int current_blank_count;

	// Initial shape of the board.
	std::vector<char> initial_board;

	// The current status of squares.
	std::vector<char> current_board;

    public:
	/// Status ID for blank square.
	static const char blank = '#';

	/// Status ID for unavailable square (not used in a game).
	static const char unavailable = '.';

	// The maximum number of characters in a line of file.
	static const int max_file_line_length = 256;

	///
	/// Default constructor.
	///
	Board();

	///
	/// Constructor.
	///
	/// @param Shape the initial shape of the board.
	///
	Board(const char *shape);

	///
	/// Constructor.
	///
	/// @param Shape the initial shape of the board.
	///
	Board(const std::string &shape);

	///
	/// Examine whether the board has a shape or not.
	///
	/// @return True if the board has a shape.
	///
	bool
	has_shape() const;

	///
	/// Return width of the board.
	///
	/// @return Width of the board.
	///
	int
	get_width() const;

	///
	/// Return height of the board.
	///
	/// @return Height of the board.
	///
	int
	get_height() const;

	///
	/// Return the number of squares.
	///
	/// @return The number of squares.
	///
	int
	get_square_count() const;

	///
	/// Return the number of blank squares remained currently.
	///
	/// @return The number of blank squares.
	///
	int
	get_blank_count() const;

	///
	/// Examine whether no blank squares in the board.
	///
	/// @return True if no blank squares in the board.
	///
	bool
	is_complete() const;

	///
	/// Remove all pieces put on the board.
	///
	void
	restart();

	///
	/// Get status of a particular square in the board.
	/// 
	/// @param location Location of the square.
	/// @return The status of the square; blank, unavailable or piece ID.
	///
	char
	get_square(const Location &location) const;

	///
	/// Set shape of the board.
	///
	/// @param shape The initial shape of the board.
	/// @return True if 'shape' is valid.
	///
	/// In the shape string, '#' means a blank square, '.' means
	/// unavailable and '\n' means the end of the row.  For example,
	/// the following string represents a board with 3x3 squares.
	///
	///    const char *shape = "###\n"
	///                        "###\n"
	///                        "###\n";
	///
	bool
	set_shape(const char *shape);

	///
	/// Set shape of the board.
	///
	/// @param shape The initial shape of the board.
	/// @return True if 'shape' is valid.
	///
	bool
	set_shape(const std::string &shape);

	///
	/// Set shape of the board, by reading a file.
	///
	/// @param file_name File on which shape of the board is written.
	/// @return True if 'shape' is valid.
	///
	bool
	set_shape_by_file(const char *file_name);

	///
	/// Set shape of the board, by reading a file.
	///
	/// @param file_name File on which shape of the board is written.
	/// @return True if 'shape' is valid.
	///
	bool
	set_shape_by_file(const std::string &file_name);

	///
	/// Put a piece on the board.
	///
	/// @param piece A piece put on the board.
	/// @param location Location of the piece on the board.
	/// @return True if the piece fits the Please.
	///
	/// location note that it never changes piece's status.
	///
	bool
	locate_piece(const Piece &piece, const Location &location, 
	    Direction direction);

	///
	/// Remove a piece from the board.
	///
	/// @param piece A piece which has been put on the board.
	/// @return True if the piece is located on the board.
	///
	/// Please note that it never changes piece's status.
	///
	bool
	unlocate_piece(const Piece &piece);

	///
	/// Dump the current status of squares in the board.
	///
	/// @return A string which shows status of squares.
	///
	/// The returned string has the similar form as 'shape' argument
	/// given to set_shape().  Unlike 'share', however, also piece IDs
	/// may be appeared in it.
	///
	std::string
	dump() const;
    };
}

#endif // UBONGO_BOARD_H
