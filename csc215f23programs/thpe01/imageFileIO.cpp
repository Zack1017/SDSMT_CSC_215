/** *************************************************************************
 * @file
 ***************************************************************************/
#include "netPBM.h" 

/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function reads the header of the image file and send it 
 * to ascii or binary
 * @param[in]  argv[] - contains the argument 
 * @param[in] image img - contatins the data for the image
 * @param[in] int num - contains the number of arguments
 *
 * @par Example:
   @verbatim

   readHeader(--ascii img, 4);

   Output:
        reads header info into the img struc and then sends it the the 
        correct read function
   @endverbatim
 *
 ******************************************************************************/
void readHeader ( char* argv[], image& img, int num )
{
    ifstream file;
    string comments;
    int maxValue;
    if(num == 4)
    { 
        file.open(argv[3], ios::binary | ios::in);
        if (!file.is_open())
        {
            usage(3,argv[3]);
            file.close();
        }
    }
    if (num == 5)
    {
        file.open(argv[4], ios::binary | ios::in);
        if (!file.is_open())
        {
            usage(3, argv[4]);
            file.close();
        }
    }
    if (num == 6)
    {
        file.open(argv[5], ios::binary | ios::in);
        if (!file.is_open())
        {
            usage(3, argv[5]);
            file.close();
        }
    }

    file >> img.magicNumber;
    if (img.magicNumber == "P3")
    {
        file.ignore();
        while (file.peek() == '#')
        {
            getline(file, comments, '\n');
            img.comment = img.comment + comments;
        }

        file >> img.cols >> img.rows >> maxValue;
        readPPMFileAscii(file, img);
        file.close();
    }
    else if (img.magicNumber == "P6")
    {
        file.ignore();
        //file.ignore();
        while (file.peek() == '#')
        {
            getline(file, comments, '\n');
            img.comment = img.comment + comments;
        }

        file >> img.cols >> img.rows >> maxValue;
        file.ignore();
        readPPMFileBinary(file, img);
        file.close();
    } 
    else
    {
        usage(4, "nouse");
        file.close();
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function reads image data into 3 2D arrays
 * to ascii or binary
 * @param[in]  file - contains the input file steam
 * @param[in] image img - contatins the data for the image
 *
 * @par Example:
   @verbatim

   readPPMFileAscii(file, img);

   Output:
        reads file infomation into the img from ascii data 
   @endverbatim
 *
 ******************************************************************************/
void readPPMFileAscii ( ifstream& file, image& img )
{
    int i, j;
    int red, blue, green;
    alloc2d(img.rows, img.cols, img);
    for (i = 0; i < img.rows; i++)
    {
        
        for (j = 0; j < img.cols; j++)
        {
            file >> red >> green >> blue;
            img.redgray[i][j] = red;
            img.green[i][j] = green;
            img.blue[i][j] = blue;
        }
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function reads image data into 3 2D arrays
 * to ascii or binary
 * @param[in]  file - contains the input file steam
 * @param[in] image img - contatins the data for the image
 *
 * @par Example:
   @verbatim

   readPPMFileBinary(file, img);

   Output:
        reads file infomation into the img from binary data
   @endverbatim
 *
 ******************************************************************************/
void readPPMFileBinary ( ifstream& file, image& img )
{
    int i, j;
    cout << img.cols << '\n';
    alloc2d(img.rows, img.cols, img);
    for (i = 0; i < img.rows; ++i)
    {
        for (j = 0; j < img.cols; )
        {
            file.read( (char*)(&img.redgray[i][j]), 1);
            file.read( (char*)(&img.green[i][j]), 1);
            file.read( (char*)(&img.blue[i][j]), 1);
            ++j;
            //cout << img.redgray[i][j] - 1 << endl;
            //cout << j << '\n';
        }
        i = img.rows;
        //cout << i<<'\n';
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 *  * This function writes image data out in ascii form and choses the new
 * magic number.  This data is also printed based on correct data type.
 * to ascii or binary
 * @param[in] string file - contains the output file name
 * @param[in] image img - contatins the data for the image
 * @param[in] int rows - contatins the number of rows
 * @param[in] int cols - contatins the number of cols
 * @param[in] argv - contatins the commands line arguments
 * 
 *
 * @par Example:
   @verbatim

   writePPMFileAscii(file, img, 10, 10, argv);

   Output:
        writes the image out in ascii
   @endverbatim
 *
 ******************************************************************************/
void writePPMFileAscii ( string filename, image img, int rows, int cols, char* argv )
{
    ofstream file;
    string processedComment;
    size_t location;
    int i, j;

    if ((strcmp(argv, "--grayscale") == 0) || (strcmp(argv, "--contrast") == 0))
    {
        file.open(filename + ".pgm", ios::binary | ios::out);
        if (!file.is_open())
        {
            usage(3, filename + ".pgm");
            file.close();
        }
    }
    else
    {
        file.open(filename + ".ppm", ios::binary | ios::out);
        if (!file.is_open())
        {
            usage(3, filename + ".ppm");
            file.close();
        }
    }



    if ((strcmp(argv, "--grayscale") == 0) || (strcmp(argv, "--contrast") == 0))
    {
        img.magicNumber = "P2";
        file << img.magicNumber << '\n';
        processedComment = img.comment;
        location = processedComment.find("#");
        while (location != string::npos)
        {
            location = processedComment.find("#", location + 2);
            if (location != -1)
            {
                processedComment.insert(location, "\n");
            }
        }
        img.comment = processedComment;
        file << img.comment << '\n';
        file << img.cols << " " << img.rows << '\n';
        file << "255" << '\n';
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                file << img.redgray[i][j] - 0 << '\n';
            }
        }
        file.close();
    }


    else
    { 
        img.magicNumber = "P3";
        file << img.magicNumber << '\n';
        processedComment = img.comment;
        location = processedComment.find("#");
        while (location != string::npos)
        {
            location = processedComment.find("#", location + 2);
            if (location != -1)
            {
                processedComment.insert(location, "\n");
            }
        }
        img.comment = processedComment;
        file << img.comment << '\n';
        file << img.cols << " " << img.rows << '\n';
        file << "255" << '\n';

        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                file << img.redgray[i][j]-0 << " " << img.green[i][j]-0 << " " << img.blue[i][j]-0 << '\n';
            }
        }
        file.close();
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function writes image data out in binary form and choses the new
 * magic number.  This data is also printed based on correct data type.
 * to ascii or binary
 * @param[in] string file - contains the output file name
 * @param[in] image img - contatins the data for the image
 * @param[in] int rows - contatins the number of rows
 * @param[in] int cols - contatins the number of cols
 * @param[in] argv - contatins the commands line arguments
 *
 *
 * @par Example:
   @verbatim

   writePPMFileBinary(file, img, 10, 10, argv);

   Output:
        writes the image out in binary
   @endverbatim
 *
 ******************************************************************************/
void writePPMFileBinary ( string filename, image img, int rows, int cols, char* argv )
{
    ofstream file;
    string processedComment;
    size_t location;
    int i, j;
    if ((strcmp(argv, "--grayscale") == 0) || (strcmp(argv, "--contrast") == 0))
    {
        file.open(filename + ".pgm", ios::binary | ios::out);
        if (!file.is_open())
        {
            usage(3, filename + ".pgm");
            file.close();
        }
    }
    else
    {
        file.open(filename + ".ppm", ios::binary | ios::out);
        if (!file.is_open())
        {
            usage(3, filename + ".ppm");
            file.close();
        }
    }
    

    if ((strcmp(argv, "--grayscale") == 0)|| (strcmp(argv, "--contrast") == 0))
    {
        img.magicNumber = "P5";
        file << img.magicNumber << '\n';
        processedComment = img.comment;
        location = processedComment.find("#");
        while (location != string::npos)
        {
            location = processedComment.find("#", location + 2);
            if (location != -1)
            {
                processedComment.insert(location, "\n");
            }
        }
        img.comment = processedComment;

        file << img.comment << '\n';
        file << img.cols << " " << img.rows << '\n';
        file << "255" << '\n';

        for (i = 0; i < img.rows; ++i)
        {
            for (j = 0; j < img.cols; ++j)
            {
                file.write((char*)&img.redgray[i][j], sizeof(pixel));
            }
        }
        file.close();
    }

    else
    {
        img.magicNumber = "P6";
        file << img.magicNumber << '\n';
        processedComment = img.comment;
        location = processedComment.find("#");
        while (location != string::npos)
        {
            location = processedComment.find("#", location + 2);
            if (location != -1)
            {
                processedComment.insert(location, "\n");
            }
        }
        img.comment = processedComment;

        file << img.comment << '\n';
        file << img.cols << " " << img.rows << '\n';
        file << "255" << '\n';

        for (i = 0; i < img.rows; ++i)
        {
            for (j = 0; j < img.cols; ++j)
            {
                file.write((char*)&img.redgray[i][j], sizeof(pixel));
                file.write((char*)&img.green[i][j], sizeof(pixel));
                file.write((char*)&img.blue[i][j], sizeof(pixel));
                //cout << img.redgray[i][j] -0 << " " << img.green[i][j] -0<< " " << img.blue[i][j] -0<< endl;
            }
        }
        file.close();
    }
}