#!/bin/bash

gcc -shared -rdynamic fact.c -o libfact.so 
gcc -g main2.c -ldl -o benchmark
