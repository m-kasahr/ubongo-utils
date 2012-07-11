#! /bin/sh

PROBLEM_FILE=problems.tmp

trap "rm -f $PROBLEM_FILE; exit 1" 1 2 3 15
cat > $PROBLEM_FILE <<__END__
* A B C D E
* A B C E F
* A B C E G
* B C D E G
* B C E F G
__END__

ubongo-solve-miniy -f $PROBLEM_FILE board01
EXITCODE=$?

rm -f $PROBLEM_FILE
exit $EXITCODE
