#!/bin/bash
lines=0
for name in *; do
    lines=$(($lines+$(wc -l $name | grep -oP '^[0-9]+' )))
done
echo $lines

