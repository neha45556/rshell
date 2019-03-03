#!/bin/sh

cd ..

./rshell << EOF
echo hello # world
echo "hello # world"
echo hello # world; ls # -a
ls # -a
echo goodbye
#echo hello
#exit
exit
EOF
