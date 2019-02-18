#!/bin/sh

cd ..

./rshell << EOF
echo We are going to || echo should not print; echo execute mkdir and ls
mkdir dummy; ls
echo we are going to && echo remove the dummy
rm -rf dummy; ls
dog; echo hello
dog || echo should print
dog && echo should not print; echo hello
echo "hello && goodbye" && echo "goodbye && hello"
echo "Basket || Ball" || echo "Shouldn't print"
echo "Hey ; Look"; echo "A ; semicolon"
echo Going to go bye bye now
exit
EOF
