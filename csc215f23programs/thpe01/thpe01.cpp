/** ***************************************************************************
 * @file
 *
 * @brief A program that creates an image opperation in binary and ascii.
 *****************************************************************************/
 /** ***************************************************************************
  * @mainpage THPE01 - Image Manipulation 
  *
  * @section M01
  *
  * @authors Zackery Holloway
  *
  * @date October 15, 2023
  *
  * @par Instructor
  *         Professor Roger Schrader
  *
  * @par Course
  *         CSC 215  - Section M01 - 9:00 am
  *
  * @par Location
  *         McLaury - Room 207
  *
  * @section program_section Program Information
  *
  * @details This programming assignment is to help you get a firm understanding of 2d arrays, dynamic memory
  * allocation, ascii data files and binary data files. To accomplish this, we will be using netpbm images. Only 4
  * of the 6 types will be used and they will have a .ppm or a .pgm extension. Data files with a .ppm extension
  * are color images and files with a .pgm extension are grayscale. Only color images (.ppm) will be used for
  * input. 
  *
  * Because of space, the rest of the details have been omitted.
  *
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *      None
  *
  * @par Usage
    @verbatim
   C:\>thpeOl.exe [option] --[ascii | binary] basename image.ppm 
        —-smooth smooth three color bands of the image. 
        —-sharpen sharpen the 3 color bands of the image.
        ——negate negate each pixel in the rgb arrays.
        —-brighten # brighten image by set number
        —-grayscale makes a gray scale of image 
        —-contrast brightens image with grayscale
        --ascii outputs ascii data type
        -- binary outputs binary data type 
    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications
  *
  * @bug Issues in smooth and sharpen 
  * @bug Crashes if wrong arguments are given even though exit 0
  *
  *
  * @par Modifications and Development Timeline:
  *     <a href="https://gitlab.cse.sdsmt.edu/101113328/csc215f23programs/-/pipelines" target=_blank>
  *     Gitlab Commit Log</a>
  *
  *****************************************************************************/
#include "netPBM.h" 

using namespace std;
/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description
 * This is the starting point to the program. Based on command line arguments
 * it will process the image as binary or ascii.  This will also run
 * the opperation command to make the needed changes to the image. If the 
 * options provied are not correct it will exit with error code. 
 *
 * @param[in] argc - the number of arguments from the command prompt.
 * @param[in] argv - the opperation commands 
 *
 * @returns 0 system success 
 *
 * *****************************************************************************/
int main ( int argc, char* argv[] )
{
    fstream file;
    image stru;
    int num;
    num = argc;
    if (argc == 4)
    {
        if ((strcmp(argv[1], "--ascii")==0))
        {
            readHeader(argv, stru,num);
            writePPMFileAscii(argv[2],stru, stru.rows, stru.cols, argv[1]);
            free2d(stru, stru.rows);
        }
        else if ((strcmp(argv[1], "--binary") == 0))
        {
            readHeader(argv, stru, num);
            writePPMFileBinary(argv[2], stru, stru.rows, stru.cols, argv[1]);
            free2d(stru, stru.rows);
        }
        else
        {
            usage(1,"nouse");
        }
    }
    else if (argc == 5)
    {
            if ((strcmp(argv[2], "--ascii") == 0))
            { 
                readHeader(argv, stru, num);
                opperator(argv, stru, argc);
                writePPMFileAscii(argv[3], stru, stru.rows, stru.cols, argv[1]);
                free2d(stru, stru.rows);
            }
            else if ((strcmp(argv[2], "--binary") == 0))
            {
                readHeader(argv, stru, num);
                opperator(argv, stru, argc);
                writePPMFileBinary(argv[3], stru, stru.rows, stru.cols, argv[1]);
                free2d(stru, stru.rows);
            }
            else
            {
                usage(1, "nouse");
            }    
    }
    else if (argc == 6)
    {
        if ((strcmp(argv[3], "--ascii") == 0))
        {
            readHeader(argv, stru, num);
            opperator(argv, stru, argc);
            writePPMFileAscii(argv[4], stru, stru.rows, stru.cols, argv[1]);
            free2d(stru, stru.rows);
        }
        else if ((strcmp(argv[3], "--binary") == 0))
        {
            readHeader(argv, stru, num);
            opperator(argv, stru, argc);
            writePPMFileBinary(argv[4], stru, stru.rows, stru.cols, argv[1]);
            free2d(stru, stru.rows);
        }
        else
        {
            usage(1, "nouse");
        }
    }
    else
    {
        usage(0, "nouse");
    }
    return 0;
}