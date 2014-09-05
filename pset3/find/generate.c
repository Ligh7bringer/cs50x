/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checks if the program has 1 or 2 arguments, and if it doesn't, it prints the correct usage and then the program ends
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Converts the first argument to an integer and assigns the converted value to a variable n
    int n = atoi(argv[1]);

    /** Checks if the program has 2 arguments. If it does, it calls the random generator which uses the second argument as  
    * a seed.
    * If there's only 1 argument, it doesn't uses the current seconds as a seed.
    */ 
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // Creates a loop which cycles n times (n is equal to the first argument). It prints a random number modulo 65536 (the 
    // value of the constant LIMIT)
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks
    return 0;
}
