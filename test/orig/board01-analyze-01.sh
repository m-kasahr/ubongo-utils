#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-orig board01 1
}

do_teardown() {
    true
}

. ./do-test.sh
