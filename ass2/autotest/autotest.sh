#!/bin/bash
# Author: Jack Jiang (z5129432)
# Data: 2018x1
# Description: auto test for COMP9024 Assignment 2
#     if you want to modify the test cases
#     go to the bottom of this file, I have comments there


######################################## local functrion definations ############################################

update(){
    echo -n $DATE_TODAY > .log     # generate new log
    if git pull | grep -q "Already up-to-date."
    then    # if it already up-to-date, break and continue
        echo "Already up-to-date."
    else    # need to re start autotest
        echo "Update Finished! You may need to restart autotest.sh!"
        exit 1
    fi
}


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
    START_TIME=$(date +%s.%N)       # start tracking the testing time
    ./pagerank $D_FACTOR $MAX_DIFF $MAX_ITER
    # generate running time
    END_TIME=$(date +%s.%N)
    RUNNING_TIME=$(echo "$END_TIME - $START_TIME" | bc)
    cd ..       # return back

    if [ -e ./$DIR/pagerankList.txt ]
    then
        if diff -b -B <(sed 's/.$/0/' ./$DIR/pagerankList.txt) <(sed 's/.$/0/' ./$DIR/pagerankList.exp) &> /dev/null    # substitute last two charactor with 00
        then
            echo "$DIR Test Succeeded in $RUNNING_TIME seconds"        
            if [ $FULL_RESULT = 1 ]
            then
                echo "      'pagerank $D_FACTOR $MAX_DIFF $MAX_ITER'"
                echo "Your Output                                                    Expected Output"
                echo "-----------                                                    ---------------"
                diff -y -b -B ./$DIR/pagerankList.txt ./$DIR/pagerankList.exp
                echo "The last one digits will be ignored when compare"
                echo
            fi
        else
            echo "$DIR Test Failed in $RUNNING_TIME seconds"
            echo "      'pagerank $D_FACTOR $MAX_DIFF $MAX_ITER'"
            echo "Your Output                                                    Expected Output"
            echo "-----------                                                    ---------------"
            diff -y -b -B ./$DIR/pagerankList.txt ./$DIR/pagerankList.exp
            echo "The last one digits will be ignored when compare"
            echo
        fi
    else
        echo "$DIR Test Failed! ~(ToT)~"
        echo "      'pagerank $D_FACTOR $MAX_DIFF $MAX_ITER'"
        echo "      ./$DIR/pagerankList.txt has not been generated"
    fi
}


testinverted(){
    DIR=$1      # the directory of test case

    # check whether the test directory exists
    if [ ! -d $DIR ]
    then
        echo "Could not find $DIR/ directory, test aborted!"
        return 0
    fi

    # clean up test direcotry
    rm -f ./$DIR/invertedIndex.txt ./$DIR/inverted
    # copy excutable file to test directory
    cp ./inverted_test00/inverted ./$DIR/inverted

    cd $DIR     # must change directory before excuting
    START_TIME=$(date +%s.%N)       # start tracking the testing time
    ./inverted
    # generate running time
    END_TIME=$(date +%s.%N)
    RUNNING_TIME=$(echo "$END_TIME - $START_TIME" | bc)
    cd ..       # return back

    if [ -e ./$DIR/invertedIndex.txt ]
    then
        if diff -b -B ./$DIR/invertedIndex.txt ./$DIR/invertedIndex.exp &> /dev/null
        then
            echo "$DIR Test Succeeded in $RUNNING_TIME seconds"
            if [ $FULL_RESULT = 1 ]
            then
                echo "Your Output                                                    Expected Output"
                echo "-----------                                                    ---------------"
                diff -y -b -B ./$DIR/invertedIndex.txt ./$DIR/invertedIndex.exp
                echo
            fi
        else
            echo "$DIR Test Failed in $RUNNING_TIME seconds"
            echo "Your Output                                                    Expected Output"
            echo "-----------                                                    ---------------"
            diff -y -b -B ./$DIR/invertedIndex.txt ./$DIR/invertedIndex.exp
            echo
        fi
    else 
        echo "$DIR Test Failed! ~(ToT)~"
        echo "      ./$DIR/invertedIndex.txt has not been generated"
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
    START_TIME=$(date +%s.%N)       # start tracking the testing time
    ./searchPagerank $2 $3 $4 $5 $6 $7 $8 $9 | head -50 > searchResult.txt
    # generate running time
    END_TIME=$(date +%s.%N)
    RUNNING_TIME=$(echo "$END_TIME - $START_TIME" | bc)
    cd ..       # return back

    if diff -b -B ./$DIR/searchResult.txt ./$DIR/searchResult.exp &> /dev/null
    then 
        echo "$DIR Test Succeeded in $RUNNING_TIME seconds"
        if [ $FULL_RESULT = 1 ]
        then
            echo "      'searchPagerank $2 $3 $4 $5 $6 $7 $8 $9'"
            echo "Your Output                                                    Expected Output"
            echo "-----------                                                    ---------------"
            diff -y -b -B ./$DIR/searchResult.txt ./$DIR/searchResult.exp
            echo
        fi
        
    else
        echo "$DIR Test Failed in $RUNNING_TIME seconds"
        echo "      'searchPagerank $2 $3 $4 $5 $6 $7 $8 $9'"
        echo "Your Output                                                    Expected Output"
        echo "-----------                                                    ---------------"
        diff -y -b -B ./$DIR/searchResult.txt ./$DIR/searchResult.exp
        echo
    fi
}


