#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-orig --all board01 A
}

do_teardown() {
    true
}

. ./do-test.sh
