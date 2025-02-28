/** *************************************************************************
 * @file
 ***************************************************************************/
#include "netPBM.h" 
/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function starts off the differnt operations based off the argv
 * @param[in] argv[] - array of strings that contain the opperators 
 * @param[in] image img - contatins the data for the image 
 * @param[in] int acrc - contaings number of arguments 
 *
 * @par Example:
   @verbatim

   opperator( --negate, img, 5);

   Output:
        image operation 
   @endverbatim
 *
 ******************************************************************************/
void opperator ( char* argv[], image& img, int argc )
{
    int minval, maxval;
    minval = 255;
    maxval = 0;
    if ((strcmp(argv[1], "--negate") == 0))
    {
        negate(img);
    }
    else if ((strcmp(argv[1], "--brighten") == 0))
    {
        brighten(img, argv[2]);
    }
    else if ((strcmp(argv[1], "--sharpen") == 0))
    {
        sharpen(img);
    }
    else if ((strcmp(argv[1], "--smooth") == 0))
    {
        smooth(img);
    }
    else if ((strcmp(argv[1], "--grayscale") == 0))
    {
        grayscale(img,minval,maxval);
    }
    else if ((strcmp(argv[1], "--contrast") == 0))
    {
        contrast(img);
    }
    else 
    {
        usage(2,"noUse");
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function negates the image 
 * @param[in] image img - contatins the data for the image
 *
 * @par Example:
   @verbatim

   negate(img);

   Output:
        negates the image 
   @endverbatim
 *
 ******************************************************************************/
void negate ( image& img )
{
    int i, j;
    for (i = 0; i < img.rows; i++)
    {
        for (j = 0; j < img.cols; j++)
        {
            img.redgray[i][j] = 255 - img.redgray[i][j];
            img.green[i][j] = 255 - img.green[i][j];
            img.blue[i][j] = 255 - img.blue[i][j];
        }
    }
}




/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function brightens the image 
 * @param[in] image img - contatins the data for the image
 * @param[in] string val - the value to be brighten
 *
 * @par Example:
   @verbatim

   brighten(img, 10);

   Output:
        brightens the image by 10 
   @endverbatim
 *
 ******************************************************************************/
void brighten ( image& img, string val )
{
    int value = stoi(val);
    for (int i = 0; i < img.rows; ++i) 
    {
        for (int j = 0; j < img.cols; ++j) 
        {
            img.redgray[i][j] = min(255, max(0, img.redgray[i][j] + value));
            img.green[i][j] = min(255, max(0, img.green[i][j] + value));
            img.blue[i][j] = min(255, max(0, img.blue[i][j] + value));
        }
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function sharpens the image
 * @param[in] image img - contatins the data for the image
 *
 * @par Example:
   @verbatim

   sharpen(img);

   Output:
        sharpens the image
   @endverbatim
 *
 ******************************************************************************/
void sharpen ( image& img )
{
    int i, j;
    int** newRedgray;
    int** newGreen;
    int** newBlue;
    allocate2dOper(newRedgray, img.rows, img.cols);
    allocate2dOper(newGreen, img.rows, img.cols);
    allocate2dOper(newBlue, img.rows, img.cols);
    for (i = 1; i < img.rows - 1; ++i)
    {
        for (j = 1; j < img.cols - 1; ++j)
        {
            newRedgray[i][j] = min(255, max(0,  5 * img.redgray[i][j] -
                - img.redgray[i - 1][j] 
                - img.redgray[i][j - 1] - img.redgray[i][j + 1]
                - img.redgray[i + 1][j]));
            newGreen[i][j] = min(255, max(0, 5 * img.green[i][j] -
                -img.green[i - 1][j]
                - img.green[i][j - 1] - img.green[i][j + 1]
                - img.green[i + 1][j]));
            newBlue[i][j] = min(255, max(0, 5 * img.blue[i][j] -
                -img.blue[i - 1][j]
                - img.blue[i][j - 1] - img.blue[i][j + 1]
                - img.blue[i + 1][j]));
        }
    }
    for (int i = 0; i < img.rows; ++i) 
    {
        delete[] img.redgray[i];
        delete[] img.green[i];
        delete[] img.blue[i];
        img.redgray[i] = (pixel*)newRedgray[i];
        img.green[i] = (pixel*)newGreen[i];
        img.blue[i] = (pixel*)newBlue[i];
    }

    // Clean up new arrays
    delete[] newRedgray;
    delete[] newGreen;
    delete[] newBlue;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function smooths the image
 * @param[in] image img - contatins the data for the image
 *
 * @par Example:
   @verbatim

   smooth(img);

   Output:
        smooths the image
   @endverbatim
 *
 ******************************************************************************/
void smooth ( image& img )
{
    int i, j;
    int** newRedgray;
    int** newGreen;
    int** newBlue;
    allocate2dOper(newRedgray, img.rows, img.cols);
    allocate2dOper(newGreen, img.rows, img.cols);
    allocate2dOper(newBlue, img.rows, img.cols);

    for (i = 1; i < img.rows - 1; ++i) 
    {
        for (j = 1; j < img.cols - 1; ++j)
        {
            newRedgray[i][j] = img.redgray[i][j] + img.redgray[i - 1][j - 1]
                + img.redgray[i - 1][j] + img.redgray[i - 1][j + 1]
                + img.redgray[i][j - 1] + img.redgray[i][j + 1]
                + img.redgray[i + 1][j - 1] - img.redgray[i + 1][j]
                + img.redgray[i + 1][j + 1];
            newGreen[i][j] = img.green[i][j] + img.green[i - 1][j - 1]
                + img.green[i - 1][j] + img.green[i - 1][j + 1]
                + img.green[i][j - 1] + img.green[i][j + 1]
                + img.green[i + 1][j - 1] - img.green[i + 1][j]
                + img.green[i + 1][j + 1];
            newBlue[i][j] = img.blue[i][j] + img.blue[i - 1][j - 1]
                + img.blue[i - 1][j] + img.blue[i - 1][j + 1]
                + img.blue[i][j - 1] + img.blue[i][j + 1]
                + img.blue[i + 1][j - 1] - img.blue[i + 1][j]
                + img.blue[i + 1][j + 1];
            img.redgray[i][j] = min(255, max(0, static_cast<int>(newRedgray[i][j] / 9)));
            img.green[i][j] = min(255, max(0, static_cast<int>(newGreen[i][j] / 9)));
            img.blue[i][j] = min(255, max(0, static_cast<int>(newBlue[i][j] / 9)));
            //cout << j << endl;
        }
        
        
    }
    for (int i = 0; i < img.rows; ++i) 
    {
        delete[] img.redgray[i];
        delete[] img.green[i];
        delete[] img.blue[i];
        img.redgray[i] = (pixel*)newRedgray[i];
        img.green[i] = (pixel*)newGreen[i];
        img.blue[i] = (pixel*)newBlue[i];
    }

    // Clean up new arrays
    delete[] newRedgray;
    delete[] newGreen;
    delete[] newBlue;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function grayscale the image
 * @param[in] image img - contatins the data for the image
 * @param[in] int minval - contatins the largest data in the image
 * @param[in] int maxval - contatins the smallest data in the image 
 *
 * @par Example:
   @verbatim

   grayscale(img, 255, 0);

   Output:
        grayscales the image
   @endverbatim
 *
 ******************************************************************************/
void grayscale ( image& img, int &minval, int&maxval )
{
    int grayscaleValue;
    minval = 255;
    maxval = 0;
    for (int i = 0; i < img.rows; ++i) 
    {
        for (int j = 0; j < img.cols; ++j) 
        {
            grayscaleValue = static_cast<int>(round((0.3 * img.redgray[i][j]) +
                (0.6 * img.green[i][j]) +
                (0.1 * img.blue[i][j])));
            img.redgray[i][j] = static_cast<pixel>(grayscaleValue);
            minval = min(minval, grayscaleValue);
            maxval = max(maxval, grayscaleValue);
        }
    }
}


/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function contrast and grayscales the image
 * @param[in] image img - contatins the data for the image
 *
 * @par Example:
   @verbatim

   contrast(img);

   Output:
        contrast the image as a grayscale the image
   @endverbatim
 *
 ******************************************************************************/
void contrast ( image& img )
{
    int minval, maxval;
    minval = 255;
    maxval = 0;
    grayscale(img, minval, maxval);
    double scale = 255.0 / (maxval - minval);
    for (int i = 0; i < img.rows; ++i) 
    {
        for (int j = 0; j < img.cols; ++j) 
        {
            int adjustedValue = static_cast<int>(round(scale * (img.redgray[i][j] - minval)));
            img.redgray[i][j] = adjustedValue;
        }
    }
}