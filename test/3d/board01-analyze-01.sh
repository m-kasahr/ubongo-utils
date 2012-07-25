#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-3d board01 2
}

do_teardown() {
    true
}

. ./do-test.sh
