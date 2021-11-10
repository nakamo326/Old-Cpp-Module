#! /bin/bash

touch tests/permission
chmod 000 tests/permission

function test() {
  cat_result=`/bin/cat ${@} 2>&1`
  cat9_result=`./cato9tails ${@} 2>&1`
  if [ "$cat_result" != "$cat9_result" ]; then
    echo "[failed]"
  else
    echo "[passed]"
  fi
  diff <(echo "$cat_result") <(echo "$cat9_result")
}

test tests/txt1
test tests/txt2
test tests/txt1 tests/txt2
test tests/txt1 tests/txt2 Cat.cpp
test no_such_file
test tests/permission
test tests/txt2 no_such_file
test no_such_file tests/txt2
test tests/permission tests/txt2
test tests/txt2 tests/permission