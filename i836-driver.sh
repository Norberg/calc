#!/bin/sh
#	Authors: Simon Norberg & Filip Andersson

# Print error-message
if [ $# -le 0 ]; then
	echo ".calc-file input needed."
fi

fileName=`echo $1 |cut -d'.' -f1`

assemblyFile=$fileName.s

cat prologue.s > $assemblyFile
./calc3i < $1 >> $assemblyFile
cat epilogue.s >> $assemblyFile

gcc $assemblyFile -o$fileName

