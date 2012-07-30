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

#ifndef UBONGO3D_COMMON_H
#define UBONGO3D_COMMON_H

namespace Ubongo3d {
    ///
    /// Location (X,Y,Z) of a cube.
    ///
    /// Ubongo 3-D library assumes:
    ///    - The X axis is directed from left to right. 
    ///    - The Y axis is directed from top to bottom.
    ///    - The Z axis represents a level.
    /// That is to say the top left cube just on the board is (0,0,0).
    ///
    struct Location {
	int x;
	int y;
	int z;
    };

    ///
    /// Calcurate location1 + location2.
    ///
    inline Location
    operator +(const Location &location1, const Location &location2) {
	Location result = {location1.x + location2.x,
			   location1.y + location2.y,
			   location1.z + location2.z};
	return result;
    }

    ///
    /// Calcurate location1 - location2.
    ///
    inline Location
    operator -(const Location &location1, const Location &location2) {
	Location result = {location1.x - location2.x,
			   location1.y - location2.y,
			   location1.z - location2.z};
	return result;
    }

    ///
    /// Calcurate location1 += location2.
    ///
    inline Location &
    operator +=(Location &location1, const Location location2) {
	location1.x += location2.x;
	location1.y += location2.y;
	location1.z += location2.z;
	return location1;
    }

    ///
    /// Calcurate location1 -= location2.
    ///
    inline Location &
    operator -=(Location &location1, const Location location2) {
	location1.x -= location2.x;
	location1.y -= location2.y;
	location1.z -= location2.z;
	return location1;
    }

    ///
    /// Piece's directions.
    ///
    /// When a piece is put on the board, it can be rotated.
    /// The enumerated type represents directions of piece.
    ///
    /// 'direction_count' represents the number of directions.
    ///
    enum Direction {
	direction_00,
	direction_01,
	direction_02,
	direction_03,
	direction_04,
	direction_05,
	direction_06,
	direction_07,
	direction_08,
	direction_09,
	direction_10,
	direction_11,
	direction_12,
	direction_13,
	direction_14,
	direction_15,
	direction_16,
	direction_17,
	direction_18,
	direction_19,
	direction_20,
	direction_21,
	direction_22,
	direction_23,
        direction_count
    };
}

#endif // UBONGO3D_COMMON_H
