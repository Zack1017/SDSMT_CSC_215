/** *************************************************************************
 * @file
 ***************************************************************************/
#include "netPBM.h" 
/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function allocates needed memory and checks to make sure it is valid
 *
 * @param[in] int rows - the number of rows
 * @param[in] int cols - the number of cols
 * @param[in] image img - the image data 
 *
 * @par Example:
   @verbatim

   alloc2d( 10,10, img );

   Output:
   allocated memmory to the arrays 
   @endverbatim
 *
 ******************************************************************************/
void alloc2d ( int rows, int cols, image& img )
{
    int i;
    img.redgray = nullptr;
    img.green = nullptr;
    img.blue = nullptr;

    // allocate row number of pointers for the 2d array
    img.redgray = new (nothrow) pixel * [rows];
    img.green = new (nothrow) pixel * [rows];
    img.blue = new (nothrow) pixel * [rows];
    // check for success
    if (img.redgray == nullptr)
    {
        usage(5, "nouse");
    }
    if (img.green == nullptr)
    {
        usage(5, "nouse");
    }
    if (img.blue == nullptr)
    {
        usage(5, "nouse");
    }

    // allocate the storage for every row all in consecutive memory
    for (i = 0; i < rows; i++)
    {
        img.redgray[i] = new(nothrow) pixel[cols];
        img.green[i] = new(nothrow) pixel[cols];
        img.blue[i] = new(nothrow) pixel[cols];
    }
    if (img.redgray[0] == nullptr)
    {
        delete[] img.redgray;
        usage(5, "nouse");
    }
    if (img.green[0] == nullptr)
    {
        delete[] img.redgray;
        usage(5, "nouse");
    }
    if (img.blue[0] == nullptr)
    {
        delete[] img.redgray;
        usage(5, "nouse");
    }
}


/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function de-allocates memory and checks to make sure it is valid
 *
 * @param[in] image img - the image data
 * @param[in] int rows - the number of rows
 *
 * @par Example:
   @verbatim

   free2d( img, 10 );

   Output:
   frees the memmory
   @endverbatim
 *
 ******************************************************************************/
void free2d ( image img, int rows )
{
    // make sure pointer has an address
    if (img.redgray == nullptr)
        return;

    // free up the storage in each row within the 2d array
    delete[] img.redgray[0];

    // delete the array of pointers for the row.
    delete[] img.redgray;

    img.redgray = nullptr;

    // make sure pointer has an address
    if (img.green == nullptr)
        return;

    // free up the storage in each row within the 2d array
    delete[] img.green[0];

    // delete the array of pointers for the row.
    delete[] img.green;

    img.green = nullptr;

    // make sure pointer has an address
    if (img.blue == nullptr)
        return;

    // free up the storage in each row within the 2d array
    delete[] img.blue[0];

    // delete the array of pointers for the row.
    delete[] img.blue;

    img.blue = nullptr;
}


/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function allocates needed memory and checks to make sure it is valid 
 * for opperators obly 
 *
 * @param[in] ptr - the pointer to allocate 
 * @param[in] int rows - the number of rows
 * @param[in] int cols - the number of cols
 *
 * @par Example:
   @verbatim

   allocate2dOper( ptr, 10,10 );

   Output:
   allocated memmory to the arrays
   @endverbatim
 *
 ******************************************************************************/
void allocate2dOper ( int**& ptr, int rows, int  cols )
{
    int i;
    ptr = nullptr;
    ptr = new (nothrow) int* [rows];
    if (ptr == nullptr)
    {
        usage(5, "nouse");
    }
    for (i = 0; i < rows; i++)
    {
        ptr[i] = new(nothrow) int[cols];
    }
    if (ptr[0] == nullptr)
    {
        delete[] ptr;
        usage(5, "nouse");
    }

}