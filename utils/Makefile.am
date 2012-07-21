bin_PROGRAMS = ubongo-solve-orig \
               ubongo-solve-duel \
               ubongo-solve-minib \
               ubongo-solve-minig \
               ubongo-solve-minir \
               ubongo-solve-miniy \
               ubongo-solve-dir \
               ubongo-solve-3d \
               ubongo-analyze-orig \
               ubongo-analyze-duel \
               ubongo-analyze-minib \
               ubongo-analyze-minig \
               ubongo-analyze-minir \
               ubongo-analyze-miniy \
               ubongo-analyze-dir \
               ubongo-analyze-3d

bin_SCRIPTS = ubongo-draw \
              ubongo-html-orig \
              ubongo-html-duel \
              ubongo-html-minib \
              ubongo-html-minig \
              ubongo-html-minir \
              ubongo-html-miniy \
              ubongo-html-3d \
              ubongo-compare

if COND_GETOPT
GETOPT_LDADD = 
else
GETOPT_LDADD = getopt.lo
endif

ubongo_solve_orig_SOURCES = ubongo-solve-orig.cpp
ubongo_solve_orig_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_orig_LDADD = $(GETOPT_LDADD) \
                           $(top_builddir)/lib/ubongo/libubongo.la
ubongo_solve_orig_LDFLAGS = -rpath $(libdir)

ubongo_solve_duel_SOURCES = ubongo-solve-duel.cpp
ubongo_solve_duel_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_duel_LDADD = $(GETOPT_LDADD) \
                           $(top_builddir)/lib/ubongo/libubongo.la
ubongo_solve_duel_LDFLAGS = -rpath $(libdir)

ubongo_solve_minib_SOURCES = ubongo-solve-minib.cpp
ubongo_solve_minib_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_minib_LDADD = $(GETOPT_LDADD) \
                            $(top_builddir)/lib/ubongo/libubongo.la
ubongo_solve_minib_LDFLAGS = 

ubongo_solve_minig_SOURCES = ubongo-solve-minig.cpp
ubongo_solve_minig_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_minig_LDADD = $(GETOPT_LDADD) \
                           $(top_builddir)/lib/ubongo/libubongo.la
ubongo_solve_minig_LDFLAGS = -rpath $(libdir)

ubongo_solve_minir_SOURCES = ubongo-solve-minir.cpp
ubongo_solve_minir_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_minir_LDADD = $(GETOPT_LDADD) \
                           $(top_builddir)/lib/ubongo/libubongo.la
ubongo_solve_minir_LDFLAGS = -rpath $(libdir)

ubongo_solve_miniy_SOURCES = ubongo-solve-miniy.cpp
ubongo_solve_miniy_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_miniy_LDADD = $(GETOPT_LDADD) \
                           $(top_builddir)/lib/ubongo/libubongo.la
ubongo_solve_miniy_LDFLAGS = -rpath $(libdir)

ubongo_solve_dir_SOURCES = ubongo-solve-dir.cpp
ubongo_solve_dir_CPPFLAGS = -DUBONGO_SOLVE_DIR \
                            -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_dir_LDADD = $(GETOPT_LDADD) \
                         $(top_builddir)/lib/ubongo/libubongo.la
ubongo_solve_dir_LDFLAGS = -rpath $(libdir)

ubongo_solve_3d_SOURCES = ubongo-solve-3d.cpp
ubongo_solve_3d_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_solve_3d_LDADD = $(GETOPT_LDADD) \
                        $(top_builddir)/lib/ubongo3d/libubongo3d.la
ubongo_solve_3d_LDFLAGS = -rpath $(libdir)

ubongo_analyze_orig_SOURCES = ubongo-analyze-orig.cpp
ubongo_analyze_orig_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_orig_LDADD = $(GETOPT_LDADD) \
                            $(top_builddir)/lib/ubongo/libubongo.la
ubongo_analyze_orig_LDFLAGS = -rpath $(libdir)

