#!/bin/bash
read -p "filename:" filename 
g++ -std=c++11 -O2 "$filename".cpp lib.a -Wall -o "$filename".out

