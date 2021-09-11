if [ $(grep "tree "$1" "$2"" $3 | wc -l) -eq 0 ]; 
then
    echo "tree "$1" "$2" " >>$3
fi
