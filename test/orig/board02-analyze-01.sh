#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-orig board02 1
}

do_teardown() {
    true
}

. ./do-test.sh