ubongo_analyze_duel_SOURCES = ubongo-analyze-duel.cpp
ubongo_analyze_duel_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_duel_LDADD = $(GETOPT_LDADD) \
                            $(top_builddir)/lib/ubongo/libubongo.la
ubongo_analyze_duel_LDFLAGS = -rpath $(libdir)

ubongo_analyze_minib_SOURCES = ubongo-analyze-minib.cpp
ubongo_analyze_minib_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_minib_LDADD = $(GETOPT_LDADD) \
                             $(top_builddir)/lib/ubongo/libubongo.la
ubongo_analyze_minib_LDFLAGS = -rpath $(libdir)

ubongo_analyze_minig_SOURCES = ubongo-analyze-minig.cpp
ubongo_analyze_minig_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_minig_LDADD = $(GETOPT_LDADD) \
                             $(top_builddir)/lib/ubongo/libubongo.la
ubongo_analyze_minig_LDFLAGS = -rpath $(libdir)

ubongo_analyze_minir_SOURCES = ubongo-analyze-minir.cpp
ubongo_analyze_minir_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_minir_LDADD = $(GETOPT_LDADD) \
                             $(top_builddir)/lib/ubongo/libubongo.la
ubongo_analyze_minir_LDFLAGS = -rpath $(libdir)

ubongo_analyze_miniy_SOURCES = ubongo-analyze-miniy.cpp
ubongo_analyze_miniy_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_miniy_LDADD = $(GETOPT_LDADD) \
                             $(top_builddir)/lib/ubongo/libubongo.la
ubongo_analyze_miniy_LDFLAGS = -rpath $(libdir)

ubongo_analyze_dir_SOURCES = ubongo-analyze-dir.cpp
ubongo_analyze_dir_CPPFLAGS = -DUBONGO_ANALYZE_DIR \
                              -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_dir_LDADD = $(GETOPT_LDADD) \
                           $(top_builddir)/lib/ubongo/libubongo.la
ubongo_analyze_dir_LDFLAGS = -rpath $(libdir)

ubongo_analyze_3d_SOURCES = ubongo-analyze-3d.cpp
ubongo_analyze_3d_CPPFLAGS = -I$(top_srcdir)/lib -I$(top_builddir)/lib
ubongo_analyze_3d_LDADD = $(GETOPT_LDADD) \
                          $(top_builddir)/lib/ubongo3d/libubongo3d.la
ubongo_analyze_3d_LDFLAGS = -rpath $(libdir)

CLEANFILES = ubongo-solve-orig.cpp \
             ubongo-solve-duel.cpp \
             ubongo-solve-minib.cpp \
             ubongo-solve-minig.cpp \
             ubongo-solve-minir.cpp \
             ubongo-solve-miniy.cpp \
             ubongo-solve-dir.cpp \
             ubongo-solve-3d.cpp \
             ubongo-analyze-orig.cpp \
             ubongo-analyze-duel.cpp \
             ubongo-analyze-minib.cpp \
             ubongo-analyze-minig.cpp \
             ubongo-analyze-minir.cpp \
             ubongo-analyze-miniy.cpp \
             ubongo-analyze-dir.cpp \
             ubongo-analyze-3d.cpp \
             ubongo-html-orig \
             ubongo-html-duel \
             ubongo-html-minib \
             ubongo-html-minig \
             ubongo-html-minir \
             ubongo-html-miniy \
             ubongo-html-dir \
             ubongo-html-3d \
             ubongo-draw \
             ubongo-compare

EXTRA_DIST = ubongo-solve-x.cpp.in \
             ubongo-analyze-x.cpp.in \
             ubongo-html-x.in \
             ubongo-html-3d.in \
             ubongo-draw.in \
             ubongo-compare.in

ubongo-solve-orig.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|orig|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|Orig|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-solve-duel.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|duel|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|Duel|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-solve-minib.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|minib|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniB|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-solve-minig.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|minig|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniG|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-solve-minir.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|minir|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniR|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-solve-miniy.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|miniy|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniY|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-solve-dir.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|dir|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|Dir|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-solve-3d.cpp: ubongo-solve-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|3d|' \
	    -e 's|[@]lib[@]|ubongo3d|' \
	    -e 's|[@]namespace[@]|Ubongo3d|' \
	    -e 's|[@]pieceset_suffix[@]|3d|' \
	    $(srcdir)/ubongo-solve-x.cpp.in > $@

