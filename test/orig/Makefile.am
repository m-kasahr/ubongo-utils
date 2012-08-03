noinst_SCRIPTS = do-test.sh

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) $(srcdir)/../tap-driver.sh

TESTS = board01-analyze-01.sh \
        board01-analyze-02.sh \
        board01-solve-01.sh \
        board01-solve-02.sh \
        board02-analyze-01.sh \
        board02-analyze-02.sh \
        board02-solve-01.sh \
        board02-solve-02.sh \
        board03-analyze-01.sh \
        board03-analyze-02.sh \
        board03-solve-01.sh \
        board03-solve-02.sh \
        board04-analyze-01.sh \
        board04-analyze-02.sh \
        board04-solve-01.sh \
        board04-solve-02.sh \
        board05-analyze-01.sh \
        board05-analyze-02.sh \
        board05-analyze-03.sh \
        board05-analyze-04.sh \
        board05-analyze-05.sh \
        board05-analyze-06.sh \
        board05-analyze-07.sh \
        board05-analyze-08.sh \
        board05-solve-01.sh \
        board05-solve-02.sh \
        board05-solve-03.sh

EXTRA_DIST = board01 \
             board01-analyze-01.exp \
             board01-analyze-01.sh \
             board01-analyze-02.exp \
             board01-analyze-02.sh \
             board01-solve-01.exp \
             board01-solve-01.sh \
             board01-solve-02.exp \
             board01-solve-02.sh \
             board02 \
             board02-analyze-01.exp \
             board02-analyze-01.sh \
             board02-analyze-02.exp \
             board02-analyze-02.sh \
             board02-solve-01.exp \
             board02-solve-01.sh \
             board02-solve-02.exp \
             board02-solve-02.sh \
             board03 \
             board03-analyze-01.exp \
             board03-analyze-01.sh \
             board03-analyze-02.exp \
             board03-analyze-02.sh \
             board03-solve-01.exp \
             board03-solve-01.sh \
             board03-solve-02.exp \
             board03-solve-02.sh \
             board04 \
             board04-analyze-01.exp \
             board04-analyze-01.sh \
             board04-analyze-02.exp \
             board04-analyze-02.sh \
             board04-solve-01.exp \
             board04-solve-01.sh \
             board04-solve-02.exp \
             board04-solve-02.sh \
             board05 \
             board05-analyze-01.exp \
             board05-analyze-01.sh \
             board05-analyze-02.exp \
             board05-analyze-02.sh \
             board05-analyze-03.exp \
             board05-analyze-03.sh \
             board05-analyze-04.exp \
             board05-analyze-04.sh \
             board05-analyze-05.exp \
             board05-analyze-05.sh \
             board05-analyze-06.exp \
             board05-analyze-06.sh \
             board05-analyze-07.exp \
             board05-analyze-07.sh \
             board05-analyze-08.exp \
             board05-analyze-08.sh \
             board05-solve-01.exp \
             board05-solve-01.sh \
             board05-solve-02.exp \
             board05-solve-02.sh \
             board05-solve-03.exp \
             board05-solve-03.sh

clean-local:
	rm -f do-test.sh
	rm -f *.out

do-test.sh: $(srcdir)/../do-test.sh.in
	rm -f $@
	sed -e 's|[@]top_builddir[@]|$(top_builddir)|' \
	    -e 's|[@]srcdir[@]|$(srcdir)|' \
	    $(srcdir)/../do-test.sh.in > $@
	chmod 0755 $@
