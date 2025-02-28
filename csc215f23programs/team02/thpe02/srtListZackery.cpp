/** *************************************************************************
 * @file
 ***************************************************************************/

#include "srtList.h"
/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Default constructor, this will create an empty list by initializing headptr.
 ******************************************************************************/
srtList::srtList()
{
    node* headptr = nullptr;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Destructor, this called when an object goes out of scope and will free all 
 * nodes within the linked list.
 ******************************************************************************/
srtList::~srtList()
{
    while (headptr != nullptr)
    {
        node* temp = headptr;
        headptr = headptr->next;
        delete temp;
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Prints the linked list out to the srt file out.  
 * 
 * @param[in,out] out - The stream to print the data to.
 *
 * @par Example:
   @verbatim
    seperator	The string that will be outputted between the data.
   @endverbatim
 *
 ******************************************************************************/
void srtList::print ( ostream &out ) const
{
    string temp;
    node* current = headptr;
    int frameNumber = 1;
    while ( current != nullptr )
    {
        if ( current -> theFrame.startTime == "" )
        {
            current = current->next;
        }
       out << frameNumber << endl;
        out << current -> theFrame.startTime << " --> " << current -> theFrame.endTime << endl;
        if ( current -> next == nullptr )
        {
            temp = current -> theFrame.caption;
            out << temp;
        }
        else
        {
            out << current -> theFrame.caption << "\n";
        }
        
        current = current -> next;
        frameNumber++;
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Inserts the request item into the linked list. The list is sorted an the 
 * item will be placed into the correct position in the list based off start time.
 *
 * @param aFrame - The data to be inserted.
 * @returns True if it succeeds, false if it fails.
 ******************************************************************************/
bool srtList::insert ( frame aFrame )
{
    node* newNode = new node;
    node* current = headptr;
    newNode -> theFrame = aFrame;
    newNode -> next = nullptr;
    while ( current != nullptr )
    {
        if ( ( aFrame.startTime >= current -> theFrame.startTime && 
            aFrame.startTime <= current -> theFrame.endTime ) ||
            ( aFrame.endTime >= current -> theFrame.startTime &&
            aFrame.endTime <= current -> theFrame.endTime ) ||
            ( aFrame.startTime <= current -> theFrame.startTime && 
            aFrame.endTime >= current -> theFrame.endTime ) )
        {
            return false;
        }
        current = current -> next;
    }
    current = headptr;
    if ( headptr == nullptr || aFrame.startTime < 
        headptr -> theFrame.startTime )
    {
        newNode -> next = headptr;
        headptr = newNode;
    }
    else
    {
        while ( current -> next != nullptr && aFrame.startTime > 
            current -> next->theFrame.startTime )
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return true;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Will remove the frame instance of the item from the linked list.
 *
 * @param frameNumber - The item to be removed from the list.
 * @returns True if it succeeds, false if it fails.
 ******************************************************************************/
bool srtList::remove ( int frameNumber )
{
    int count = 1;
    node* current = headptr;
    if ( headptr == nullptr )
    {
        return false;
    }
    if ( frameNumber == 1 )
    {
        node* temp = headptr;
        headptr = headptr -> next;
        delete temp;
        return true;
    }
    if ( frameNumber == 0 )
    {
        return false;
    }
    while ( count < frameNumber - 1 && 
        current -> next != nullptr )
    {
        current = current -> next;
        count++;
    }
    if ( current -> next == nullptr )
    {
        return false;
    }
    node* temp = current -> next;
    current -> next = current -> next->next;
    delete temp;
    return true;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Edits the request item into the linked list. The list is sorted an the
 * item will be placed into the correct position in the list based off start time.
 *
 * @param aFrame - The data to be updated.
 * @param frameNumber - The node to update.
 * @returns True if it succeeds, false if it fails.
 ******************************************************************************/
bool srtList::editList ( int frameNumber,frame aFrame )
{
    node* current = headptr;
    int currentFrameNumber = 1;

    while ( current != nullptr && currentFrameNumber < frameNumber ) 
    {
        current = current -> next;
        currentFrameNumber++;
    }
    if ( current == nullptr || currentFrameNumber > frameNumber ) 
    {
        return false;
    }
    current -> theFrame.startTime = aFrame.startTime;
    current -> theFrame.endTime = aFrame.endTime;
    current -> theFrame.caption = aFrame.caption;
    return true;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Edits the request time into the linked list. The list is sorted an the
 * item will be placed into the correct position in the list based off start time.
 *
 * @param aFrame - The time to be updated.
 * @param frameNumber - The node to update.
 * @returns True if it succeeds, false if it fails.
 ******************************************************************************/
bool srtList::editTime ( int frameNumber, frame aFrame )
{
    node* current = headptr;
    int currentFrameNumber = 1;
    while ( current != nullptr && currentFrameNumber < frameNumber ) 
    {
        current = current -> next;
        currentFrameNumber++;
    }
    if ( current == nullptr || currentFrameNumber > frameNumber ) 
    {
        return false;
    }
    current -> theFrame.startTime = aFrame.startTime;
    current -> theFrame.endTime = aFrame.endTime;
    return true;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Clears the SRT file 
 *
 * @returns True if it succeeds, false if it fails.
 ******************************************************************************/
bool srtList::clear ()
{
    node* current = headptr;
    while ( current != nullptr ) 
    {
        node* temp = current;
        current = current -> next;
        delete temp;
    }
    headptr = nullptr;
    return true;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Checks to find if the time is found in the srt.  
 *
 * @param time - The time to be found.
 * @returns True if it succeeds, false if it fails.
 ******************************************************************************/
bool srtList::findTime ( string time )
{
    node* current = headptr;
    while ( current != nullptr ) 
    {
        if ( current -> theFrame.startTime == time || 
            current -> theFrame.endTime == time) {
            return true;
        }
        current = current -> next;
    }
    return false;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * Checks to find if the caption is found in the srt.
 *
 * @param caption - The caption to be found.
 * @returns True if it succeeds, false if it fails.
 ******************************************************************************/
bool srtList::findCaption ( string caption )
{
    node* current = headptr;
    while ( current != nullptr ) 
    {
        if ( current -> theFrame.caption == caption ) 
        {
            return true;
        }
        current = current -> next;
    }
    return false;
}