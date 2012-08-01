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

#ifndef UBONGO3D_PIECE_H
#define UBONGO3D_PIECE_H

#include <string>
#include <vector>
#include "ubongo3d/common.h"

namespace Ubongo3d {
    /// 
    /// A piece used in Ubongo 3-D.
    ///
    /// A piece object has information of its shape, whether it is put
    /// on he board or not, and if put on board, the current location
    /// and the direction.
    ///
    class Piece {
    private:
	// Piece ID character.
	char id;

	// Piece's shape.
	std::vector<Location> cubes[direction_count];

	// Whether the piece is put somewhere on the board.
	bool located;

	// Location of the piece, if the piece is put on the board.
	Location location;

	// Direction of the piece, if the piece is put on the board.
	Direction direction;

	// Information about symmetry of the shape.
	Direction symmetry_ids[direction_count];

	// Sort a vector of cubes.
	static void
	sort_cubes(std::vector<Location> &cubes);

	// Compare two vectors of cubes.
	// Return true if they are the same.
	static bool
	compare_cubes(std::vector<Location> &cubes1,
	    std::vector<Location> &cubes2);

	// Align locations of cubes to (0,0).
	static void
	canonicalize_cubes(std::vector<Location> &cubes);

	// Rotate a vector of cubes.
	static void
	rotate_cubes(std::vector<Location> &to_cubes,
	    std::vector<Location> &from_cubes, Direction direction);

    public:
	// A blank cube, in a piece shape string.
	static const char blank = '.';

	// The maximum number of characters in a line of file.
	static const int max_file_line_length = 256;

	///
	/// Default constructor.
	///
	Piece();

	///
	/// Constructor.
	///
	/// @param shape Shape of the piece.
	///
	/// Construct an object, call set_shape(shape).
	///
	Piece(const char *shape);

	///
	/// Constructor.
	///
	/// @param shape Shape of the piece.
	///
	/// Construct an object, call set_shape(shape).
	///
	Piece(const std::string &shape);

	///
	/// Examine whether the piece has a shape or not.
	///
	/// @return True if the piece has a shape.
	///
	bool
	has_shape() const;

	///
	/// Return the number of cubes in the piece.
	///
	/// @return The number of cubes.
	///
	std::size_t
	get_size() const;

	///
	/// Get location of the particular cube in the piece.
	///
	/// @param index Index of the cube in the piece (0 is the first).
	/// @param direction Direction of the piece.
	/// @return Location of the cube.
	///
	/// The member function returns location of a cube when
	/// the piece would be put on (0,0,0) in a board with 'direction'.
	///
	/// It causes std::out_of_range exception if 'index' or 'direction'
	/// is out of range
	///
	Location
	get_cube(std::size_t index, Direction direction) const;

	///
	/// Get piece ID.
	/// 
	/// @return Piece ID
	///
	char
	get_id() const;

	///
	/// Examine whether the piece is put on the board.
	///
	/// @return True if the piece is put on the board.
	///
	bool
	is_located() const;

	///
	/// Get symmetry ID of the current direction.
	///
	/// @return symmetry ID of the current direction.
	///
	/// This member function returns a symmetry ID of the current
	/// direction.  Symmetry ID represents symmetry information of
	/// the piece shape.  If its shape has symmetry,
	///
	///
	/// It causes std::logic_error exception if the piece has not
	/// been put on the board.
	/// 
	Direction
	get_symmetry_id() const;

	Direction
	get_symmetry_id(Direction direction_arg) const;

	///
	/// Get location of the piece on the board.
	///
	/// @return Location of the piece.
	///
	/// It causes std::logic_error exception if the piece has not
	/// been put on the board.
	///
	Location
	get_location() const;

	///
	/// Get direction of the piece on the board.
	///
	/// @return Direction of the piece.
	///
	/// It causes std::logic_error exception if the piece has not
	/// been put on the board.
	///
	Direction
	get_direction() const;

	///
	/// Put the piece on a board.
	///
	/// @param location_arg Location of the piece on a board.
	/// @param direction_arg Direction of the piece on a board.
	///
	/// It causes std::out_of_range exception if 'direction_arg' is
	/// out of range.
	///
	void
	locate(const Location &location_arg, Direction direction_arg);

	///
	/// Remove the piece from a board.
	///
	/// Nothing is done if the piece has not been put on a board yet.
	///
	void
	unlocate();

	///
	/// Set shape of the piece.
	///
	/// @param shape Shape of the piece.
	/// @return True if 'shape' is valid.
	///
	/// In the string, '.' means blank, and '\n' means the end of
	/// the row.  Any other characters means a cube of the piece.
	///
	bool
	set_shape(const char *shape);

	///
	/// Set shape of the piece.
	///
	/// @param shape Shape of the piece.
	/// @return True if 'shape' is valid.
	///
	bool
	set_shape(const std::string &shape);

	///
	/// Set shape of the piece, by reading a file.
	///
	/// @param file_name File on which shape of the piece is written.
	/// @return True if 'shape' is valid.
	///
	bool
	set_shape_by_file(const char *file_name);

	///
	/// Set shape of the piece, by reading a file.
	///
	/// @param file_name File on which shape of the piece is written.
	/// @return True if 'shape' is valid.
	///
	bool
	set_shape_by_file(const std::string &file_name);

	///
	/// Get location of a cube in the piece on the board.
	///
	/// @param index Index of the cube in the piece (0 is the first).
	/// @return Location of the cube.
	///
	/// The member function is the same as get_cube(), but it
	/// returns location on the board where the piece is currently
	/// located.  In other words, it returns get_cube() + 
	/// get_location().
	///
	/// It causes std::logic_error exception if the piece has not
	/// been put on the board. It causes std::out_of_range exception
	/// if 'index' is out of range.  
	///
	Location
	get_located_cube(std::size_t index) const;

	///
	/// Dump the shape of the piece.
	///
	/// @param direction_arg Direction of the piece.
	/// @return A string which shows shape of the piece.
	///
	std::string
	dump(Direction direction_arg) const;

	///
	/// Dump the shape of the piece.
	///
	/// @return A string which shows shape of the located piece.
	///
	std::string
	dump() const;
    };
}

#endif // UBONGO3D_PIECE_H
