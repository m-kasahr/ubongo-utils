ubongoincludedir = $(includedir)/ubongo

lib_LTLIBRARIES = libubongo.la

libubongo_la_SOURCES = analyzer.cpp \
                       board.cpp \
                       piece.cpp \
                       pieceset.cpp \
                       pieceset_dir.cpp \
                       puzzle.cpp \
                       solver.cpp

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
	$(RUBY) make-pieceset.rb Orig $(dataorig_srcdir) > $@

pieceset_duel.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb Duel $(dataduel_srcdir) > $@

pieceset_minib.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniB $(dataminib_srcdir) > $@

pieceset_minig.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniG $(dataminig_srcdir) > $@

pieceset_minir.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniR $(dataminir_srcdir) > $@

pieceset_miniy.h: make-pieceset.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset.rb MiniY $(dataminiy_srcdir) > $@
