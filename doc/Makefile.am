pkgdocdir = @pkgdocdir@

pkgdoc_DATA = ubongo-utils.md \
              ubongo-utils.html \
              orig-piece-A.png \
              orig-piece-B.png \
              orig-piece-C.png \
              orig-piece-D.png \
              orig-piece-E.png \
              orig-piece-F.png \
              orig-piece-G.png \
              orig-piece-H.png \
              orig-piece-I.png \
              orig-piece-J.png \
              orig-piece-K.png \
              orig-piece-L.png \
              duel-piece-A.png \
              duel-piece-B.png \
              duel-piece-C.png \
              duel-piece-D.png \
              duel-piece-E.png \
              duel-piece-F.png \
              duel-piece-G.png \
              duel-piece-H.png \
              duel-piece-I.png \
              duel-piece-J.png \
              duel-piece-K.png \
              duel-piece-L.png \
              duel-piece-M.png \
              duel-piece-N.png \
              duel-piece-O.png \
              duel-piece-P.png \
              duel-piece-Q.png \
              duel-piece-R.png \
              duel-piece-S.png \
              duel-piece-T.png \
              duel-piece-U.png \
              minib-piece-A.png \
              minib-piece-B.png \
              minib-piece-C.png \
              minib-piece-D.png \
              minib-piece-E.png \
              minib-piece-F.png \
              minib-piece-G.png \
              minig-piece-A.png \
              minig-piece-B.png \
              minig-piece-C.png \
              minig-piece-D.png \
              minig-piece-E.png \
              minig-piece-F.png \
              minig-piece-G.png \
              minir-piece-A.png \
              minir-piece-B.png \
              minir-piece-C.png \
              minir-piece-D.png \
              minir-piece-E.png \
              minir-piece-F.png \
              minir-piece-G.png \
              miniy-piece-A.png \
              miniy-piece-B.png \
              miniy-piece-C.png \
              miniy-piece-D.png \
              miniy-piece-E.png \
              miniy-piece-F.png \
              miniy-piece-G.png \
              3d-piece-A.png \
              3d-piece-B.png \
              3d-piece-C.png \
              3d-piece-D.png \
              3d-piece-E.png \
              3d-piece-F.png \
              3d-piece-G.png \
              3d-piece-H.png \
              3d-piece-I.png \
              3d-piece-J.png \
              3d-piece-K.png \
              3d-piece-L.png \
              3d-piece-M.png \
              3d-piece-N.png \
              3d-piece-O.png \
              3d-piece-P.png \
              board1.png \
              solution1.png \
              solution2.png \
              solution3.png \
              screenshot1.png \
              screenshot2.png \
              screenshot3.png \
              screenshot4.png \
              board1.txt \
              combinations1.txt \
              problem1.txt \
              solution1.txt

EXTRA_DIST = ubongo-utils.html.header \
             ubongo-utils.html.footer \
             $(pkgdoc_DATA)

ubongo-utils.html: ubongo-utils.html.header \
                   ubongo-utils.html.footer ubongo-utils.md
	rm -f $@
	cat $(srcdir)/ubongo-utils.html.header >> $@
	$(MARKDOWN) $(srcdir)/ubongo-utils.md >> $@
	cat $(srcdir)/ubongo-utils.html.footer >> $@
