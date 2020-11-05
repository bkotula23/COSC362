#include <stdio.h>
#include <stdlib.h>
#include "MyFunctions.h"
/*
 * This is a c program. It will create a purple circle as a ppm.
 * Useage:
 *
 * PurpleCircle OutFileName numRows numCols radius
 *
 * Here our program is taking an out file name and three arguements that detail the size
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
    int radius;                 // The length of the radius of the circle
//    int rad2;
//    int rad3;
    int InOut;                  // Flag where (0  = out of the circle, 1 = in the circle)
    unsigned char *outImage; 	//pixel pointer for my output image
    unsigned char *ptr;		// a moving pointer
    FILE *outputFP;		//Pointer to the output file

    printf("==================================================\n");
    printf("I'm making a plain pixel map of a circle          \n");
    printf("==================================================\n");

    if(argc != 5){
        printf("Usage: ./PurpleCircle OutFileName numRows NumCols radius1 radius2 radius3 \n");
        exit(1);
    }
    if( (numRows = atoi(argv[2]) ) <= 0){
        printf("Error: number of Rows needs to be positive! \n");
    }
    if( (numCols = atoi(argv[3]) ) <= 0){
        printf("Error: number of Columns needs to be postitive! \n");
    }
    if( (radius = atoi(argv[4]) ) <= 0){
        printf("What are you thinking? A negative value for a circle's radius? \n");
    //also need the if statement above for radius 2 and 3
    }

    // ========================================================
    // Set up a storage space for the image.
    // ========================================================
    imageSize = numRows*numCols*3;
    outImage = (unsigned char *)malloc(imageSize); //getting the space for the image

    // Open File for the output image to go into
    if ((outputFP = fopen(argv[1], "w")) == NULL){
       perror("output open error!");
       printf("Error: cannot open the file. \n");
       exit(1);
    }

    // Lets make the image.
    ptr = outImage;
    for(row = 0; row < numRows; row++){
        for(col = 0; col < numCols; col++){
        //walk accorss the image row column by column.
            InOut = InCircle(numRows, numCols, radius, row, col);
            if(InOut == 1){
                    //Purple Pixel
	       	*ptr = 128;
		*(ptr + 1) = 0;
		*(ptr + 2) = 128;
            } else{
		//white pixel
		*ptr = 255;
		*(ptr + 1) = 255;
		*(ptr + 2) = 255;
            }
	    // Advance the pointer
	    ptr += 3;
        }
        for(col = 0; col < numCols; col++){
             InOut = InCircle(numRows, numCols, radius, row, col);
             if(InOut == 1){
                   //white pixel
                *ptr=255;
                *(ptr +1) = 255;
                *(ptr +2) = 255;
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
