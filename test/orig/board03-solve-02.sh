#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-orig --all board03 A B
}

do_teardown() {
    true
}

. ./do-test.sh
