#!/bin/sh

cd ..

./rshell << EOF
cat < integration_tests/inputfile.txt | tr a-z A-Z
echo HER | tr A-Z a-z | tr a-z A-Z
cat < integration_tests/inputfile.txt | tee integration_tests/outputfile.txt | tr a-z A-Z
echo ABC | tr A-Z a-z 
cat < integration_tests/inputfile.txt | tr A-Z a-z | tr a-z A-Z
cat < integration_tests/inputfile.txt | sort
cat < integration_tests/inputfile.txt | tr a-z A-Z | sort > integration_tests/outputfile.txt
cat < integration_tests/inputfile2.txt | tr A-Z a-z | tee integration_tests/outputfile.txt | tr a-z A-Z >> integration_tests/outputfile.txt
exit 
EOF

