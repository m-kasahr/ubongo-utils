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

#ifndef UBONGO3D_PUZZLE_H
#define UBONGO3D_PUZZLE_H

#include <string>
#include <vector>
#include "ubongo3d/common.h"
#include "ubongo3d/piece.h"
#include "ubongo3d/board.h"

namespace Ubongo3d {
    /// 
    /// A puzzle of Ubongo 3-D.
    ///
    /// The object just consists of a board and pieces.
    ///
    class Puzzle {
    private:
	/// The board used in the puzzle.
	Board board;

	/// The pieces used in the puzzle.
	std::vector<Piece> pieces;

	/// Pieces can be flipped or not.
	bool piece_flip_flag;

	//
	// Unlocate pieces from the board.
	//
	void
	unlocate_pieces();

    public:
	///
	/// Default constructor.
	///
	Puzzle();

	///
	/// Constructor.
	///
	/// @param board_arg Board of the puzzle.
	/// @param pieces_arg Pieces of the puzzle.
	/// @param piece_count The number of pieces in 'pieces_arg'.
	/// @param piece_flip_flag_arg Whether pieces can be flipped or not.
	///
	/// The Puzzle object creates copies of 'board_arg' and
	/// 'pieces_args' and holds them.  After return, it never
	/// accesses 'board_arg' or 'pieces_args' object directly.
	///
	Puzzle(const Board &board_arg, const Piece *pieces_arg,
	    std::size_t piece_count, bool piece_flip_flag_arg);

	///
	/// Constructor.
	///
	/// @param board_arg Board of the puzzle.
	/// @param pieces_arg Pieces of the puzzle.
	/// @param piece_flip_flag_arg Whether pieces can be flipped or not.
	///
	/// The puzzle object creates copies of 'board_arg' and
	/// 'pieces_args' and holds them.  After return it never
	/// accesses 'board_arg' or 'pieces_args' object directly.
	///
	Puzzle(const Board &board_arg, std::vector<Piece> &pieces_arg,
	    bool piece_flip_flag_arg);

	///
	/// Return the Board object.
	///
	/// @return the Board object.
	///
	const Board &
	get_board() const;

	///
	/// Return width of the board.
	///
	/// @return Width of the board.
	///
	/// It is equivalent to 'get_board().get_width()'.
	///
	const int
	get_board_width() const;

	///
	/// Return height of the board.
	///
	/// @return Height of the board.
	///
	/// It is equivalent to 'get_board().get_height()'.
	///
	const int
	get_board_height() const;

	///
	/// Return depth of the board.
	///
	/// @return Depth of the board.
	///
	/// It is equivalent to 'get_board().get_depth()'.
	///
	const int
	get_board_depth() const;

	///
	/// Return the number of cubes in tbe board.
	///
	/// @return Size of the board.
	///
	/// It is equivalent to 'get_board().get_cube_count()'.
	///
	const int
	get_board_size() const;

	///
	/// Return pieces used in the puzzle.
	///
	/// @return Pieces of the puzzle.
	///
	const std::vector<Piece> &
	get_pieces() const;

	///
	/// Return the number of pieces used in the puzzle.
	///
	/// @return The number of pieces.
	///
	std::size_t
	get_piece_count() const;

	///
	/// Return a piece object.
	///
	/// @param index Index of the piece (0...piece_count - 1).
	/// @return A piece object.
	///
	/// It causes std::out_of_range exception if 'index' is out
	/// of range.  
	///
	const Piece &
	get_piece(std::size_t index) const;

	///
	/// Whether pieces can be flipped or not.
	///
	/// @return True if pieces can be flipped.
	///
	bool
	get_piece_flip_flag() const;

