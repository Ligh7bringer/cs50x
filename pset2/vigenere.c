#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {
    if (argc != 2 ) { 
        printf("./vigenere <key>\n");
        return 1;
    } else if(argv[1]) {    
        int l = strlen(argv[1]);
        for(int i=0; i<l; i++) {
            if(!isalpha(argv[1][i])) {
                 printf("./vigenere <key>\n");
                 return 1;
            }
        }
    }
    
    string text = GetString();
    int l = strlen(text);
    string key = argv[1]; 
    int control;
    int m = 0;
    
    for(int i=0; i<l; i++) {          
         if(isalpha(text[i]) && islower(text[i])) {
            control = m % strlen(key);
                  if(islower(key[control])) {                        
                        int result = (key[control] - 97 + text[i] - 97) % 26;
                        printf("%c", result + 97);    
                } else {                     
                    int result = (key[control] - 65 + text[i] - 97) % 26;
                    printf("%c", result + 97); 
                }
            m++;
       } else if(isalpha(text[i]) && isupper(text[i])) {
            control = m % strlen(key);
                  if(islower(key[control])) {            
                    int result = (key[control] - 97 + text[i] - 65) % 26;
                    printf("%c", result + 65); 
                } else {
                    int result = (key[control] - 65 + text[i] - 65) % 26;
                    printf("%c", result + 65); 
                }  
            m++;     
       } else {
            printf("%c", text[i]);
       }    
   }
    printf("\n");
}

