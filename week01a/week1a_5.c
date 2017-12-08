// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set
Define a data structure to store all information of a single ride with the Opal card. Here are two sample records

 You may assume that individual stops (such as "Anzac Pde D opp UNSW") require no more than 31 characters.

Q:
Determine the memory requirements of your data structure, assuming that each integer and floating point number takes 4 bytes.
A: 264bytes


Q:
If you want to store millions of records, how would you improve your data structure? 
A:
I don't know
*/

#include <stdio.h>
#include <stdlib.h>


int main(void) {
    printf("hello, world!\n");
    return EXIT_SUCCESS;
}

struct opal {
    int transactionNumber;  // 1
    char dataTime[20];      // 20
    char mode;              // 1
    char details[31];       // 31
    int journeyNumber;      // 1
    char fareApplied[9];    // 9
    float fare;             // 1
    float discount;         // 1
    float amount;           // 1
    // sum = 66
    // 66 * 4 = 264 bytes
};