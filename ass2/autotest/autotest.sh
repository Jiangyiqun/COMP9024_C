#!/bin/bash

# check whether the test directory exists
if [ ! -d pagerank_test00 ]     
then
    mkdir pagerank_test00
fi

if [ ! -d inverted_test00 ]     
then
    mkdir inverted_test00
fi

if [ ! -d searchPagerank_test00 ]     
then
    mkdir searchPagerank_test00
fi

testPagerank(){
    DIR=$1      # the directory of test case
    D_FACTOR=$2
    MAX_DIFF=$3
    MAX_ITER=$4

    # check whether the test directory exists
    if [ ! -d $DIR ]
    then
        echo "Could not find $DIR/ directory, test aborted!"
        return 0
    fi

    # clean up test direcotry
    rm -f ./$DIR/pagerankList.txt ./$DIR/pagerank
    # copy excutable file to test directory
    cp ./pagerank_test00/pagerank ./$DIR/pagerank

    cd $DIR     # must change directory before excuting
    ./pagerank $D_FACTOR $MAX_DIFF $MAX_ITER
    cd ..       # return back

    if diff <(sed 's/..$/00/' ./$DIR/pagerankList.txt) <(sed 's/..$/00/' ./$DIR/pagerankList.exp) &> /dev/null    # substitute last two charactor with 00
    then
        echo "$DIR Test Succeeded! \(^_^)/"        
    else
        echo "$DIR Test Failed! /(ㄒoㄒ)\\"
        echo "'pagerank $D_FACTOR $MAX_DIFF $MAX_ITER'"
        echo "Your Output                                                    Expected Output"
        echo "-----------                                                    ---------------"
        diff -y ./$DIR/pagerankList.txt ./$DIR/pagerankList.exp
        echo
    fi
}


testSearchPagerank(){
    DIR=$1      # the directory of test case
    # $2 ~ $9 are searching keywords

    # check whether the test directory exists
    if [ ! -d $DIR ]
    then
        echo "Could not find $DIR/ directory, test aborted!"
        return 0
    fi

    # clean up test direcotry
    rm -f ./$DIR/searchResult.txt ./$DIR/searchPagerank
    # copy excutable file to test directory
    cp ./searchPagerank_test00/searchPagerank ./$DIR/searchPagerank

    cd $DIR     # must change directory before excuting
    ./searchPagerank $2 $3 $4 $5 $6 $7 $8 $9 > searchResult.txt
    cd ..       # return back

    if diff -Z ./$DIR/searchResult.txt ./$DIR/searchResult.exp &> /dev/null    # substitute last two charactor with 00
    then
        echo "$DIR Test Succeeded! \(^_^)/"
    else
        echo "$DIR Test Failed! /(ㄒoㄒ)\\"
        echo "'searchPagerank $2 $3 $4 $5 $6 $7 $8 $9'"
        echo "Your Output                                                    Expected Output"
        echo "-----------                                                    ---------------"
        diff -y -Z ./$DIR/searchResult.txt ./$DIR/searchResult.exp
        echo
    fi
}







# test pagerank
if [ -e "./submit/pagerank.c" ]
then
    rm -f ./pagerank_test00/*   # clean up test directory
    cp submit/*.c submit/*.h ./pagerank_test00    # copy source code to test directory
    rm -f ./pagerank_test00/inverted.c ./pagerank_test00/searchPagerank.c   # exclude unused source code
    if gcc -Wall -lm -Werror ./pagerank_test00/*.c  -o ./pagerank_test00/pagerank
    then
        testPagerank pagerank_test01 0.85 0.00001 1000
        testPagerank pagerank_test02 0.85 0.00001 1000
        testPagerank pagerank_test03 0.85 0.00001 1000
    fi
else
    echo "pagerank.c does not exit, skip testing pagerank module!"
fi




# test inverted
if [ -e "./submit/inverted.c" ]
then
    rm -f ./inverted_test00/*   # clean up test directory
    cp submit/*.c submit/*.h ./inverted_test00    # copy source code to test directory
    rm -f ./inverted_test00/pagerank.c ./inverted_test00/searchPagerank.c   # exclude unused source code
    if gcc -Wall -lm -Werror ./inverted_test00/*.c  -o ./inverted_test00/inverted
    then
        echo "Compile inverted finished, testing inverted..."


    fi
else
    echo "inverted.c does not exit, skip testing inverted module!"
fi




# test searchPagerank
if [ -e "./submit/searchPagerank.c" ]
then
    rm -f ./searchPagerank_test00/*   # clean up test directory
    cp submit/*.c submit/*.h ./searchPagerank_test00    # copy source code to test directory
    rm -f ./searchPagerank_test00/pagerank.c ./searchPagerank_test00/inverted.c   # exclude unused source code
    if gcc -Wall -lm -Werror ./searchPagerank_test00/*.c  -o ./searchPagerank_test00/searchPagerank
    then
        testSearchPagerank searchPagerank_test01 vegetation design
        testSearchPagerank searchPagerank_test02 vegetation design nowheretobefound
    fi
else
    echo "searchPagerank.c does not exit, skip testing searchPagerank module!"
fi