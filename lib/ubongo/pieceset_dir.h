#ifndef UBONGO_PIECESET_READDIR_H
#define UBONGO_PIECESET_READDIR_H

#include <string>
#include "ubongo/pieceset.h"

namespace Ubongo {
    class PieceSet_ReadDir : public PieceSet {
	void
	scan_dir(const char *path, std::vector<Piece> &pieces,
	    bool &piece_flip_flag);

	PieceSet_ReadDir();

    public:
	static const size_t max_line_length = 256;

        PieceSet_ReadDir(const char *path);
        PieceSet_ReadDir(const std::string &path);
    };
}

#endif // UBONGO_PIECESET_READDIR_HPP
