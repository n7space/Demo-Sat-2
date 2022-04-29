#!/bin/bash

cd ..
rm -rf build
mkdir build
cd build
cmake ..
make
cp bin/LinuxPartition ../samv71Partition/work/binaries
cd ../samv71Partition
