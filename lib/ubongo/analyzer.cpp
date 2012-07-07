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

#include "ubongo/analyzer.h"
#include "ubongo/solver.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace Ubongo {
    void
    Analyzer::reset_piece_indice() {
	if (piece_count > pieceset.size()) {
	    complete = true;
	    return;
	}

	//
	// Set 'piece_indice' to initial state.
	//
	// In case 'piece_count' is 3 and pieceset.size() is 5,
	// 'piece_indice' will be initialized as:
	//
	//     {0, 1, 2}
	//
	piece_indice.resize(piece_count);
	for (int i = 0; i < piece_count; i++)
	    piece_indice[i] = i;
    }

    Analyzer::Analyzer()
	: pieceset(),
	  piece_count(0),
	  piece_indice(0),
	  board_size(0),
	  solver(),
	  complete(true) {
    }

    Analyzer::Analyzer(const Board &board_arg, const PieceSet &pieceset_arg,
	int piece_count_arg)
	: pieceset(pieceset_arg),
	  piece_count(piece_count_arg),
	  piece_indice(piece_count_arg),
	  board_size(0),
	  solver(),
	  complete(false) {
	solver.set_board(board_arg);
	solver.set_piece_flip_flag(pieceset_arg.get_flip_flag());
	reset_piece_indice();
	board_size = solver.get_puzzle().get_board_size();
    }

    void
    Analyzer::set_components(const Board &board_arg,
	const PieceSet &pieceset_arg, int piece_count_arg) {
	complete = false;
	solver.set_board(board_arg);
	solver.set_piece_flip_flag(pieceset_arg.get_flip_flag());
	pieceset = pieceset_arg;
	piece_count = piece_count_arg;
	reset_piece_indice();
	board_size = solver.get_puzzle().get_board_size();
    }

    void
    Analyzer::restart() {
	complete = false;
	solver.restart();
	reset_piece_indice();
    }

    bool
    Analyzer::find_solvable_puzzle() {
	std::vector<Piece> selected_pieces(piece_count);

	while (!complete) {
	    //
	    // Select pieces.
	    //
	    int total_piece_size = 0;
	    for (int i = 0; i < piece_count; i++) {
		selected_pieces[i] = pieceset[piece_indice[i]];
		total_piece_size += selected_pieces[i].get_size();
	    }
	    
	    bool solved = false;
	    if (total_piece_size == board_size) {
		//
		// Try solving the puzzle.
		//
		solver.set_pieces(selected_pieces);
		solved = solver.find_solution();
	    }

	    //
	    // Step forward 'piece_indice'.
	    //
	    // In case 'piece_count' is 3 and pieceset.size() is 5,
	    // 'piece_indice' in this loop will be changed in
	    // the following steps:
	    //
	    //     {0, 1, 2}   -- set by reset_piece_indice()
	    //     {0, 1, 3}
	    //     {0, 1, 4}
	    //     {0, 2, 3}
	    //     {0, 2, 4}
	    //     {0, 3, 4}
	    //     {1, 2, 3}
	    //     {1, 2, 4}
	    //     {2, 3, 4}   -- comlete
	    //
	    int i = piece_count - 1;
	    if (piece_indice[i] + 1 < pieceset.size())
		piece_indice[i]++;
	    else {
		i--;
		while (i >= 0) {
		    if (piece_indice[i] + 1 < piece_indice[i + 1]) {
			int new_index = piece_indice[i] + 1;
			for (int j = i; j < piece_count; j++)
			    piece_indice[j] = new_index++;
			break;
		    }
		    i--;
		}
		if (i < 0)
		    complete = true;
	    }

	    if (solved)
		return true;
	}

	return false;
    }

    const Puzzle &
    Analyzer::get_puzzle() {
	return solver.get_puzzle();
    }

    bool
    Analyzer::find_next_solution() {
	return solver.find_solution();
    }

    bool
    Analyzer::is_complete() const {
	return complete;
    }
}
