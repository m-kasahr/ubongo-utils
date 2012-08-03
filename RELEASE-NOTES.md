RELEASE NOTES
=============

Version 1.1
-----------
* Add a test suite.
* Add 'ubongo-solve-dir' and 'ubongo-analyze-dir' commands.
* Explain 'ubongo-compare' command in the document.
* Add 'Ubongo::PieceSet_Dir' class.
* Add 'dump()' and dump(Direction)' methods to 'Ubongo::Piece' and 
  'Ubongo3d::Piece' classes.
* Add 'Board(const std::string &)' constructor,
  'set_shape(const std::string &)' method and
  'set_shape_by_file(const char *)' method to 'Ubongo::Board' and 
  'Ubongo3d::Board' classes.
* Change 'Analyzer(const Board &, const PieceSet &, int)' constructor of
  'Ubongo::Anayzer' and 'Ubongo3d::Anayzer' classes to
  'Analyzer(const Board &, const PieceSet &, size_t)'.
* Change 'set_components(const Board &, const PieceSet &, int)' method of
  'Ubongo::Anayzer' and 'Ubongo3d::Anayzer' classes to
  'set_components(const Board &, const PieceSet &, size_t)'.

Version 1.0
-----------
* Initial release.
