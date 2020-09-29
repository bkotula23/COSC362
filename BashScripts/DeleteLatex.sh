#!/bin/bash
echo "What is the file name that you would like to clean up?"

read filename

echo please confirm that this is the correct file name - $filename [Yes/No]

read ans

if [ "$ans" == Yes ]
then
    rm $filename.log || echo "a .log file was not found"
    rm $filename.aux || echo "a .aux file was not found"
    echo "The file name $filename is now m cleaned up."
fi
