#! /bin/sh

PROBLEM_FILE=problems.tmp

trap "rm -f $PROBLEM_FILE; exit 1" 1 2 3 15
cat > $PROBLEM_FILE <<__END__
* A B C D
* A B C F
* A C D G
* A C F G
* A D E G
* A E F G
* C D E F
__END__

ubongo-solve-minib -f $PROBLEM_FILE board01
EXITCODE=$?

rm -f $PROBLEM_FILE
exit $EXITCODE
