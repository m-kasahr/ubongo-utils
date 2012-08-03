pkgdataminiydir = $(pkgdatadir)/miniy

pkgdataminiy_DATA = A.piece \
                    B.piece \
                    C.piece \
                    D.piece \
                    E.piece \
                    F.piece \
                    G.piece \
                    colors \
                    piece-flip-flag \
                    piece-order

EXTRA_DIST = $(pkgdataminiy_DATA)

uninstall-hook:
	-rmdir $(pkgdataminiydir)
	-rmdir $(pkgdatadir)
