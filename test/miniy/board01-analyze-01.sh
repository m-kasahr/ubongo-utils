#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-miniy board01 5
}

do_teardown() {
    true
}

. ./do-test.sh
