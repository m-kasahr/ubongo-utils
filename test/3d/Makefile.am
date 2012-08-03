noinst_SCRIPTS = do-test.sh

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) $(srcdir)/../tap-driver.sh

TESTS = board01-analyze-01.sh \
        board01-solve-01.sh \
        board02-analyze-01.sh \
        board02-solve-01.sh \
        board03-analyze-01.sh \
        board03-analyze-02.sh \
        board03-analyze-03.sh \
        board03-analyze-04.sh \
        board03-analyze-05.sh \
        board03-analyze-06.sh \
        board03-analyze-07.sh \
        board03-analyze-08.sh \
        board03-solve-01.sh \
        board03-solve-02.sh \
        board03-solve-03.sh

EXTRA_DIST = board01 \
             board01-analyze-01.exp \
             board01-analyze-01.sh \
             board01-solve-01.exp \
             board01-solve-01.sh \
             board02 \
             board02-analyze-01.exp \
             board02-analyze-01.sh \
             board02-solve-01.exp \
             board02-solve-01.sh \
             board03 \
             board03-analyze-01.exp \
             board03-analyze-01.sh \
             board03-analyze-02.exp \
             board03-analyze-02.sh \
             board03-analyze-03.exp \
             board03-analyze-03.sh \
             board03-analyze-04.exp \
             board03-analyze-04.sh \
             board03-analyze-05.exp \
             board03-analyze-05.sh \
             board03-analyze-06.exp \
             board03-analyze-06.sh \
             board03-analyze-07.exp \
             board03-analyze-07.sh \
             board03-analyze-08.exp \
             board03-analyze-08.sh \
             board03-solve-01.exp \
             board03-solve-01.sh \
             board03-solve-02.exp \
             board03-solve-02.sh \
             board03-solve-03.exp \
             board03-solve-03.sh

clean-hook:
	rm -f do-test.sh
	rm -f *.out

do-test.sh: $(srcdir)/../do-test.sh.in
	rm -f $@
	sed -e 's|[@]top_builddir[@]|$(top_builddir)|' \
	    -e 's|[@]srcdir[@]|$(srcdir)|' \
	    $(srcdir)/../do-test.sh.in > $@
	chmod 0755 $@
