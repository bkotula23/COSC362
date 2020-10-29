#include <stdio.h>
#include <stdlib.h>

/*
 * This is a c program. It will create a red and blue pixel map.
 * Useage:
 *
 * RedBluePPM outfileName numRows numCols
 *
 * Here our program is taking an out file name and two arguements that detail the size
 * of the image we are creating.
 *
 */

int main(int argc,	// This is the number of arguments passed to the function.
         char *argv[]   // This is the array of stuff passed to me.
         ){

    int numRows;		// The number of rows place holder
    int numCols;		// The number of columns for image
    int imageSize;		// Total pixels in the image
    int row, col;		// Counters for the rows and columns of the image
    unsigned char *outImage; 	//pixel pointer for my output image
    unsigned char *ptr;		// a pointer
    FILE *outputFP;		//Pointer to the output file

    printf("=============================\n");
    printf("I'm making an image          \n");
    printf("=============================\n");

    if(argc != 4){
        printf("Usage: ./RedBluePPM OutFileName rowsize colsize \n");
        exit(1);
    }
    if( (numRows = atoi(argv[2]) ) <= 0){
        printf("Error: number of Rows needs to be positive. \n");
    }
    if( (numCols = atoi(argv[3]) ) <= 0){
        printf("Error: number of Columns need to be postitive. \n");
    }

    // ========================================================
    // Set up a storage space for the image.
    // ========================================================
    imageSize = numRows*numCols*3;
    outImage = (unsigned char *)malloc(imageSize); //getting the space for the image

    // Open File for the output image to go into
    if ((outputFP = fopen(argv[1], "w")) == NULL){
        perror("output open error");
        printf("Error: cannot open the file. \n");
        exit(1);
    }

    // Lets make the image.
    ptr = outImage;
    for(row = 0; row < numRows; row++){
        for(col = 0; col < numCols; col++){
        //walk accorss the image row column by column.
            if( col < numCols/2){
                //Red Pixel
		*ptr = 255;
		*(ptr + 1) = 0;
		*(ptr + 2) = 0;
            } else{
		//green pixel
		*ptr = 0;
		*(ptr + 1) = 255;
		*(ptr + 2) = 0;
            }
	    // Advance the pointer
	    ptr += 3;
        }
    }

    // ========================================================
    // Put all of the collness into the file.
    // ========================================================
    fprintf(outputFP, "P6 %d %d 255\n", numCols, numRows);
    fwrite(outImage, 1, imageSize, outputFP);
   
   
    //Done
    fclose(outputFP);

    return 0;
}
