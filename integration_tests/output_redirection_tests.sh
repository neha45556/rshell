#!/bin/sh

cd ..

./rshell << EOF
echo abc > integration_tests/outputfile.txt
echo "output" && cat < integration_tests/outputfile.txt
echo b >> integration_tests/outputfile.txt
echo "in" && cat < integration_tests/outputfile.txt
echo abcde >> integration_tests/outputfile.txt && echo efgh >> integration_tests/outputfile.txt
echo "hello" < integration_tests/outputfile.txt && echo bye
echo xyz < integration_tests/outputfile.txt || echo werq < integration_tests/outputfile.txt
echo qwer > integration_tests/outputfile.txt; echo isd > integration_tests/outputfile.txt
exit
EOF
