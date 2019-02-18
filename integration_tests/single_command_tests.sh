#!/bin/sh

cd ..

./rshell << EOF
echo Bash scripts are pretty cool
dog
ls
mkdir newDir
ls
rm -rf newDir
ls
echo "hello && goodbye"
echo "hello ; goodbye"
echo "hello || goodbye"
echo exiting
exit
EOF
