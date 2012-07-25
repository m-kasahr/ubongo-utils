#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-solve-orig --all board04 K L
}

do_teardown() {
    true
}

. ./do-test.sh
