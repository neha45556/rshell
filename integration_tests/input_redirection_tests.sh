#!/bin/sh

cd ..

./rshell << EOF
cat < integration_tests/inputfile.txt
echo hello; cat < integration_tests/inputfile.txt
cat < intergration_tests/inputfile.txt; echo bye
cat < intergration_tests/inputfile.txt && echo hi
echo hi && cat < intergration_tests/outputfile.txt
cat < intergration_tests/inputfile.txt > intergration_tests/outputfile.txt
cat < intergration_tests/inputfile.txt || echo hi
exit 
EOF

