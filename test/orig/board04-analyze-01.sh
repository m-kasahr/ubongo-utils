#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-orig board04 2
}

do_teardown() {
    true
}

. ./do-test.sh
