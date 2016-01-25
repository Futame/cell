#!/bin/bash

dir=$1
outputdir=$2
mkdir $outputdir
files="${dir}/*"
echo $files

for file in $files; do
	if [ -d "$file" ]
	then
	continue
	fi
    echo "Processing file: ${file}"
	bn=${file##*/}
    echo $bn
	b=${bn%.*}
    echo $b
	outputfile="${outputdir}/${b}.png"
    echo "output file: ${outputfile}"
    echo "set term png
          set output \"${outputfile}\"
          plot \"${file}\" using 1:2 w l title \"\" " | gnuplot
done	
