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

# Create a .c filename for the file containing the C code
cFile=$fileName.c

# Pipe the contents of prologue.c, the file compiled with calc3i and epilogue.c to the C file
cat prologue.c > $cFile
./calc3c < $1 >> $cFile
cat epilogue.c >> $cFile

# Compile the C file with gcc
gcc $cFile -o$fileName

