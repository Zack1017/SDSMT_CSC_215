#include "sortedSingle.h"


bool sortedSingle::insert(int item)
{
    node* newNode;
    newNode = new node{ item };
    if (headptr == nullptr || item < headptr -> theItem)
    {
        newNode -> next = headptr;
        headptr = newNode;
    }
    else
    {
        node* current = headptr;
        while (current -> next != nullptr && item > current -> next -> theItem)
        {
            current = current -> next;
        }
        newNode -> next = current->next;
        current->next = newNode;
    }

    return 1;
}



void sortedSingle::print(ostream& out, string seperator)
{
    node* current = headptr;
    while (current != nullptr)
    {
        out << current->theItem;
        if (current->next != nullptr)
        {
            out << seperator;
        }
        current = current->next;
    }
}