#include "trim.h"
#include "..\\catch_amalgamated.hpp"

void cTrim ( char cString[], trimType area )
{
    char* ptr = nullptr; 
    ptr = cString;
    if ( cString != nullptr )
    {
        if ( area == BOTH || area == FRONT  )
        {
            while ( isspace( *ptr ) )
            {
                ptr++;
            }
            strcpy ( cString, ptr );
        }
        if ( area == END || area == BOTH )
        {
            ptr = cString;
            ptr += strlen( cString ) - 1;

            while ( isspace ( *ptr ) )
            {
                *ptr = '\0';
                ptr--;
            }
        }
    }
}



void sTrim ( string &sString, trimType area )
{
    string::iterator iter;
    int bye = 0; 

    if ( area == FRONT || area== BOTH )
    {
        iter = sString.begin();
        while ( iter != sString.end() && isspace ( *iter ) )
        {
            iter++;
            bye++;
        }
        sString.erase( 0, bye );
    }
    if ( area == END || area == BOTH )
    {
        iter = sString.end();
        while ( iter != sString.begin() && isspace ( * ( iter -1 ) ) )
        {
            iter--;
        }
        sString.erase ( iter, sString.end() );
    }
}