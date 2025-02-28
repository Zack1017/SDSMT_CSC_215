/** *************************************************************************
* @file
****************************************************************************/

#include "srtList.h"

/** **********************************************************************
*  @author Maverick Bohm
*
*  @par Description
*  Inserts a time frame into a list of frames.
*
*  @param[in] aFrame the frame to be inserted
*
*  @returns A boolean result. true if the frame was inserted, false 
            otherwise.
*
*  @par Example
*  @verbatim
bool result;
frame aFrame
{
    string startTime = "00:20:32,307";
    string endTime = "00:22:21,102";
}

result = Cars2.insert( aFrame );//result would equal true if insert worked

@endverbatim
************************************************************************/
/*
bool srtList::insert( frame aFrame )
{
    bool exit = false;
    node* newNode = new ( nothrow ) node;
    node* currNode = headptr;
    node* prevNode = headptr;
    if( newNode == nullptr )
        return false;

    newNode->theFrame = aFrame;
    newNode->next = nullptr;

    if( headptr == nullptr )//Empty
    {
        headptr = newNode;
        return true;
    }


    if( currNode->theFrame.startTime > newNode->theFrame.endTime )//Front
    {
        newNode->next = headptr;
        headptr = newNode;
        return true;
    }

    while( currNode != nullptr && exit == false )//Middle
    {
        if( currNode->theFrame.startTime > newNode->theFrame.endTime )
        {
            if( newNode->theFrame.startTime < prevNode->theFrame.endTime )
            {
                delete newNode;
                return false;
            }
            exit = true;
            newNode->next = currNode;
            prevNode->next = newNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
        if( exit == true )
            return true;
    }

    if( newNode->theFrame.startTime < prevNode->theFrame.endTime )//End
        prevNode->next = newNode;
        return true;

    return false;
}*/
