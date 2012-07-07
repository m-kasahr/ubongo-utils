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

#ifndef UBONGO3D_PIECESET_H
#define UBONGO3D_PIECESET_H

#include <string>
#include <vector>
#include "ubongo3d/common.h"
#include "ubongo3d/piece.h"

namespace Ubongo3d {
    /// 
    /// A piece-set used in Ubongo 3-D.
    ///
    class PieceSet {
    private:
	// Pieces.
	std::vector<Piece> pieces;

	// Mapping table from ID to piece.
	std::vector<Piece *> id_maps;

	// Whether pieces can be flipped or not.
	bool flip_flag;

	//
	// Reset 'id_maps'.
	//
	void
	reset_id_maps();

    public:
	///
	/// Default constructor.
	///
	PieceSet();

	///
	/// Constructor.
	///
	/// @param pieces_arg A set of pieces used in a puzzle.
	/// @param piece_count_arg The number of pieces.
	/// @param flip_flag_arg Whether pieces can be flipped or not.
	///
	PieceSet(const Piece *pieces_arg, size_t piece_count, 
	    bool flip_flag_arg);

	///
	/// Constructor.
	///
	/// @param pieces_arg A set of pieces used in a puzzle.
	/// @param flip_flag_arg Whether pieces can be flipped or not.
	///
	PieceSet(const std::vector<Piece> pieces_arg, bool flip_flag_arg);

	///
	/// Copy constructor.
	///
	/// @param source Source piece set.
	///
	PieceSet(const PieceSet &source);

	///
	/// Operator '='.
	///
	/// @param source Source piece set.
	///
	PieceSet &
	operator=(const PieceSet &source);

	///
	/// Set components of the piece set.
	///
	/// @param pieces_arg A set of pieces used in a puzzle.
	/// @param flip_flag_arg Whether pieces can be flipped or not.
	///
	void
	set_components(const Piece *pieces_arg, size_t piece_count, 
	    bool flip_flag_arg);

	///
	/// Set components of the piece set.
	///
	/// @param pieces_arg A set of pieces used in a puzzle.
	/// @param flip_flag_arg Whether pieces can be flipped or not.
	///
	void
	set_components(const std::vector<Piece> pieces_arg,
	    bool flip_flag_arg);

	///
	/// Get n'th piece of the piece-set.
	///
	/// @param n Index.
	///
	const Piece &
	at(std::size_t n) const;

	///
	/// Get n'th piece of the piece-set.
	///
	/// @param n Index.
	///
	const Piece &
	operator[](std::size_t n) const;

	///
	/// Get a piece with ID.
	///
	/// @param id Piece Id.
	///
	const Piece &
	get_piece_by_id(char id) const;

	///
	/// Get a piece with ID.
	///
	/// @param id Piece Id.
	///
	const Piece &
	get_piece_by_id(const char *id) const;

	///
	/// Get a piece with ID.
	///
	/// @param id Piece Id.
	///
	const Piece &
	get_piece_by_id(const std::string &id) const;

	//
	// Return true if pieces can be flipped.
	//
	bool
	get_flip_flag() const;

	//
	// Return the number of pieces in the piece set.
	//
	std::size_t
	size() const;
    };
}

#endif // UBONGO3D_PIECESET_H
