noinst_SCRIPTS = do-test.sh

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) $(srcdir)/../tap-driver.sh

TESTS = do-test.sh

EXTRA_DIST = board01 \
             board01-solve-01.exp \
             board01-solve-01.sh \
             board02 \
             board02-solve-01.exp \
             board02-solve-01.sh

clean-local:
	rm -f do-test.sh
	rm -f *.out

do-test.sh: $(srcdir)/../do-test.sh.in
	rm -f $@
	sed -e 's|[@]top_builddir[@]|$(top_builddir)|' \
	    -e 's|[@]srcdir[@]|$(srcdir)|' \
	    $(srcdir)/../do-test.sh.in > $@
	chmod 0755 $@