######################################## main function #################################################

# First time start
if [ ! -f .log ]
then
    echo 
    echo "                             First Time Start"
    echo "    This autotest is written by Jack Jiang for the convenience of testing"
    echo "                      COMP9024 Assignment 2 in 2018x1"
    echo 
    echo "      ***** Please maximum terminal window to get the best format *****"
    echo 
    echo 
    echo " ****************************** User Manual *********************************"
    echo " * Usage: autotest [OPTION]                                                * "
    echo " * Test COMP9024 assignment 2                                              * "
    echo " *                                                                         * "
    echo " * test modules separately                                                 * "
    echo " *   p           test pagerank only                                        * "
    echo " *   i           test invertedIndex only                                   * "
    echo " *   s           test searchPagerank only                                  * "
    echo " *                                                                         * "
    echo " * by default, full result only shows when failed                          * "
    echo " *   f           always show full result                                   * "
    echo " *                                                                         * "
    echo " * In order to get the most recently added test cases                      * "
    echo " *   u           manually update this test script                          * "
    echo " *                                                                         * "
    echo " * all arguments above can be used together                                * "
    echo " * you can open README.md to refer to the same user manual                 * "
    echo " ****************************************************************************"
    echo "01/01/18" > .log   # mark this is not the first start
fi



# argument preprocess
MANUAL_UPDATE=0
FULL_RESULT=0
PAGERANK_TEST=0
INDEX_TEST=0
SERACH_TEST=0
for arg in "$@"
do
    if [ $arg = 'u' ]
    then
        MANUAL_UPDATE=1
    fi
    if [ $arg = 'f' ]
    then
        FULL_RESULT=1
    fi
    if [ $arg = 'p' ]
    then
        PAGERANK_TEST=1
    fi
    if [ $arg = 'i' ]
    then
        INDEX_TEST=1
    fi
    if [ $arg = 's' ]
    then
        SERACH_TEST=1
    fi
done
# if no module is selected, then test all modules
if [[ $PAGERANK_TEST = 0 ]] && [[ $INDEX_TEST = 0 ]] && [[ $SERACH_TEST = 0 ]]
then
    PAGERANK_TEST=1
    INDEX_TEST=1
    SERACH_TEST=1
fi


# update auto test
DATE_TODAY=$(date +"%x")
DATE_LOG=$(cat .log)
# manual update
if [ $MANUAL_UPDATE = 1 ]
then
    echo "Manual update"
    update
