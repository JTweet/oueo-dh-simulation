#!/usr/bin/env sh

for i in {0..9999}; do
    src/dh-test >> dh-timing.csv
done
