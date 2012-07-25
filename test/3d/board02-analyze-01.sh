#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-3d board02 2
}

do_teardown() {
    true
}

. ./do-test.sh
