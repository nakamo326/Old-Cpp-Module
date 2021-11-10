#! /bin/bash

function test () {
  ./replace $1 $2 $3
  sed=`sed -e 's/$2/$3/g' $1`
}

test tests/test aaa zzz