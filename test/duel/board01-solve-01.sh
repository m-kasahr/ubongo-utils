#! /bin/sh

PROBLEM_FILE=problems.tmp

trap "rm -f $PROBLEM_FILE; exit 1" 1 2 3 15
cat > $PROBLEM_FILE <<__END__
* A C E O
* A D H O
* A D O P
* A H L U
* B C D Q
* B C G Q
* B D E O
* B D F L
* B D G H
* B D G M
* B D H O
* B D L M
* B D L Q
* B D M O
* B D N O
* B D O P
* B D O R
* B D Q U
* B E J O
* B G I L
* B J O P
* C D M O
* C D M T
* C D O R
* C E G L
* C G N T
* C G O S
* C H L O
* C J M O
* C J O P
* C J O R
* C L M U
* C L N O
* C L Q U
* C L R U
* C P T U
* D E L O
* D G I O
* D G O R
* D H L U
* D I O T
* D L N O
* D L O P
* D L O R
* D M T U
* D N O U
* D O Q T
* D O R T
* D O R U
* E J L O
* G L O Q
* J O S U
__END__

ubongo-solve-duel -f $PROBLEM_FILE board01
EXITCODE=$?

rm -f $PROBLEM_FILE
exit $EXITCODE
