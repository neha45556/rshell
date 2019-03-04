
#!/bin/sh
cd ..

./rshell << EOF
test -e src/test.cpp 
test -f src/input.cpp
test -d ../src && echo “exists”
test -e src/stuff.cpp || echo “failed”
test -d direc 
test -e src/connector.h && test -e src/command.cpp && test -d ../src && echo "files"
echo testing && echo "files" && test -e src/MultCmd.cpp && echo working
test -d ../integration_test && echo hi || echo bye
test unit_tests/unit_tests.cpp && (echo hi && echo hello) || echo "world"
test src/command.h
(test test.cpp)
exit
EOF

