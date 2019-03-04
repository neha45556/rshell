#test_command_tests.sh

#!/bin/s
cd ..

./rshell << EOF
test -e src/test.cpp 
test -f src/input.cpp
test -d ../src && echo “exists”
test -e src/stuff.cpp || echo “failed”
test -d direc 
test src/command.h
(test test.cpp)
EOF
