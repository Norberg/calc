#!/bin/sh
#	Authors: Simon Norberg & Filip Andersson

# Print error-message
if [ $# -le 0 ]; then
	echo "ERROR: .calc-file input needed."
	exit
fi
if [ "`echo "$1" | cut -d"." -f2`" != "calc" ]; then
	echo "ERROR: .calc-file input needed."
	exit
fi

# Create a proper filename for the compiled file
fileName=`echo $1 |cut -d'.' -f1`

# Create a .s filename for the file containing the assembly code
assemblyFile=$fileName.s

# Pipe the contents of prologue.s, the file compiled with calc3i and epilogue.s to the assembly file
cat prologue.s > $assemblyFile
./calc3i < $1 >> $assemblyFile
cat epilogue.s >> $assemblyFile

# Compile the assembly file with gcc
gcc $assemblyFile -o$fileName

