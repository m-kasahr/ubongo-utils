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

#include <stdexcept>
#include "ubongo/solver.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace Ubongo {
    bool
    Solver::locate_piece() {
	const Piece &current_piece = puzzle.get_piece(current_piece_index);
	Location location = current_location
	    - current_piece.get_square(0, current_direction);

	if (!puzzle.locate_piece(current_piece_index, location,
		current_direction))
	    return false;

	located_piece_indice.push_back(current_piece_index);
	if (located_piece_indice.size() == puzzle.get_piece_count())
	    return true;

	current_direction = right0;
	current_piece_index = 0;
	while (current_piece_index < puzzle.get_piece_count()) {
	    if (!puzzle.is_located_piece(current_piece_index))
		break;
	    current_piece_index++;
	}

	return next_location();
    }

    bool
    Solver::unlocate_last_piece() {
	if (located_piece_indice.empty())
	    return false;

	current_piece_index = located_piece_indice.back();
	current_direction
	    = puzzle.get_piece(current_piece_index).get_direction();
	located_piece_indice.pop_back();

	if (!puzzle.unlocate_piece(current_piece_index))
	    throw std::logic_error("Ubongo::Solver::unlocate_last_piece");
	if (!find_location())
	    throw std::logic_error("Ubongo::Solver::unlocate_last_piece");

	if (next_direction())
	    return true;
	return next_piece();
    }

    bool
    Solver::next_piece() {
	current_direction = right0;

	for (;;) {
	    current_piece_index++;
	    if (current_piece_index >= puzzle.get_piece_count())
		return false;
	    if (!puzzle.is_located_piece(current_piece_index))
		return true;
	}

	return false; // not reached.
    }

    bool
    Solver::next_direction() {
	const Piece &current_piece = puzzle.get_piece(current_piece_index);

	int dir;
	for (dir = current_direction + 1; dir < direction_count; dir++) {
	    if (current_piece.get_symmetry((Direction)dir) == dir) {
		current_direction = (Direction)dir;
		break;
	    }
	}
	if (dir >= direction_count)
	    return false;

	if (!puzzle.get_piece_flip_flag()) {
	    if (current_direction == mirror_right0
		|| current_direction == mirror_right90
		|| current_direction == mirror_right180
		|| current_direction == mirror_right270)
		return false;
	}

	return true;
    }

    bool
    Solver::next_location() {
	for (;;) {
	    if (current_location.x + 1 < puzzle.get_board_width()) {
		current_location.x++;
	    } else if (current_location.y + 1 < puzzle.get_board_height()) {
		current_location.x = 0;
		current_location.y++;
	    } else {
		return false;
	    }

	    if (puzzle.get_board_square(current_location) == Board::blank)
		return true;
	}

	return false; // not reached.
    }

    bool
    Solver::find_location() {
	current_location.x = 0;
	current_location.y = 0;
	if (puzzle.get_board_square(current_location) == Board::blank)
	    return true;

	if (next_location())
	    return true;

	return false;
    }

    Solver::Solver()
	: puzzle(),
	  located_piece_indice(),
	  current_piece_index(0),
	  current_direction(right0),
	  current_location(),
	  complete(false) {
    }

    Solver::Solver(const Puzzle &puzzle_arg)
	: puzzle(puzzle_arg),
	  located_piece_indice(),
	  current_piece_index(0),
	  current_direction(right0),
	  current_location(),
	  complete(false) {
	located_piece_indice.resize(puzzle.get_piece_count());
	restart();
    }

    const Puzzle &
    Solver::get_puzzle() const {
	return puzzle;
    }

    const std::vector<Piece> &
    Solver::get_pieces() const {
	return puzzle.get_pieces();
    }

    std::size_t
    Solver::get_piece_count() const {
	return puzzle.get_piece_count();
    }

    bool
    Solver::get_piece_flip_flag() const {
	return puzzle.get_piece_flip_flag();
    }

    void
    Solver::set_puzzle(const Puzzle &puzzle_arg) {
	puzzle = puzzle_arg;
	located_piece_indice.resize(puzzle.get_piece_count());
	restart();
    }

    void
    Solver::set_board(const Board &board_arg) {
	puzzle.set_board(board_arg);
	restart();
    }

    void
    Solver::set_pieces(const Piece *pieces_arg, std::size_t piece_count) {
	puzzle.set_pieces(pieces_arg, piece_count);
	restart();
    }

    void
    Solver::set_pieces(const std::vector<Piece> &pieces_arg) {
	puzzle.set_pieces(pieces_arg);
	restart();
    }

    void
    Solver::set_piece_flip_flag(bool piece_flip_flag_arg) {
	puzzle.set_piece_flip_flag(piece_flip_flag_arg);
	restart();
    }

    void
    Solver::restart() {
	complete = false;
	puzzle.restart();

	located_piece_indice.clear();
	current_piece_index = 0;
	if (!find_location())
	    complete = true;
	current_direction = right0;

	int total_piece_size = 0;
	for (std::size_t i = 0; i < puzzle.get_piece_count(); i++)
	    total_piece_size += puzzle.get_piece(i).get_size();
	if (total_piece_size != puzzle.get_board().get_blank_count())
	    complete = true;
    }

    bool
    Solver::find_solution() {
	if (complete)
	    return false;

	if (located_piece_indice.size() >= puzzle.get_piece_count()) {
	    unlocate_last_piece();
	    for (;;) {
		if (unlocate_last_piece())
		    break;
		if (located_piece_indice.empty()) {
		    complete = true;
		    return false;
		}
	    }
#ifdef DEBUG
	    std::cout << puzzle.dump_board();
#endif
	}
	    
	for (;;) {
	    bool located = false;
	    for (;;) {
#ifdef DEBUG
		std::cout << "location(" << current_location.x << ","
			  << current_location.y << "), ";
		std::cout << "piece(" << current_piece_index << "), ";
		std::cout << "direction(" << current_direction << ")\n";
#endif
		if (locate_piece()) {
		    located = true;
		    break;
		}
		if (!next_direction())
		    break;
	    }

	    if (located) {
#ifdef DEBUG
		std::cout << puzzle.dump_board();
#endif
		if (located_piece_indice.size() >= puzzle.get_piece_count())
		    return true;
	    } else {
		if (!next_piece()) {
		    for (;;) {
			if (unlocate_last_piece())
			    break;
			if (located_piece_indice.empty()) {
			    complete = true;
			    return false;
			}
		    }
#ifdef DEBUG
		    std::cout << puzzle.dump_board();
#endif
		}
	    } 
	}

	return false; // not reached.
    }

    bool
    Solver::is_complete() const {
	return complete;
    }
}
