/*
    g++ -o is used to make exe from .os
    g++ -c is used to make .os from .cpp

    steps:
        1)make .os of all cpp files: g++ -c a.cpp
        2)link all .os and make executable: g++ a.o b.o main.o -o my_program
 */


// algorithm.h ->header file
#ifndef ALGORITHM_H // guard # to avoid re-declaration
#define ALGORITHM_H

// function
// someone's international patennted logic
void sort(int arr[], int n); // declaration

#endif 