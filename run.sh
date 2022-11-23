mkdir build
cd build
cmake ..
make

cd ..
cd test
cd build
make seq_scan_test
./seq_scan_test
