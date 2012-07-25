#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-3d --all board02 I D
}

do_teardown() {
    true
}

. ./do-test.sh
