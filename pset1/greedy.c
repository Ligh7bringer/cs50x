#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float change = 0;
    int coins = 0;
    
    do {
    printf("How much change?:\n");
    change = GetFloat();
   } while (change < 0);  
   
   int cents = round(change*100);
   
      
   while (cents -25 >= 0 ) {
        cents = cents-25;
        coins++;
   }
   while (cents - 25 >= 0 ) {
        cents = cents-25;
        coins++;
   }
     while (cents - 10 >= 0 ) {
        cents = cents-10;
        coins++;
   }
        while (cents - 5 >= 0 ) {
        cents = cents-5;
        coins++;
   }
        while (cents - 1 >= 0 ) {
        cents = cents-1;
        coins++;
   }
     
   printf("%i\n", coins); 
   
}  
