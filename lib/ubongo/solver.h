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

#ifndef UBONGO_SOLVER_H
#define UBONGO_SOLVER_H

#include <vector>
#include "ubongo/puzzle.h"

namespace Ubongo {
    /// 
    /// Solution search for Ubongo.
    ///
    class Solver {
    private:
	// The puzzle to be solved.
	Puzzle puzzle;

	// The order of located pieces.
	std::vector<std::size_t> located_piece_indice;

	// The index of the piece the solver currently tries to put
	// on the board.
	std::size_t current_piece_index;

	// The direction with which the solver currently tries to put
	// the piece.
	Direction current_direction;

	// The location of the board where the solver currently tries
	// to put a piece.
	Location current_location;

	// Whether the search has been finished.
	bool complete;

	//
	// Put a piece with 'current_piece_index' on the board.
	//
	// Its direction is 'current_direction' and its location is
	// 'current_location'.
	//
	bool
	locate_piece();

	//
	// Remove a piece put on the board at the last time.
	//
	bool
	unlocate_last_piece();

	//
	// Give up put a piece with 'current_piece_index' onto the board.
	// Set 'current_piece_index' to next one.
	//
	bool
	next_piece();

	//
	// Set 'current_direction' to the next value.
	//
	bool
	next_direction();

	///
	/// Find a blank square on the board, next to 'current_location'.
	///
	bool
	next_location();

	//
	// Find the lowest blank square in the board.
	//
	bool
	find_location();

    public:
	///
	/// Default constructor.
	///
	Solver();

	///
	/// Constructor.
	///
	/// @param puzzle_arg A puzzle to be solved.
	///
	Solver(const Puzzle &puzzle_arg);

	///
	/// Return a puzzle object.
	///
	/// @return A puzzle object.
	///
	const Puzzle &
	get_puzzle() const;

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
	/// Whether pieces can be flipped or not.
	///
	/// @return True if pieces can be flipped.
	///
	bool
	get_piece_flip_flag() const;

	///
	/// Bind a puzzle to the solver.
	///
	/// @param puzzle_arg A puzzle to be solved.
	///
	void
	set_puzzle(const Puzzle &puzzle_arg);

	///
	/// Bind a board to the solver object.
	///
	/// @param board_arg Board of the puzzle.
	///
	void
	set_board(const Board &board_arg);

	///
	/// Bind pieces to the puzzle object in the solver.
	///
	/// @param pieces_arg Pieces of the puzzle.
	///
	void
	set_pieces(const Piece *pieces_arg, std::size_t piece_count);

	///
	/// Bind pieces to the solver object.
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
	/// Reset the solution search state.
	///
	void
	restart();

	///
	/// Try to find a solution of the bound puzzle.
	///
	/// @return True if it finds a solution.
	///
	/// A puzzle may have more than one solutions. To find all
	/// solutions, call this member function repeatedly until it
	/// returns false.
	///
	bool
	find_solution();

	///
	/// Examine whether the solution search has been finished.
	///
	/// @return True if solution search has be done.
	///
	bool
	is_complete() const;
    };
}

#endif // UBONGO_SOLVER_H
