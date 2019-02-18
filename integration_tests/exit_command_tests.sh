#!/bin/sh

cd ..

./rshell << EOF
echo exit
exit
EOF

./rshell << EOF
echo exit; echo hello
echo hello; exit
EOF

./rshell << EOF
echo "hello && exit" && exit
EOF

./rshell << EOF
echo hello || exit
exit
EOF

./rshell << EOF
#exit
exit
EOF


