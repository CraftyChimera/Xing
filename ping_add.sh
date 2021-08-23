#!/bin/bash

pa=$(pwd)/.ping/objects
ping=$(pwd)/.ping

function hashfile() {
    (cat $1;echo $1;) | sha1sum | awk '{print $1}'
}
function hashtree() {
(ls -A $1;pwd;) | sha1sum | awk '{print $1}';
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
        cp $1 $(pwd)/.ping/objects/$(hashfile $1)
    fi
}
function addTree() {
    cd $2
    for file in $(ls -A); do
        if [ $(check $file) == "File" ]; then
            if [ $(grep "node $(hashfile $file) $file" $1 | wc -l) -eq 0 ]; then
                echo node $(hashfile $file) $file >>$1
            if [ $(grep "$(hashfile $file) $(pwd)/$file" ${ping}/index | wc -l) -eq 0 ]; then
                echo "$(hashfile $file) $(pwd)/$file">>${ping}/index
            fi
                cp $file ${pa}/$(hashfile $file)
            fi
        else
            if [ $(grep "tree $(hashtree $file) $file" $1 | wc -l) -eq 0 ];then
            echo tree $(hashtree $file) $file >>$1
            fi
            addTree ${pa}/$(hashtree $file) $file
        fi
    done
    cd ..
}
#driver
if [ $(check "$1") == "File" ]; then
    if [ $(grep "$(hashfile "$1") $(pwd)/"$1"" $(pwd)/.ping/index | wc -l) -eq 0 ]; then
        echo "$(hashfile "$1") $(pwd)/"$1"" >>$(pwd)/.ping/index
        cp "$1" ${pa}/$(hashfile "$1")
    fi
else
    addTree ${pa}/$(hashtree "$1") $1
fi
cd ${ping}
cd ..