fi
# auto update
if [ ! $DATE_TODAY = $DATE_LOG ]    # compare the date today and in log
then # need to be update
    while :     # this loop will be break if user input y or no
    do
        echo -n "Your autotest may out-of-date, do you wish to update?(y or n):"
        read choice
        case $choice in
            y)  # choose to update
                update
                break
                ;;
            n)  # user cancelled update, break and continue
                echo -n $DATE_TODAY > .log     # generate new log
                echo "Auto update cancelled, I won't bother you today, you can still update manually"
                break
                ;;
            *)  # user input an wrong choise
                echo "Input Error! please choose y or n."
                ;;
        esac
    done
fi


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


# test pagerank
if [ $PAGERANK_TEST = 1 ]
then
if [ -e "./submit/pagerank.c" ]
    then
        rm -f ./pagerank_test00/*   # clean up test directory
        cp submit/*.c submit/*.h ./pagerank_test00    # copy source code to test directory
        rm -f ./pagerank_test00/inverted.c ./pagerank_test00/searchPagerank.c   # exclude unused source code
        if gcc -Wall -lm -Werror ./pagerank_test00/*.c  -o ./pagerank_test00/pagerank
        then
            ################################### modify your test case here ###################################
            testPagerank pagerank_test01 0.85 0.00001 1000
            testPagerank pagerank_test02 0.85 0.00001 1000
            testPagerank pagerank_test03 0.85 0.00001 1000
            # testPagerank pagerank_test04 0.85 0.00001 1000
            testPagerank pagerank_test05 0.00 0.00001 1000
            testPagerank pagerank_test06 0.50 0.00001 1000
            testPagerank pagerank_test07 1.00 0.00001 1000
            testPagerank pagerank_test08 0.85 0.00001 0
            testPagerank pagerank_test09 0.85 0.00001 1
            testPagerank pagerank_test10 0.85 0.00000 100000
            ################################### modify your test case here ###################################
        fi
    else
        echo "pagerank.c does not exit, skip testing pagerank module!"
    fi
fi


# test inverted
if [ $INDEX_TEST = 1 ]
then
    if [ -e "./submit/inverted.c" ]
    then
        rm -f ./inverted_test00/*   # clean up test directory
        cp submit/*.c submit/*.h ./inverted_test00    # copy source code to test directory
        rm -f ./inverted_test00/pagerank.c ./inverted_test00/searchPagerank.c   # exclude unused source code
        if gcc -Wall -lm -Werror ./inverted_test00/*.c  -o ./inverted_test00/inverted
        then
            ################################### modify your test case here ###################################
            testinverted inverted_test01
            testinverted inverted_test02
            testinverted inverted_test03
            testinverted inverted_test04
            ################################### modify your test case here ###################################
        fi
    else
        echo "inverted.c does not exit, skip testing inverted module!"
    fi
fi


# test searchPagerank
if [ $SERACH_TEST = 1 ]
then
    if [ -e "./submit/searchPagerank.c" ]
    then
        rm -f ./searchPagerank_test00/*   # clean up test directory
        cp submit/*.c submit/*.h ./searchPagerank_test00    # copy source code to test directory
        rm -f ./searchPagerank_test00/pagerank.c ./searchPagerank_test00/inverted.c   # exclude unused source code
        if gcc -Wall -lm -Werror ./searchPagerank_test00/*.c  -o ./searchPagerank_test00/searchPagerank
        then
            ################################### modify your test case here ###################################
            testSearchPagerank searchPagerank_test01 and were winds
            testSearchPagerank searchPagerank_test02
            testSearchPagerank searchPagerank_test03 mars utopian
            testSearchPagerank searchPagerank_test04 jack
            testSearchPagerank searchPagerank_test05 bot
            testSearchPagerank searchPagerank_test06 a on to
            testSearchPagerank searchPagerank_test07 wind winds planet planets no an and ear eu 
            ################################### modify your test case here ###################################
        fi
    else
        echo "searchPagerank.c does not exit, skip testing searchPagerank module!"
    fi
fi

echo "************************************ done ************************************"
echo
