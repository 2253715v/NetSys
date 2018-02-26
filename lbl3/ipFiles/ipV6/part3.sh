#!/bin/bash
for i in $( ls *.txt); do
    java MyClass $i
done