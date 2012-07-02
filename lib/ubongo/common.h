
#ifndef UBONGO_COMMON_H
#define UBONGO_COMMON_H

namespace Ubongo {
    ///
    /// Location (X,Y) of a square.
    ///
    /// Ubongo library assumes the X axis is directed from left to right
    /// and the Y axis is directed from top to bottom.
    /// That is to say the top left square is (0,0).
    ///
    struct Location {
	int x;
	int y;
    };

    ///
    /// Calcurate location1 + location2.
    ///
    inline Location
    operator +(const Location &location1, const Location &location2) {
	Location result
	    = {location1.x + location2.x, location1.y + location2.y};
	return result;
    }

    ///
    /// Calcurate location1 - location2.
    ///
    inline Location
    operator -(const Location &location1, const Location &location2) {
	Location result
	    = {location1.x - location2.x, location1.y - location2.y};
	return result;
    }

    ///
    /// Calcurate location1 += location2.
    ///
    inline Location &
    operator +=(Location &location1, const Location location2) {
	location1.x += location2.x;
	location1.y += location2.y;
	return location1;
    }

    ///
    /// Calcurate location1 -= location2.
    ///
    inline Location &
    operator -=(Location &location1, const Location location2) {
	location1.x -= location2.x;
	location1.y -= location2.y;
	return location1;
    }

    ///
    /// Piece's directions.
    ///
    /// When a piece is put on the board, it can be rotated and/or flipped.
    /// The enumerated type represents directions of pieces.
    ///
    ///    right0:      #    mirror-right0:    #
    ///               ###                      ###
    ///
    ///    right90:   #      mirror-right90:   ##    
    ///               #                        #
    ///               ##                       #
    ///
    ///    right180:  ###    mirror-right180:  ###
    ///               #                          #
    ///
    ///    right270:  ##     mirror-right270:   #
    ///                #                        #
    ///                #                       ##
    ///
    /// 'right0' is the basic direction. The word 'mirror' in direction
    /// names means "flipped" from the basic direction. The word 'rightX'
    /// (X is 90, 180 or 270) in direction names means "rotated right X
    /// degrees" from the basic direction.
    ///
    /// 'direction_count' represents the number of directions.
    ///
    enum Direction {
	right0,
	right90,
	right180,
        right270,
        mirror_right0,
        mirror_right90,
        mirror_right180,
        mirror_right270,
        direction_count
    };
}

#endif // UBONGO_COMMON_H
