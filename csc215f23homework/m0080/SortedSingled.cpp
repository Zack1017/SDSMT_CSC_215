/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"

sortedSingle::sortedSingle(sortedSingle& s)
{
    headptr = nullptr;

    if (s.headptr == nullptr)
    {
        return;
    }

    headptr = new node;
    headptr->theItem = s.headptr->theItem;
    headptr->next = nullptr;

    node* srcPrt = s.headptr->next;
    node* desPrt = headptr;

    while (srcPrt != nullptr)
    {
        node* newNode = new node;
        newNode->theItem = srcPrt->theItem;
        newNode->next = nullptr;

        desPrt->next = newNode;
    
        desPrt = newNode;
        srcPrt = srcPrt->next;
    }
}