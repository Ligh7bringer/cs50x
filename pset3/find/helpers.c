/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{  
    int start = 0, center, end = n-1;
    while(end >= start) {
        center = (start+end) / 2;
        if(values[center] > value) {
            start = 0; 
            end = center-1;               
        } else if(values[center] < value){
            start = center+1;            
        } else {
            return true;  
            break;         
        }
    }
   return false;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swapper;
    for(int k=0; k < n-1; k++) {
        for(int i = 0; i < n-k-1; i++) {
            if(values[i] >values[i+1]) {
               swapper = values[i]; 
               values[i] = values[i+1];
               values[i+1] = swapper;                                      
            }
        }
    }  
    return;
}
