
#!/bin/sh

cd ..

./rshell  << EOF
[ -f light.cpp ] 
[ -d integration_test ]
[ -e src/FullCommand.cpp ]
[ src/Paren.h ]
[ -d nothin.cpp ] && echo fail
echo 1 || [ -e dubs.h ]
([ -e ../unit_tests ]) && echo passes
[ -e nms.cpp ] && [ -f jsc.h ] || ([ -e src/and.cpp ] && [ -d input.cpp ])
[ ../images ] || [ -e Base.hpp ] && ([ -d input.cpp]) || echo filesworks
echo "yahoooooo" && [ -e googogogle.cpp ] && [ -f FullCommand.cpp ] 
exit
EOF

