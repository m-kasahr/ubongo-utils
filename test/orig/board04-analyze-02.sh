#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-orig --show-solution board04 2
}

do_teardown() {
    true
}

. ./do-test.sh
