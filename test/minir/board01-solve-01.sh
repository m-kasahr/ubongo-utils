#! /bin/sh

PROBLEM_FILE=problems.tmp

trap "rm -f $PROBLEM_FILE; exit 1" 1 2 3 15
cat > $PROBLEM_FILE <<__END__
* A B D E G
* A C E F G
__END__

ubongo-solve-minir -f $PROBLEM_FILE board01
EXITCODE=$?

rm -f $PROBLEM_FILE
exit $EXITCODE
