/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdbool.h>
//Stuff we'll need
char buffer[512];
bool search(void) {
	if (buffer[0] ==(char)255 && buffer[1] == (char)216 && buffer[2] == (char)255 && (buffer[3] == (char)224 || buffer[3] == (char)225)) {
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	FILE* card = fopen("card.raw", "r");
	if (card == NULL) {
		printf("Something went wrong :(\n");
		return 1;
	} 
	
	int counter = 0;
	FILE* outp = NULL;
		
	while(fread(&buffer, sizeof(char), 512, card) == 512) {
		 if(search())  {
		 	if (outp != NULL)
                fclose(outp);
		 	char filename[8];
			sprintf(filename, "%03d.jpg", counter);	
			outp = fopen(filename, "a");
			counter++;
			} 
				if(outp != NULL) {	
					fwrite(&buffer, sizeof(buffer), 1, outp);	
				}
				//fseek(outp, -sizeof(buffer), SEEK_CUR);				
			}				
		 			
	
	fclose(card);
	fclose(outp);	
	return 0;	
}

