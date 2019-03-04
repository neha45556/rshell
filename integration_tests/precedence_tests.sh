
#!/bin/sh

cd ..

./rshell << EOF
(echo hello || (echo five))
(echo hi; (echo four))
(echo 1; (echo 2; echo 3); (echo 4; echo 5))
((echo 4 && echo 2)
(exit && echo 3) && echo 3
(dog && (echo 4 && echo 3)
(echo 2 || (echo 1 && echo 2) && echo 9)
EOF
