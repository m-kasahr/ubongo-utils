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
#include "ubongo3d/puzzle.h"

namespace Ubongo3d {
    void
    Puzzle::unlocate_pieces() {
	std::vector<Piece>::iterator it = pieces.begin();
	while (it != pieces.end()) {
	    it->unlocate();
	    it++;
	}
    }

    Puzzle::Puzzle()
	: board(), pieces() {
    }

    Puzzle::Puzzle(const Board &board_arg, const Piece *pieces_arg,
	std::size_t piece_count, bool piece_flip_flag_arg)
	: board(), pieces(), piece_flip_flag(true) {
	set_board(board_arg);
	set_pieces(pieces_arg, piece_count);
	set_piece_flip_flag(piece_flip_flag_arg);
    }

    Puzzle::Puzzle(const Board &board_arg, std::vector<Piece> &pieces_arg,
	bool piece_flip_flag_arg)
	: board(), pieces(), piece_flip_flag(true) {
	set_board(board_arg);
	set_pieces(pieces_arg);
	set_piece_flip_flag(piece_flip_flag_arg);
    }

    const Board &
    Puzzle::get_board() const {
	return board;
    }

    const int
    Puzzle::get_board_width() const {
	return board.get_width();
    }

    const int
    Puzzle::get_board_height() const {
	return board.get_height();
    }

    const int
    Puzzle::get_board_depth() const {
	return board.get_depth();
    }

    const int
    Puzzle::get_board_size() const {
	return board.get_cube_count();
    }

    const std::vector<Piece> &
    Puzzle::get_pieces() const {
	return pieces;
    }

    std::size_t
    Puzzle::get_piece_count() const {
	return pieces.size();
    }

    const Piece &
    Puzzle::get_piece(std::size_t index) const {
	if (index < 0 || (std::size_t) index >= pieces.size())
	    throw std::out_of_range("Ubongo3d::Puzzle::get_piece");
	return pieces[index];
    }

    bool
    Puzzle::get_piece_flip_flag() const {
	return piece_flip_flag;
    }

    void
    Puzzle::set_components(const Board &board_arg, const Piece *pieces_arg,
	std::size_t piece_count, bool piece_flip_flag_arg) {
	set_board(board_arg);
	set_pieces(pieces_arg, piece_count);
	set_piece_flip_flag(piece_flip_flag_arg);
    }

    void
    Puzzle::set_components(const Board &board_arg,
	const std::vector<Piece> &pieces_arg, bool piece_flip_flag_arg) {
	set_board(board_arg);
	set_pieces(pieces_arg);
	set_piece_flip_flag(piece_flip_flag_arg);
    }

    void
    Puzzle::set_board(const Board &board_arg) {
	board = board_arg;
	board.restart();
    }

    void
    Puzzle::set_pieces(const Piece *pieces_arg, std::size_t piece_count) {
	pieces.clear();
	for (std::size_t i = 0; i < piece_count; i++)
	    pieces.push_back(pieces_arg[i]);
	unlocate_pieces();
    }

    void
    Puzzle::set_pieces(const std::vector<Piece> &pieces_arg) {
	pieces = pieces_arg;
	unlocate_pieces();
    }

    void
    Puzzle::set_piece_flip_flag(bool piece_flip_flag_arg) {
	piece_flip_flag = piece_flip_flag_arg;
    }
	
    void
    Puzzle::restart() {
	board.restart();
	unlocate_pieces();
    }

    bool
    Puzzle::is_complete() const {
	return board.is_complete();
    }

    bool
    Puzzle::locate_piece(std::size_t index, const Location &location,
	Direction direction) {
	if (index < 0 || index >= pieces.size())
	    throw std::out_of_range("Ubongo3d:Puzzle::locate_piece");
	if (pieces[index].is_located())
	    throw std::logic_error("Ubongo3d:Puzzle::locate_piece");

	if (!board.locate_piece(pieces[index], location, direction))
	    return false;

 	pieces[index].locate(location, direction);
	return true;
    }

    bool
    Puzzle::unlocate_piece(std::size_t index) {
	if (index < 0 || index >= pieces.size())
	    throw std::out_of_range("Ubongo3d:Puzzle::unlocate_piece");
	if (!pieces[index].is_located())
	    throw std::logic_error("Ubongo3d:Puzzle::unlocate_piece");

	board.unlocate_piece(pieces[index]);
 	pieces[index].unlocate();
	return true;
    }

    bool
    Puzzle::is_located_piece(std::size_t index) const {
	if (index < 0 || (std::size_t) index >= pieces.size())
	    throw std::out_of_range("Ubongo3d::Puzzle::is_located_piece");
	return pieces[index].is_located();
    }

    char
    Puzzle::get_board_cube(const Location &location) const {
	return board.get_cube(location);
    }

    std::string
    Puzzle::dump_board() const {
	return board.dump();
    }
}
