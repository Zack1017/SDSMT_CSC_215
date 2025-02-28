#include "thpe02.h"
/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function reads in the data an srt file and then addes it into the linked 
 * list.
 *
 * @param in - Input stream from which subtitle data is read.
 * @param data - Reference to the srtList object to store the extracted subtitle 
 data.
 ******************************************************************************/
void readSrt ( istream& in, srtList &data )
{ 
    string line;
    frame aFrame;
    string time;
    string caption;
    size_t space;
    string temp;
    string junk;
    in.ignore();
    while ( getline ( in, line ) )
    { 
        while ( getline ( in, time ) )
        {
            //getline(in, time);
            space = time.find ( ' ' );
            aFrame.startTime = time.substr ( 0, space );
            space = time.rfind ( ' ' );
            aFrame.endTime = time.substr ( space + 1, time.size () );
            aFrame.caption = "";
            while ( getline ( in, line ) && !line.empty () )
            {
                aFrame.caption += line + "\n";
            }
            in.ignore ();
            getline ( in, junk );
            if ( data.insert ( aFrame ) == 0 )
            {
                cout << "Unable to insert frame:" << endl;
                cout << aFrame.startTime << " --> " << aFrame.endTime << endl;
                temp = aFrame.caption;
                space = temp.rfind ( '\n' );
                temp = temp.substr ( 0, space );
                cout << temp << endl;
            }
        }
    }
    //data.insert(aFrame);
}