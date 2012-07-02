
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
