/** *************************************************************************
 * @file
 ***************************************************************************/
#include <iostream>
#include<fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <math.h>



using namespace std;
#ifndef __NETPBM__H__
#define __NETPBM__H__
typedef unsigned char pixel;
struct image
{
    string magicNumber;
    string comment;
    int rows;
    int cols;
    pixel **redgray;
    pixel **green;
    pixel **blue;
};
// place functions here 

#endif // !__NETPBM__H__

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

void readHeader ( char* argv[], image& img, int num );
void readPPMFileAscii ( ifstream & fin, image& stru );
void readPPMFileBinary ( ifstream& file, image& img );


void alloc2d ( int rows, int cols, image& img );
void free2d ( image img, int rows );


void writePPMFileAscii ( string filename, image img, int rows, int cols, char* argv );
void writePPMFileBinary ( string filename, image img, int rows, int cols, char* argv );


void opperator ( char * argv[], image& stru, int argc );
void negate ( image& stru );
void brighten ( image& img, string value );
void sharpen ( image& img );
void smooth ( image& img );
void grayscale ( image& img, int& minval, int& maxval );
void contrast ( image& img );

void allocate2dOper ( int**& ptr, int rows, int  cols );
void usage ( int num, string file );