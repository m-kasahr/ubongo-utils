#! /bin/sh

PROBLEM_FILE=problems.tmp

trap "rm -f $PROBLEM_FILE; exit 1" 1 2 3 15
cat > $PROBLEM_FILE <<__END__
* A B C I J
* A B C I K
* A B C I L
* A B C J K
* A B C J L
* A B C K L
* A B D E I
* A B D E J
* A B D E K
* A B D E L
* A B D F I
* A B D F J
* A B D F K
* A B D F L
* A B D G I
* A B D G J
* A B D G K
* A B D G L
* A B D H I
* A B D H J
* A B D H K
* A B D H L
* A B E F I
* A B E F J
* A B E F K
* A B E F L
* A B E G I
* A B E G J
* A B E G K
* A B E G L
* A B E H I
* A B E H J
* A B E H K
* A B E H L
* A B F G I
* A B F G J
* A B F G K
* A B F G L
* A B F H I
* A B F H J
* A B F H K
* A B F H L
* A B G H I
* A B G H J
* A B G H K
* A B G H L
* A C D E I
* A C D E J
* A C D E K
* A C D E L
* A C D F I
* A C D F J
* A C D F K
* A C D F L
* A C D G I
* A C D G J
* A C D G K
* A C D G L
* A C D H I
* A C D H J
* A C D H K
* A C D H L
* A C E F I
* A C E F J
* A C E F K
* A C E F L
* A C E G I
* A C E G J
* A C E G K
* A C E G L
* A C E H I
* A C E H J
* A C E H K
* A C E H L
* A C F G I
* A C F G J
* A C F G K
* A C F G L
* A C F H I
* A C F H J
* A C F H K
* A C G H I
* A C G H J
* A C G H K
* A D E F G
* A D E F H
* A D E G H
* B C D E F
* B C D E G
* B C D E H
* B C D F G
* B C D F H
* B C D G H
* B C E F G
* B C E F H
* B C E G H
__END__

ubongo-solve-orig -f $PROBLEM_FILE board05
EXITCODE=$?

rm -f $PROBLEM_FILE
exit $EXITCODE
