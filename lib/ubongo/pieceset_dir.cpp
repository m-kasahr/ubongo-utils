//                                                            -*- C++ -*-
// Copyright (c) 2012  Motoyuki Kasahara
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

extern "C" {
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
}

#include <cstring>
#include <fstream>
#include <vector>
#include "ubongo/pieceset_dir.h"

namespace Ubongo {
    void
    PieceSet_Dir::scan_dir(const char *path, std::vector<Piece> &pieces,
	bool &piece_flip_flag) {
	DIR *dir = ::opendir(path);
	if (dir == NULL)
	    return;

	for (;;) {
	    struct dirent *dirent = ::readdir(dir);
	    if (dirent == NULL)
		break;

	    std::string filepath = path;
	    filepath += "/";
	    filepath += dirent->d_name;

	    struct stat st;
	    if (::stat(filepath.c_str(), &st) < 0)
		continue;
	    if (!S_ISREG(st.st_mode))
		continue;

	    if (dirent->d_name[0] != '\0' &&
		std::strcmp(dirent->d_name + 1, ".piece") == 0) {
		Piece new_piece;
		new_piece.set_shape_by_file(filepath);
		pieces.push_back(new_piece);
	    } else if (std::strcmp(dirent->d_name, "piece-flip-flag") == 0) {
		std::fstream fs;
		fs.open(filepath.c_str(), std::ios::in);
		if (!fs.is_open())
		    continue;

		std::string shape;
		char line[max_line_length];
		if (fs.getline(line, sizeof(line)))
		    piece_flip_flag = (std::strcmp(line, "false") != 0);

		fs.close();
	    }
	}
	::closedir(dir);
    }

    PieceSet_Dir::PieceSet_Dir()
	: PieceSet() {
    }

    PieceSet_Dir::PieceSet_Dir(const char *path)
	: PieceSet() {
	std::vector<Piece> pieces;
	bool piece_flip_flag;
	scan_dir(path, pieces, piece_flip_flag);
	set_components(pieces, piece_flip_flag);
    }

    PieceSet_Dir::PieceSet_Dir(const std::string &path)
	: PieceSet() {
	std::vector<Piece> pieces;
	bool piece_flip_flag;
	scan_dir(path.c_str(), pieces, piece_flip_flag);
	set_components(pieces, piece_flip_flag);
    }
}
	
