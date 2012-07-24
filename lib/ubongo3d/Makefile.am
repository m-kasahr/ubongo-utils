ubongo3dincludedir = $(includedir)/ubongo3d

lib_LTLIBRARIES = libubongo3d.la

libubongo3d_la_SOURCES = analyzer.cpp \
                         board.cpp \
                         piece.cpp \
                         pieceset.cpp \
                         puzzle.cpp \
                         solver.cpp
libubongo3d_la_CPPFLAGS = -I.. -I$(srcdir)/..
libubongo3d_la_LDFLAGS = -version-info $(LIBUBONGO3D_VERSION_INFO)

ubongo3dinclude_HEADERS = analyzer.h \
                          board.h \
                          common.h \
                          piece.h \
                          pieceset.h \
                          pieceset_3d.h \
                          puzzle.h \
                          solver.h

EXTRA_DIST = make-pieceset3d.rb

CLEANFILES = pieceset_3d.h

pieceset_3d.h: make-pieceset3d.rb
	rm -f $@
	$(RUBY) $(srcdir)/make-pieceset3d.rb 3d $(top_srcdir)/data/3d > $@
