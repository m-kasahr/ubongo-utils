#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-3d --all board01 I B
}

do_teardown() {
    true
}

. ./do-test.sh
