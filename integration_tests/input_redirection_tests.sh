#!/bin/sh

cd ..

./rshell << EOF
cat < intergration_tests/inputfile
echo hello; cat < integration_tests/inputfile
cat < inputfile | tr a-z A-Z
cat < inputfile | tee outputfile | tr a-z A-Z
echo hi && cat < outputfile

exit 
EOF

