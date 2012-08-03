pkgdatapentominodir = $(pkgdatadir)/pentomino

pkgdatapentomino_DATA = F.piece \
                        I.piece \
                        L.piece \
                        N.piece \
                        P.piece \
                        T.piece \
                        U.piece \
                        V.piece \
                        W.piece \
                        X.piece \
                        Y.piece \
                        Z.piece \
                        colors \
                        piece-flip-flag \
                        piece-order

EXTRA_DIST = $(pkgdatapentomino_DATA)

uninstall-hook:
	-rmdir $(pkgdatapentominodir)
	-rmdir $(pkgdatadir)
