pkgdataminigdir = $(pkgdatadir)/minig

pkgdataminig_DATA = A.piece \
                    B.piece \
                    C.piece \
                    D.piece \
                    E.piece \
                    F.piece \
                    G.piece \
                    colors \
                    piece-flip-flag \
                    piece-order

EXTRA_DIST = $(pkgdataminig_DATA)

uninstall-hook:
	-rmdir $(pkgdataminigdir)
	-rmdir $(pkgdatadir)
