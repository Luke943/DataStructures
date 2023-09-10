#!usr/bin/bash

if [ $# -eq 0 ]
  then
    echo "Provide name of new data structure"
    exit 1
fi

echo "#include <stdio.h>" > "src/$1.c"
echo "#include <stdlib.h>" >> "src/$1.c"
echo "#include \"$1.h\"" >> "src/$1.c"
echo "#pragma once" > "include/$1.h"
echo "#include <stdio.h>" > "tests/test_$1.c"
echo "#include \"$1.h\"" >> "tests/test_$1.c"