#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-3d --max-solutions 1 --show-solution board03 4
}

do_teardown() {
    true
}

. ./do-test.sh
