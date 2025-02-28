#include "sortedSingle.h"

bool sortedSingle::remove(int item)
{
    node* current = headptr;
    node* temp = nullptr;
    while (current != nullptr && current->theItem != item)
    {
        temp = current;
        current = current->next;
    }
    if (current != nullptr)
    {
        if (temp != nullptr)
        {
            temp->next = current->next;
        }
        else
        {
            headptr = current->next;
        }
        delete current;
        return true;
    }
    return false;
}



void sortedSingle::clear()
{
    while (headptr != nullptr)
    {
        node* current = headptr;
        headptr = headptr->next;
        delete current;
    }
}
