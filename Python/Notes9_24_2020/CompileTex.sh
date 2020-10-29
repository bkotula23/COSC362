#!/bin/bash
for file in $(ls *.tex)
do
    pdflatex $file
done
