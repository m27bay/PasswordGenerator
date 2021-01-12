#!/bin/bash

if [ ! -d "bin" ]; then
mkdir bin;
fi

if [ ! -d "out" ]; then
mkdir out;
touch out/save.txt
fi

if [ ! -d "target" ];then
mkdir target;
fi