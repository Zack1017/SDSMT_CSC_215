/** **********************************************************************
* @file
************************************************************************/
#ifndef __THPE02__H__
#define __THPE02__H__
//other includes 
#include "srtList.h"
#include "sstream"

//function not part of srtList
void readInstructions(ifstream& instrFile, srtList& data);
void readSRT(ifstream& srtFile, srtList& data);
void readSrt(istream& in, srtList& data);
string getCaption(ifstream& file);
#endif