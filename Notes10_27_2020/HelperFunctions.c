/* This is a bunch of stuff to use in my pixel mapping. */
#include <math.h> //Allow us to use the pow(x,y) --> x^y

int InCircle(int totalrows, int totalcols, int radius, int pixRow, int pixCol){
    int InOrOut = 0; // 0 ==> No, 1 ==> Yes for being in the circle.

    int Centerx = totalcols/2;
    int Centery = totalrows/2;
    int dist    = 0;

    dist = pow( (pow(Centerx - pixCol,2) + pow(Centery - pixRow,2) ), 0.5);

    if( dist < radius){
        InOrOut = 1;
    }
    return InOrOut;
}
