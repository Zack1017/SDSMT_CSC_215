#include "sortedSingle.h"
#include <cstring>

sortedSingle::sortedSingle()
{
    node* headptr = nullptr;
}



sortedSingle::~sortedSingle()
{
    node* temp = headptr;
    node* next;
    while (temp != nullptr) {
        next = temp->next;
        delete temp;
        temp = next;
    }
    headptr = nullptr;
}



bool sortedSingle::find(int item)
{
    node* current = headptr;
    while (current != nullptr)
    {
        if (current->theItem == item)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}



int sortedSingle::retrievePosition(int item)
{
    node* current = headptr;
    int position = 1;
    while (current != nullptr)
    {
        if (current->theItem == item)
        {
            return position;
        }
        current = current->next;
        position++;
    }
    return 0;
}



int sortedSingle::size()
{
    node* current = headptr;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}



bool sortedSingle::empty()
{
    node* current = headptr;
    if (current == nullptr)
    {
        return 1;
    }
    return 0;
}