ubongo-analyze-orig.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|orig|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|Orig|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-analyze-duel.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|duel|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|Duel|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-analyze-minib.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|minib|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniB|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-analyze-minig.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|minig|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniG|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-analyze-minir.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|minir|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniR|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-analyze-miniy.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|miniy|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|MiniY|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-analyze-dir.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|dir|' \
	    -e 's|[@]lib[@]|ubongo|' \
	    -e 's|[@]namespace[@]|Ubongo|' \
	    -e 's|[@]pieceset_suffix[@]|Dir|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-analyze-3d.cpp: ubongo-analyze-x.cpp.in
	rm -f $@
	sed -e 's|[@]name[@]|3d|' \
	    -e 's|[@]lib[@]|ubongo3d|' \
	    -e 's|[@]namespace[@]|Ubongo3d|' \
	    -e 's|[@]pieceset_suffix[@]|3d|' \
	    $(srcdir)/ubongo-analyze-x.cpp.in > $@

ubongo-draw: ubongo-draw.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]CONVERT[@]|$(CONVERT)|' \
	    $(srcdir)/ubongo-draw.in > $@
	chmod 0755 $@

ubongo-html-orig: ubongo-html-x.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]name[@]|orig|' \
	    -e 's|[@]title[@]|Ubongo|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    -e 's|[@]pkgdatadir[@]|$(pkgdatadir)|' \
	    $(srcdir)/ubongo-html-x.in > $@
	chmod 0755 $@

ubongo-html-duel: ubongo-html-x.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]name[@]|duel|' \
	    -e 's|[@]title[@]|Ubongo Duel|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    -e 's|[@]pkgdatadir[@]|$(pkgdatadir)|' \
	    $(srcdir)/ubongo-html-x.in > $@
	chmod 0755 $@

ubongo-html-minib: ubongo-html-x.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]name[@]|minib|' \
	    -e 's|[@]title[@]|Ubongo Mini|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    -e 's|[@]pkgdatadir[@]|$(pkgdatadir)|' \
	    $(srcdir)/ubongo-html-x.in > $@
	chmod 0755 $@

ubongo-html-minig: ubongo-html-x.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]name[@]|minig|' \
	    -e 's|[@]title[@]|Ubongo Mini|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    -e 's|[@]pkgdatadir[@]|$(pkgdatadir)|' \
	    $(srcdir)/ubongo-html-x.in > $@
	chmod 0755 $@

ubongo-html-minir: ubongo-html-x.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]name[@]|minir|' \
	    -e 's|[@]title[@]|Ubongo Mini|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    -e 's|[@]pkgdatadir[@]|$(pkgdatadir)|' \
	    $(srcdir)/ubongo-html-x.in > $@
	chmod 0755 $@

ubongo-html-miniy: ubongo-html-x.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]name[@]|miniy|' \
	    -e 's|[@]title[@]|Ubongo Mini|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    -e 's|[@]pkgdatadir[@]|$(pkgdatadir)|' \
	    $(srcdir)/ubongo-html-x.in > $@
	chmod 0755 $@

ubongo-html-3d: ubongo-html-3d.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]name[@]|3d|' \
	    -e 's|[@]title[@]|Ubongo 3-D|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    -e 's|[@]pkgdatadir[@]|$(pkgdatadir)|' \
	    $(srcdir)/ubongo-html-3d.in > $@
	chmod 0755 $@

ubongo-compare: ubongo-compare.in Makefile
	rm -f $@
	sed -e 's|[@]RUBY[@]|$(RUBY)|' \
	    -e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|' \
	    -e 's|[@]bindir[@]|$(bindir)|' \
	    $(srcdir)/ubongo-compare.in > $@
	chmod 0755 $@
