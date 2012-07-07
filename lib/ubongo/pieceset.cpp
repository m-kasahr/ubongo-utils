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

#include <climits>
#include <cstring>
#include <stdexcept>
#include "ubongo/pieceset.h"

namespace Ubongo {
    void
    PieceSet::reset_id_maps() {
	for (std::size_t i = 0; i < (1 << CHAR_BIT); i++)
	    id_maps[i] = NULL;
	for (std::size_t i = 0; i < pieces.size(); i++)
	    id_maps[static_cast<size_t>(pieces[i].get_id())] = &pieces[i];
    }

    PieceSet::PieceSet()
	: pieces(), id_maps(1 << CHAR_BIT), flip_flag(true) {
    }

    PieceSet::PieceSet(const Piece *pieces_arg, size_t piece_count, 
	bool flip_flag_arg)
	: pieces(piece_count),
	  id_maps(1 << CHAR_BIT),
	  flip_flag(flip_flag_arg) {
	for (std::size_t i = 0; i < piece_count; i++)
	    pieces[i] = pieces_arg[i];
	reset_id_maps();
    }

    PieceSet::PieceSet(const std::vector<Piece> pieces_arg, bool flip_flag_arg)
	: pieces(pieces_arg.size()),
	  id_maps(1 << CHAR_BIT),
	  flip_flag(flip_flag_arg) {
	for (std::size_t i = 0; i < pieces_arg.size(); i++)
	    pieces[i] = pieces_arg[i];
	reset_id_maps();
    }

    PieceSet::PieceSet(const PieceSet &source)
	: pieces(source.pieces),
	  id_maps(1 << CHAR_BIT),
	  flip_flag(source.flip_flag) {
	reset_id_maps();
    }

    PieceSet &
    PieceSet::operator=(const PieceSet &source) {
	if (this == &source)
	    return *this;
	pieces = source.pieces;
	flip_flag = source.flip_flag;
	reset_id_maps();
    }

    void
    PieceSet::set_components(const Piece *pieces_arg, size_t piece_count, 
	bool flip_flag_arg) {
	pieces.resize(piece_count);
	for (std::size_t i = 0; i < piece_count; i++)
	    pieces[i] = pieces_arg[i];
	reset_id_maps();
	flip_flag = flip_flag_arg;
    }

    void
    PieceSet::set_components(const std::vector<Piece> pieces_arg,
	bool flip_flag_arg) {
	pieces.resize(pieces_arg.size());
	for (std::size_t i = 0; i < pieces_arg.size(); i++)
	    pieces[i] = pieces_arg[i];
	reset_id_maps();
	flip_flag = flip_flag_arg;
    }

    const Piece &
    PieceSet::at(std::size_t n) const {
	return pieces.at(n);
    }

    const Piece &
    PieceSet::operator[](std::size_t n) const {
	return pieces[n];
    }

    const Piece &
    PieceSet::get_piece_by_id(char id) const {
	Piece *piece = id_maps[static_cast<size_t>(id)];
	if (piece == NULL)
	    throw std::out_of_range("Ubongo::PieceSet::get_piece_by_id");
	return *piece;
    }

    const Piece &
    PieceSet::get_piece_by_id(const char *id) const {
	if (std::strlen(id) != 1)
	    throw std::invalid_argument("Ubongo::PieceSet::get_piece_by_id");

	Piece *piece = id_maps[static_cast<size_t>(*id)];
	if (piece == NULL)
	    throw std::out_of_range("Ubongo::PieceSet::get_piece_by_id");
	return *piece;
    }

    const Piece &
    PieceSet::get_piece_by_id(const std::string &id) const {
	if (id.size() != 1)
	    throw std::invalid_argument("Ubongo::PieceSet::get_piece_by_id");

	Piece *piece = id_maps[static_cast<size_t>(id[0])];
	if (piece == NULL)
	    throw std::out_of_range("Ubongo::PieceSet::get_piece_by_id");
	return *piece;
    }

    bool
    PieceSet::get_flip_flag() const {
	return flip_flag;
    }

    std::size_t
    PieceSet::size() const {
	return pieces.size();
    }
}
