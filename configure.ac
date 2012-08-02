dnl *
dnl * Basic definitions.
dnl *
AC_INIT([ubongo-utils], [1.1])
AM_INIT_AUTOMAKE([foreign dist-bzip2 parallel-tests -Wall])
CXXFLAGS=${CXXFLAGS-"-g -O3"}
LIBUBONGO_VERSION_INFO=2:0:0
LIBUBONGO3D_VERSION_INFO=2:0:0
AC_SUBST([LIBUBONGO_VERSION_INFO])
AC_SUBST([LIBUBONGO3D_VERSION_INFO])
AC_CONFIG_MACRO_DIR([m4])

dnl *
dnl * Programs.
dnl *
AC_LANG([C++])
AC_PROG_CXX
AC_PROG_MKDIR_P
AC_PROG_INSTALL
AM_PROG_AR
AC_PROG_LIBTOOL
AC_PATH_PROG([RUBY], [ruby], [/usr/bin/ruby])
AC_PATH_PROG([CONVERT], [convert], [/usr/bin/convert])
AC_PATH_PROGS([MARKDOWN], [Markdown.pl], [/usr/bin/Markdown.pl])

dnl *
dnl * --with-pkgdocdir option.
dnl *
AC_ARG_WITH(pkgdocdir,
AC_HELP_STRING([--with-pkgdocdir=DIR],
    [HTML documents in DIR (default=DATADIR/ubongo-utils/doc)]),
[pkgdocdir="${withval}"],[pkgdocdir='${datadir}/ubongo-utils/doc'])
AC_SUBST(pkgdocdir)

dnl *
dnl * Check functions.
dnl *
AC_MSG_CHECKING(for getopt_long)
AC_LINK_IFELSE([AC_LANG_PROGRAM(
[[extern "C" {
#include <getopt.h>
}]], [[::getopt_long(0, 0, 0, 0, 0);]])],
    [ac_cv_func_getopt_long=yes], [ac_cv_func_getopt_long=no])
AC_MSG_RESULT($ac_cv_func_getopt_long)
AM_CONDITIONAL([COND_GETOPT], [test "$ac_cv_func_getopt_long" = yes])

dnl *
dnl * Output files.
dnl *
AC_CONFIG_FILES([Makefile
                 lib/ubongo/Makefile
                 lib/ubongo3d/Makefile
                 utils/Makefile
                 data/3d/Makefile
                 data/duel/Makefile
                 data/minib/Makefile
                 data/minig/Makefile
                 data/minir/Makefile
                 data/miniy/Makefile
                 data/orig/Makefile
                 data/pentomino/Makefile
                 doc/Makefile
                 test/Makefile
                 test/orig/Makefile
                 test/duel/Makefile
                 test/minib/Makefile
                 test/minig/Makefile
                 test/minir/Makefile
                 test/miniy/Makefile
                 test/3d/Makefile])
AC_OUTPUT
