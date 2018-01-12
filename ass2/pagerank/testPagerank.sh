if gcc -Wall -lm -Werror *.c  -o pagerank
then
    if ./pagerank 0.85 0.00001 1000
    then
        echo "Your Output                                                    Expected Output"
        echo "-----------                                                    ---------------"
        diff -y pagerankList.txt pagerankList.exp
    fi
fi