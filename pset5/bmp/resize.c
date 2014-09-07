/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
	
	if(n < 1 || n > 100) {
		printf("n can have values [1; 100]\n");
		return 1;
	}

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //headers for output
    BITMAPFILEHEADER bfnew;
    BITMAPINFOHEADER binew;    
    binew = bi;
	bfnew = bf;
	
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingnew = (4 - (binew.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	
	// write outfile's BITMAPFILEHEADER
    // write outfile's BITMAPINFOHEADER
    bfnew.bfSize = 54 + binew.biWidth * abs(binew.biHeight) * 3 + abs(binew.biHeight) *  paddingnew;
    binew.biSizeImage =	((((binew.biWidth * binew.biBitCount) + 31) & ~31) / 8) * abs(binew.biHeight); 
    binew.biWidth = bi.biWidth * n;
    binew.biHeight = bi.biHeight * n; 
    
    fwrite(&bfnew, sizeof(BITMAPFILEHEADER), 1, outptr);    
    fwrite(&binew, sizeof(BITMAPINFOHEADER), 1, outptr);
	
        
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++) {
        
        for(int j = 0; j < n; j++) {        
        	// iterate over pixels in scanline
		    for (int k = 0; k < bi.biWidth; k++) {        	
						// temporary storage
						RGBTRIPLE triple; 		        
						
						// read RGB triple from infile
						fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
				
						for(int l = 0; l < n; l++) {
								fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);							
						}
	 	   }      
	 	  		fseek(inptr, padding, SEEK_CUR);
					
				for (int k = 0; k < paddingnew; k++) 
					fputc(0x00, outptr);		
				
				fseek(inptr, -(bi.biWidth * sizeof(RGBTRIPLE) + padding ), SEEK_CUR);
		}
			fseek(inptr, bi.biWidth*(sizeof(RGBTRIPLE))+padding, SEEK_CUR);   
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
