#! /bin/sh

PROBLEM_FILE=problems.$$

do_setup() {
    trap "rm -f $PROBLEM_FILE; exit 1" 1 2 3 15
    cat > $PROBLEM_FILE <<__END__
* A C D F
* B D E G
__END__
}

do_test() {
    ubongo-solve-minig -f $PROBLEM_FILE board01
}

do_teardown() {
    rm -f $PROBLEM_FILE
}

. ./do-test.sh
