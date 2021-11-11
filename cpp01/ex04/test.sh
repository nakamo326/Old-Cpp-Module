#! /bin/bash

COLOR_OK="\e[32m"
COLOR_KO="\e[31m"
COLOR_RESET="\e[0m"

USAGE="USAGE: ./replace [filename] [search] [replace]"

function sedtest () {
  ./replace "$1" "$2" "$3"
  sed -e "s/$2/$3/g" "$1" > sed_res
  if diff $1.replace sed_res; then
    printf "${COLOR_OK}OK${COLOR_RESET}\n"
  else
    printf "${COLOR_KO}KO${COLOR_RESET}\n"
  fi
  rm sed_res
  rm $1.replace
}

function errortest() {
  res=`./replace "$2" "$3" "$4" 2>&1`
  if test "$res" = "$1" ; then
    printf "${COLOR_OK}OK${COLOR_RESET}\n"
  else
    printf "${COLOR_KO}KO${COLOR_RESET}\n"
  fi
}

echo "error test"
errortest "$USAGE" no_such_file "" ""
errortest "$USAGE" no_such_file " " ""
errortest "$USAGE" no_such_file "" " "
errortest "$USAGE" "" " " " "
errortest "$USAGE" no_such_file
errortest "./replace: no_such_file: No such file or directory" no_such_file test test

touch tests/permission
chmod 000 tests/permission
errortest "./replace: tests/permission: Permission denied" tests/permission test test
chmod 644 tests/permission
rm tests/permission

touch tests/test.replace
chmod 000 tests/test.replace
errortest "./replace: tests/test.replace: Permission denied" tests/test test test
chmod 644 tests/test.replace
rm tests/test.replace

echo "test with sed"
sedtest tests/test aaa zzz
sedtest tests/test1 cat fox
sedtest tests/test1 " " test