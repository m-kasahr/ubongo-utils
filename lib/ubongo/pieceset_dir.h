#ifndef UBONGO_PIECESET_DIR_H
#define UBONGO_PIECESET_DIR_H

#include <string>
#include "ubongo/pieceset.h"

namespace Ubongo {
    class PieceSet_Dir : public PieceSet {
	void
	scan_dir(const char *path, std::vector<Piece> &pieces,
	    bool &piece_flip_flag);

	PieceSet_Dir();

    public:
	static const size_t max_line_length = 256;

        PieceSet_Dir(const char *path);
        PieceSet_Dir(const std::string &path);
    };
}

#endif // UBONGO_PIECESET_DIR_HPP
