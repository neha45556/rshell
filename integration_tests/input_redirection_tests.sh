#!/bin/sh

cd ..

./rshell << EOF
cat < integration_tests/inputfile.txt
echo hello; cat < integration_tests/inputfile.txt
cat < integration_tests/inputfile.txt; echo bye
cat < integration_tests/inputfile.txt && echo hi
echo hi && cat < integration_tests/outputfile.txt
cat < integration_tests/inputfile.txt > integration_tests/outputfile.txt
cat < integration_tests/inputfile.txt || echo hi
exit 
EOF

