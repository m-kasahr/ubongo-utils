ubongoincludedir = $(includedir)/ubongo

lib_LTLIBRARIES = libubongo.la

libubongo_la_SOURCES = analyzer.cpp \
                       board.cpp \
                       piece.cpp \
                       pieceset.cpp \
                       pieceset_dir.cpp \
                       puzzle.cpp \
                       solver.cpp
libubongo_la_LDFLAGS = -version-info $(LIBUBONGO_VERSION_INFO)

ubongoinclude_HEADERS = analyzer.h \
                        board.h \
                        common.h \
                        piece.h \
                        pieceset.h \
                        pieceset_dir.h \
                        pieceset_orig.h \
                        pieceset_duel.h \
                        pieceset_minib.h \
                        pieceset_minig.h \
                        pieceset_minir.h \
                        pieceset_miniy.h \
                        puzzle.h solver.h

EXTRA_DIST = make-pieceset.rb

CLEANFILES = pieceset_orig.h \
             pieceset_duel.h \
             pieceset_minib.h \
             pieceset_minig.h \
             pieceset_minir.h \
             pieceset_miniy.h

pieceset_orig.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb Orig $(top_srcdir)/data/orig > $@

pieceset_duel.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb Duel $(top_srcdir)/data/duel > $@

pieceset_minib.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniB $(top_srcdir)/data/minib > $@

pieceset_minig.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniG $(top_srcdir)/data/minig > $@

pieceset_minir.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniR $(top_srcdir)/data/minir > $@

pieceset_miniy.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniY $(top_srcdir)/data/miniy > $@
