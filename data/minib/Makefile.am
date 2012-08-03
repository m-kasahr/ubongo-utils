pkgdataminibdir = $(pkgdatadir)/minib

pkgdataminib_DATA = A.piece \
                    B.piece \
                    C.piece \
                    D.piece \
                    E.piece \
                    F.piece \
                    G.piece \
                    colors \
                    piece-flip-flag \
                    piece-order

EXTRA_DIST = $(pkgdataminib_DATA)

uninstall-hook:
	-rmdir $(pkgdataminibdir)
	-rmdir $(pkgdatadir)
