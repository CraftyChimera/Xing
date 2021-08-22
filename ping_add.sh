#!/bin/bash

pa=$(pwd)/.ping/objects
ping=$(pwd)/.ping

function hashfile() {
    (cat $1;echo $1;) | sha1sum | awk '{print $1}'
}
function hashtree() {
    (echo $1;ls -A $1;) | sha1sum | awk '{print $1}'
}

function check() {
    a=$(ls -a $1 | wc -l)
    if [ $a -gt 1 ] 
    then
        echo "Directory"
    else
        echo "File"
    fi
}

function addfile() {
    if [ $(check $1) == "File" ]; then
        b=$(hashfile $1)
        cp $1 $(pwd)/.ping/objects/$b
    fi
}
function addTree() {
    A=$(pwd)/$(cat $1 | head -1)
    cd $A
    for file in $(ls -A $A); do
        if [ $(check $file) == "File" ]; then
            if [ $(grep "node $(hashfile $file) $file" $1 | wc -l) -eq 0 ]; then
                echo node $(hashfile $file) $file >>$1
                echo "$(hashfile $file) $(pwd)/$file">>${ping}/index
                cp $file ${pa}/$(hashfile $file)
            fi
        else
            echo tree $(hashtree $file) $file >>$1
            echo $file >>${pa}/$(hashtree $file)
            addTree ${pa}/$(hashtree $file)
        fi
    done
    cd ..
}
#driver
if [ $(check "$1") == "File" ]; then
    if [ $(grep "node $(hashfile "$1") "$1"" $(pwd)/.ping/index | wc -l) -eq 0 ]; then
        echo node $(hashfile "$1") "$1" >>$(pwd)/.ping/index
        cp "$1" ${pa}/$(hashfile "$1")
    fi

else
    if [ $(grep "$1" ${pa}/$(hashtree "$1") | wc -l) -eq 0 ]; then
        echo "$1" >>${pa}/$(hashtree "$1")
    fi
    addTree ${pa}/$(hashtree "$1")
fi
