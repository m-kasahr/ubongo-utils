#! /bin/sh

do_setup() {
    true
}

do_test() {
    ubongo-analyze-orig --max-solutions 1 board05 5
}

do_teardown() {
    true
}

. ./do-test.sh
