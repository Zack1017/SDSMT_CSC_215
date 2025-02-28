/** ***************************************************************************
 * @file
 *
 * @brief A program that creates a srtfile based on either an instructional 
 * file and/or an addional srt file
 *****************************************************************************/
 /** ***************************************************************************
   * @mainpage THPE02 - The SRT Editor
   *
   * @section M01
   *
   * @authors Zackery Holloway
   * @authors Maverick Bohm
   * @authors Benjamin Shklyar
   *
   * @date Novermber 3, 2023
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
   * @details The user wishes to be able to edit srt files.  They are 
   * a simple form of movie subtiles.  The program must preform operations
   * like create, edit, destory and print frames.  
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
    C:\>thpe02.exe instructionFile srtFile
            instructionFile - a list of modifications to be done to the srt list"
            srtFile - valid srt captions to be loaded if the file exists"
    }
     @endverbatim
   *
   * @section todo_bugs_modification_section Todo, Bugs, and Modifications
   *
   * @bug Issue with the editTime function where it does not always validate 
   * that the time is in the correct position.
   * @bug [Needs to be updated]
   *
   * @par Modifications and Development Timeline:
   *     <a href="https://gitlab.cse.sdsmt.edu/csc215/fall2023/team02/-/graphs/main?ref_type=heads" target=_blank>
   *     Gitlab Commit Log</a>
   *
   *****************************************************************************/
#include "thpe02.h"

   /** ***************************************************************************
    * @author Zackery Holloway
    *
    * @par Description
    * This is the starting point to the program. Based on command line arguments
    * it will process the instructional file or existing srt.  This will run
    * the opperation to make the needed changes to the SRTfile. If the
    * options provied are not correct it will exit with error code.
    *
    * @param[in] argc - the number of arguments from the command prompt.
    * @param[in] argv - the opperation commands
    *
    * @returns 0 system success
    *
    * *****************************************************************************/
int main ( int argc, char** argv )
{
    ifstream instruction;
    ifstream srtExisting;
    srtList data;
    if ( argc == 2 )
    {
        instruction.open ( argv [ 1 ] );
        readInstructions ( instruction, data );
        if ( !instruction.is_open ( ) )
        {
            cout << "Unable to open the file: " << argv [ 1 ] << endl;
            exit ( 0 );
        }
    }
    else if ( argc == 3 )
    {
        instruction.open ( argv [ 1 ] );
        if ( !instruction.is_open ( ) )
        {
            cout << "Unable to open the file: " << argv [ 1 ] << endl;
            exit ( 0 );
        }
        srtExisting.open ( argv [ 2 ] );
        if ( !srtExisting.is_open ( ) )
        {
            cout << "Unable to open the file: " << argv [ 2 ] << endl;
            instruction.close();
            exit ( 0 );
        }
        readSRT ( srtExisting, data ); 
        //readSrt(srtExisting, data);
        readInstructions ( instruction, data );
    }
    else
    {
        cout << "Usage: thpe02.exe instructionFile srtFile" << endl
            << "       instructionFile - a list of modifications "
            << "to be done to the srt list" << endl
            << "       srtFile - valid srt captions to be loaded if the file exists" << endl;;
    }
    return 0;
}