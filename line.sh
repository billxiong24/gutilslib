#!/bin/bash
lines=0
files=$(find -name *.c -print)
for name in $files; do
    if [[ ! "$name" =~ test ]]; then
        num=$(wc -l $name)
        echo $num
        lines=$(($lines+$(echo $num | grep -oP '^[0-9]+' )))
    fi
done
echo $lines

