#!/bin/bash

# Build with dynamic linking
gcc -Wall -shared -rdynamic fact.c -o libfact.so 
gcc -Wall -g main2.c -ldl -o benchmark

# Build with static linking
gcc -Wall -c factr.c -o libfactr.so
gcc -Wall -c facti.c -o libfacti.so
gcc -Wall main.c -L . -lfactr -lfacti -o staticlink

