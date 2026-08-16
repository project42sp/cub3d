cd cmocka-2.0.2/
cmake -S . -B build
cmake --build build
cmake --build build --target test
cmake --install build
