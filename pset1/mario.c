#include <stdio.h>
#include <cs50.h>

int main(void) {
    int h = 0;
    
    do {
    printf("height:\n");
    h = GetInt();
   } while (h > 23 || h<0);
   
   
   for (int i=0; i<h; i++) {
        for (int j = 0; j < (h+1)-(i+2); j++) {
        printf(" ");
        }
        for (int k = 0; k < i+2; k++) {
        printf("#");
        }
        printf("\n");
       }  
       
       
   
}
