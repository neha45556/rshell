#!/bin/sh

cd ..

./rshell << EOF
cat < intergration_tests/inputfile.txt
echo hello; cat < integration_tests/inputfile.txt
exit 
EOF

