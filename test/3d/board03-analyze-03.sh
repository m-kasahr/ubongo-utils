#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-3d --max-solutions 2 board03 4
}

do_teardown() {
    true
}

. ./do-test.sh