	///
	/// Bind a board and pieces to the puzzle object.
	///
	/// @param board_arg Board of the puzzle.
	/// @param pieces_arg Pieces of the puzzle.
	/// @param piece_count The number of pieces in 'pieces_arg'.
	/// @param piece_flip_flag_arg Whether pieces can be flipped or not.
	///
	/// The Puzzle object creates copies of 'board_arg' and
	/// 'pieces_args' and holds them.  After return, it never
	/// accesses 'board_arg' or 'pieces_args' object directly.
	///
	void
	set_components(const Board &board_arg, const Piece *pieces_arg,
	    std::size_t piece_count, bool piece_flip_flag_arg);

	///
	/// Bind a board and pieces to the puzzle object.
	///
	/// @param board_arg Board of the puzzle.
	/// @param pieces_arg Pieces of the puzzle.
	/// @param piece_flip_flag_arg Whether pieces can be flipped or not.
	///
	/// The Puzzle object creates copies of 'board_arg' and
	/// 'pieces_args' and holds them.
	///
	void
	set_components(const Board &board_arg,
	    const std::vector<Piece> &pieces_arg, bool piece_flip_flag_arg);

	///
	/// Bind a board to the puzzle object.
	///
	/// @param board_arg Board of the puzzle.
	///
	/// The Puzzle object creates copies of 'board_arg' and hold it.
	///
	void
	set_board(const Board &board_arg);

	///
	/// Bind pieces to the puzzle object.
	///
	/// @param pieces_arg Pieces of the puzzle.
	///
	/// The Puzzle object creates copies of 'pieces_arg' and hold it.
	///
	void
	set_pieces(const Piece *pieces_arg, std::size_t piece_count);

	///
	/// Bind pieces to the puzzle object.
	///
	/// @param pieces_arg Pieces of the puzzle.
	/// @param piece_count The number of pieces in 'pieces_arg'.
	///
	/// The Puzzle object creates copies of 'pieces_arg' and hold it.
	///
	void
	set_pieces(const std::vector<Piece> &pieces_arg);

	///
	/// Set piece-flip flag.
	///
	/// @param piece_flip_flag_arg Whether pieces can be flipped or not.
	///
	void
	set_piece_flip_flag(bool piece_flip_flag_arg);
	
	///
	/// Restart the puzzle.
	///
	/// All pieces removed from the board.
	///
	void
	restart();

	///
	/// Examine whether the puzzle is completed.
	///
	/// @return True if the puzzle is completed.
	///
	bool
	is_complete() const;

	///
	/// Put a piece on the board.
	///
	/// @param index Piece's index.
	/// @param location Piece's location on the board.
	/// @param direction Piece's direction.
	/// @return Upon success, true is returned.
	///
	/// It causes std::logic_error exception if the piece has already
	/// been put on the board. It causes std::out_of_range exception
	/// if 'index' or 'direction' is out of range.  
	///
	bool
	locate_piece(std::size_t index, const Location &location,
	    Direction direction);

	///
	/// Remove a piece from the board.
	///
	/// @param index Piece's index.
	/// @return Upon success, true is returned.
	///
	/// It causes std::logic_error exception if the piece has not
	/// been put on the board. It causes std::out_of_range exception
	/// if 'index' is out of range.  
	///
	bool
	unlocate_piece(std::size_t index);

	///
	/// Examine whether the given piece is located on the board.
	///
	/// @param index Piece's index.
	/// @return True if the piece is located.
	/// 
	/// It is equivalent to 'get_piece(i).is_located()'.
	/// It causes std::out_of_range exception if 'index' is out
	/// of range.  
	///
	bool
	is_located_piece(std::size_t index) const;

	///
	/// Get status of the particular cube in the board.
	/// 
	/// @param location Location of the cube.
	/// @return The status of the cube; blank, unavailable or piece ID.
	/// 
	/// It is equivalent to 'get_board().get_cube(location)'.
	///
	char
	get_board_cube(const Location &location) const;

	///
	/// Dump the current status of cubes in the board.
	///
	/// @return A string which shows status of cubes.
	///
	/// It is equivalent to get_board().dump().
	///
	std::string
	dump_board() const;
    };
}

#endif // UBONGO3D_PUZZLE_H
