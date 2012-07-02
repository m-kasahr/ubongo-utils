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

#ifndef UBONGO_ANALYZER_H
#define UBONGO_ANALYZER_H

#include <vector>
#include "ubongo/board.h"
#include "ubongo/pieceset.h"
#include "ubongo/puzzle.h"
#include "ubongo/solver.h"

namespace Ubongo {
    /// 
    /// Solution analyzer for Ubongo.
    ///
    class Analyzer {
    private:
	// Piece set.
	PieceSet pieceset;

	// The number of pieces placing on the board.
	int piece_count;

	// Pieces currently placed on the board.
	std::vector<int> piece_indice;

	// The number of squares on the board.
	int board_size;

	// Puzzle solver.
	Solver solver;

	// Whether the analysis has been finished.
	bool complete;

	//
	// Reset piece_indice to the initial state.
	//
	void
	reset_piece_indice();

    public:
	///
	/// Default constructor.
	///
	Analyzer();

	///
	/// Constructor.
	///
	/// @param board_arg A board to be analyzed.
	/// @param pieceset_arg A set of pieces.
	/// @param piece_count_arg The number of pieces placing on the board.
	///
	Analyzer(const Board &board_arg, const PieceSet &pieceset_arg,
	    int piece_count_arg);

	///
	/// Set components.
	///
	/// @param board_arg A board to be analyzed.
	/// @param pieceset_arg A set of pieces.
	/// @param piece_count_arg The number of pieces placing on the board.
	///
	void
	set_components(const Board &board_arg, const PieceSet &pieceset_arg,
	    int piece_count_arg);

	///
	/// Reset the analysis.
	///
	void
	restart();

	///
	/// Try to find a solvable puzzle.
	///
	/// @return True if it finds a solvable puzzle.
	///
	/// Call get_puzzle() to get an object which represents the 
	/// found puzzle.  There may be more than one solvable puzzles.
	/// To find all solvable puzzles, call this member function
	/// repeatedly until it returns false.
	///
	bool
	find_solvable_puzzle();

	///
	/// Get a solvable puzzle.
	///
	/// @return A solvable puzzle found by find_solvable_puzzle().
	///
	const Puzzle &
	get_puzzle();

	///
	/// Try to find more solution of the current puzzle.
	///
	/// @return True if it finds a solution.
	///
	bool
	find_next_solution();

	///
	/// Examine whether the analysis has been finished.
	///
	/// @return True if solution analysis has be done.
	///
	bool
	is_complete() const;
    };
}

#endif // UBONGO_ANALYZER_H
