#!/bin/bash

dir=$1
files="${dir}/*.txt"
echo $files

for file in $files; do
    echo "Processing file: ${file}"
    echo "set term png
          set output \"${file}.png\"
          plot \"${file}\" using 1:2 w l title \"\" " | gnuplot
done
