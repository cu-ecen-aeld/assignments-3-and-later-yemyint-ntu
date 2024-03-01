#!/bin/sh

filesdir=$1
searchstr=$2

if [ $# -lt 2 ]; then
  echo "filesdir and/or searchstr were not specified"
  exit 1
fi

if [ -d filesdir ]; then
  echo "filesdir is not a valid directory"
  exit 1
fi

count="$(grep -r "$searchstr" $filesdir | wc -l)"

echo "The number of files are ${count} and the number of matching lines are ${count}"
