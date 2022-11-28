cd build
echo -e "\nseq-scan-test:"
./seq-scan-test
echo -e "\nfilter-seq-scan-test:"
./filter-seq-scan-test
echo -e "\nhash-join-test:"
./hash-join-test
echo -e "\nnested-loop-join-test:"
./nested-loop-join-test
echo -e "\ncomplex-test:"
./complex-test