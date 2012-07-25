#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-3d --show-solution board03 4
}

do_teardown() {
    true
}

. ./do-test.sh
