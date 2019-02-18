#!/bin/sh

cd ..

./rshell << EOF
echo hello # world
echo "hello # world"
echo hello # world; ls #-a
echo "hello # world"; echo hellO #&&; echo end
echo goodbye
exit
EOF
