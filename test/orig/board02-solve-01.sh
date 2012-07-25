#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-orig board02 L
}

do_teardown() {
    true
}

. ./do-test.sh
