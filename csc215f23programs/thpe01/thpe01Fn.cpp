/** *************************************************************************
 * @file
 ***************************************************************************/
#include "netPBM.h" 
/** ***************************************************************************
 * @author Zackery Holloway 
 *
 * @par Description:
 * This function process the error messages and prints our the correct error.
 * It will also close any memory and file and return 0.
 * @param[in] int num - the command line argument 
 * @param[in] string file - if needed the file name of argument
 *
 * @par Example:
   @verbatim

   usage( 5, "nouse );

   Output:
   Unable to allocate memory
        exit(0);
   @endverbatim
 *
 ******************************************************************************/
void usage ( int num, string file )
{
    image img;
    if (num == 0)
    {
        cout << fixed << left <<
            "thpe01.exe [option] --outputtype basename image.ppm" << endl << endl;
        cout << "Output Type" << "      " << "Output Description" << endl;
        cout << "    " << "--ascii" << "      " <<
            "integer text numbers will be written for the data" << endl;
        cout << "    " << "--binary" << "     " << "integer numbers will be written in binary form"
            << endl << endl;
        cout << "Option Code" << "      " << "Option Description" << endl;
        cout << "    " << "--smooth" << "     " << "Blur a color image" << endl;
        cout << "    " << "--sharpen" << "    " << "Enhance the lines in a color image" << endl;
        cout << "    " << "--negate" << "     " << "Create a negative of a color image" << endl;
        cout << "    " << "--brighten" << " # " << "Add the provide (+/-) number to each pixel"
            << endl;
        cout << "    " << "--grayscale" << "  " << "Convert image to grayscale" << endl;
        cout << "    " << "--contrast" << "   " <<
            "Convert a color image to grayscale and scale the pixel values" << endl;
        exit(0);
    }
    else if (num == 1)
    {
        cout << "Invalid output type" << endl;
        cout << fixed << left <<
            "thpe01.exe [option] --outputtype basename image.ppm" << endl << endl;
        cout << "Output Type" << "      " << "Output Description" << endl;
        cout << "    " << "--ascii" << "      " <<
            "integer text numbers will be written for the data" << endl;
        cout << "    " << "--binary" << "     " << "integer numbers will be written in binary form"
            << endl << endl;
        cout << "Option Code" << "      " << "Option Description" << endl;
        cout << "    " << "--smooth" << "     " << "Blur a color image" << endl;
        cout << "    " << "--sharpen" << "    " << "Enhance the lines in a color image" << endl;
        cout << "    " << "--negate" << "     " << "Create a negative of a color image" << endl;
        cout << "    " << "--brighten" << " # " << "Add the provide (+/-) number to each pixel"
            << endl;
        cout << "    " << "--grayscale" << "  " << "Convert image to grayscale" << endl;
        cout << "    " << "--contrast" << "   " <<
            "Convert a color image to grayscale and scale the pixel values" << endl;
        exit(0);
    }
    else if (num == 2)
    {
        cout << "Invalid option" << endl;
        cout << fixed << left <<
            "thpe01.exe [option] --outputtype basename image.ppm" << endl << endl;
        cout << "Output Type" << "      " << "Output Description" << endl;
        cout << "    " << "--ascii" << "      " <<
            "integer text numbers will be written for the data" << endl;
        cout << "    " << "--binary" << "     " << "integer numbers will be written in binary form"
            << endl << endl;
        cout << "Option Code" << "      " << "Option Description" << endl;
        cout << "    " << "--smooth" << "     " << "Blur a color image" << endl;
        cout << "    " << "--sharpen" << "    " << "Enhance the lines in a color image" << endl;
        cout << "    " << "--negate" << "     " << "Create a negative of a color image" << endl;
        cout << "    " << "--brighten" << " # " << "Add the provide (+/-) number to each pixel"
            << endl;
        cout << "    " << "--grayscale" << "  " << "Convert image to grayscale" << endl;
        cout << "    " << "--contrast" << "   " <<
            "Convert a color image to grayscale and scale the pixel values" << endl;
        free2d(img, img.rows);
        exit(0);
    }
    else if (num == 3)
    {
        cout << "Unable to open the file: " << file << endl;
        exit(0);
    }
    else if (num == 4)
    {
        cout << "Not a valid netpbm image" << endl;
        exit(0);
    }
    else if (num == 5)
    {
        cout << "Unable to allocate memory" << endl;
        exit(0);
    }
}