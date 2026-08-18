#!/bin/sh
wget https://cmocka.org/files/2.0/cmocka-2.0.2.tar.xz
tar -xvf cmocka-2.0.2.tar.xz
rm cmocka-2.0.2.tar.xz

cd cmocka-2.0.2/
cmake -S . -B build
cmake --build build
cmake --build build --target test
sleep 3
cmake --install build
cd ../ && rm -rf cmocka-2.0.2/ && cd ../
