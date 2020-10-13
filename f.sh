#!/bin/bash

foo()
{
echo "Function execution"
}

myfun()
{
echo "function call with:$@"
x=2
}

echo "script start"
foo
x=1
echo "$x"
myfun 1 2 3 
echo "$x"

echo "script end"


