#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-minib board01 4
}

do_teardown() {
    true
}

. ./do-test.sh
