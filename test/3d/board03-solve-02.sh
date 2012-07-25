#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-3d --all board03 A G I M
}

do_teardown() {
    true
}

. ./do-test.sh
