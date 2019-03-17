#!/bin/sh

cd ..

./rshell << EOF
cat < intergration_tests/inputfile.txt
echo hello; cat < integration_tests/inputfile.txt
cat < intergration_tests/inputfile.txt | tr a-z A-Z
cat < intergration_tests/inputfile.txt | tee intergration_tests/outputfile.txt | tr a-z A-Z
echo hi && cat < intergration_tests/outputfile.txt
cat < intergration_tests/inputfile.txt > intergration_tests/outputfile.txt
cat < intergration_tests/inputfile.txt || echo hi
exit 
EOF

