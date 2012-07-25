#! /bin/sh

PROBLEM_FILE=problems.$$

do_setup() {
    trap "rm -f $PROBLEM_FILE; exit 1" 1 2 3 15
    cat > $PROBLEM_FILE <<__END__
* A B I M
* A D I M
* A F I M
* A G I M
* A I K M
* E F G I
* E G I M
* F G I N
* G I M N
__END__
}

do_test() {
    ubongo-solve-3d -f $PROBLEM_FILE board03
}

do_teardown() {
    rm -f $PROBLEM_FILE
}

. ./do-test.sh
