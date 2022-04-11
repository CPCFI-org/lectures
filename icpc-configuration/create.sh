#!/bin/zsh

for i in {$1..$2}
do
    mkdir $i
    cd $i
    touch $i.{cpp,in,out}
    if [ $3 = 'basic' ]
    then
        cat ../cpp_template_basic.cpp > $i.cpp
    elif [ $3 = 'icpc' ]
    then
        cat ../cpcfi_template.cpp > $i.cpp
    else
    fi
    cd ../
done