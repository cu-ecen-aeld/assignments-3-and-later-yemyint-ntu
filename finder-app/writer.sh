#!/bin/sh

writefile=$1
writestr=$2

if [ $# -lt 2 ]; then
  echo "arguments missing"
  exit 1
fi 

DIR="$(dirname "${writefile}")"
if [ ! -d $DIR ]; then
  mkdir -p $DIR
fi 

echo $writestr > $writefile


