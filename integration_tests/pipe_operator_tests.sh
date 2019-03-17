#!/bin/sh

cd ..

./rshell << EOF
cat < intergration_tests/inputfile.txt | tr a-z A-Z
echo HER | tr A-Z a-z | tr a-z A-Z
cat < intergration_tests/inputfile.txt | tee intergration_tests/outputfile.txt | tr a-z A-Z
echo ABC | tr A-Z a-z 
cat < intergration_tests/inputfile.txt | tr A-Z a-z | tr a-z A-Z
cat < intergration_tests/inputfile.txt | sort
cat intergration_tests/inputfile.txt | tr a-z A-Z | sort > intergration_tests/outputfile.txt
cat intergration_tests/inputfile.txt | tr a-z A-Z | tee intergration_tests/inputfile.txt | tr a-z A-Z >> intergration_tests/inputfile.txt
exit 
EOF

