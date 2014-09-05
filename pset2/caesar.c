#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("./caesar <key>\n");
        return 1;
    } 
         
    int key = atoi(argv[1]);
    if(key < 0)
    {
        printf("That is not valid\n");
        return 1;
    }
    
    string text = GetString();
    
    int n=strlen(text);       
    for(int i=0; i<n; i++) {
        if(isalpha(text[i]) && islower(text[i])) {
           int result = (text[i] - 97 + key) % 26;
           printf("%c", result + 97);                     
        } else if(isalpha(text[i]) && isupper(text[i])) {
           int result = (text[i] - 65 + key) % 26;
           printf("%c", result + 65);               
        } else {
            printf("%c", text[i]);
        }
    }
        printf("\n");
}
