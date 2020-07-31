#!/bin/bash
for file in $(ls *.c)
do
norminette $file > ${file%.c}.txt
done