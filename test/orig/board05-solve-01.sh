#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-orig board05 A B C J K
}

do_teardown() {
    true
}

. ./do-test.sh
