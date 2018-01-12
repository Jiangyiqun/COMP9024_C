#!/bin/sh
FILE0=pagerank     #FILE0 is the file to be tested
FILE1=inverted     #FILE1 is the file to be excluded
FILE2=searchPagerank     #FILE1 is the file to be excluded

test() {
    DIR=$1
    # check whether the test directory exists
    if [ ! -d $DIR ]
    then
        echo "No $DIR/ directory here. Are you in the right directory?"
        exit 1
    fi

    rm -f ./$DIR/$FILE0 ./$DIR/*.c ./$DIR/*.h ./$DIR/*.o ./$DIR/pagerankList.txt    # clean up test direcotry
    cp *.c *.h ./$DIR    # copy files to test directory
    rm -f ./$DIR/$FILE1.* ./$DIR/$FILE2.*   # delete unused file

    if gcc -Wall -lm -Werror *.c  -o ./$DIR/$FILE0
    then
        cd $DIR     # must change directory before excuting
        if ./$FILE0 0.85 0.00001 1000
        then
            # display test result
            echo "                      $FILE0 test report of $DIR"
            echo "Your Output                                                    Expected Output"
            echo "-----------                                                    ---------------"
            diff -y ./pagerankList.txt ./pagerankList.exp
            echo .
            # change back to the current directory and clean the test directory
            cd ..   
            rm -f ./$DIR/$FILE0 ./$DIR/*.c ./$DIR/*.h ./$DIR/*.o ./$DIR/pagerankList.txt    # clean up test direcotry
        else
            # change back to the current directory and clean the test directory
            cd ..   # change back to the current directory
            rm -f ./$DIR/$FILE0 ./$DIR/*.c ./$DIR/*.h ./$DIR/*.o ./$DIR/pagerankList.txt    # clean up test direcotry
            exit 1
        fi
    else
        exit 1
    fi
}

test aEx1
test aEx2
test aEx3