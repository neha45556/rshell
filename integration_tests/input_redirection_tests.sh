#!/bin/sh

cd ..

./rshell << EOF
cat < integration_tests/inputfile.txt
echo hello; cat < integration_tests/inputfile.txt
exit 
EOF

