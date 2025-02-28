/** **************************************************************************
 * @file
 *
 * @brief   The declaration of the srtList list for a list that
 *          is sorted based on time.
 ****************************************************************************/
#ifndef __SRTLIST__H__
#define __SRTLIST__H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
/** ************************************************************************** 
 * @struct frame 
 * @brief Struct representing a subtitle frame with start time, end time, and caption.
 * 
 ****************************************************************************/
struct frame
{
    string startTime; /**<The start time of the frame*/
    string endTime;   /**<The end time of the frame*/
    string caption;   /**<The caption of the frame*/
};
/** **************************************************************************
 * @class   srtLust
 *
 * @brief   A sorted singly linked list of strings.
 ****************************************************************************/

class srtList
{
    public:
        srtList();
        ~srtList();

        bool insert(frame aFrame);
        //bool compareTime(string sTime, string eTime);
        bool remove(int frameNumber);

        void print(ostream& out) const;

        bool editList(int frameNumber, frame aFrame);
        bool editTime(int frameNumber, frame aFrame);
        bool clear( );

        bool findTime(string time);
        bool findCaption(string caption);



        // your functionality goes here 

    private:
        /**
        * @brief  the storage container for each item in the list
         */
        struct node
        {
            frame theFrame; /**<The Data held in the linked list*/
            node* next; /**<The next node in the list*/
        };
        node* headptr; /**<The node for the first item */
};
#endif 