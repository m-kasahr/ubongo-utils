#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-orig --show-solution board05 5
}

do_teardown() {
    true
}

. ./do-test.sh
