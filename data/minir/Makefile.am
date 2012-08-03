pkgdataminirdir = $(pkgdatadir)/minir

pkgdataminir_DATA = A.piece \
                    B.piece \
                    C.piece \
                    D.piece \
                    E.piece \
                    F.piece \
                    G.piece \
                    colors \
                    piece-flip-flag \
                    piece-order

EXTRA_DIST = $(pkgdataminir_DATA)

uninstall-hook:
	-rmdir $(pkgdataminirdir)
	-rmdir $(pkgdatadir)
