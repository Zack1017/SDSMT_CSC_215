#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <vector>
#include <sstream>

using namespace std;



enum trait { POTENCY, ESSENCE, ASPECT };//Enum given in assignment 


struct rune
{
    string name;//Given in assignment 
    trait type;//Given in assignment 
};

void errorTesting ( ifstream& file, int num, char* argv );//check arguments 
int read ( ifstream& file, vector<rune>& data );//function to read 
void permuteRunes ( vector<rune>& data, vector<rune>& perm, vector<int>& used, int pos, int length );//Perm Function 



int main ( int argc, char* argv[] )
{
    ifstream file;
    vector<int> used;
    vector<rune> data;
    vector<rune> perm;
    size_t length;

    errorTesting ( file, argc, argv [ 1 ] );
    length = read ( file, data );
    file.close( );
    used.resize ( length );
    perm.resize ( 3 );
    permuteRunes ( data, perm, used, 0 , (int)length );
    
    return 0;
}



void errorTesting ( ifstream& file, int argc, char* argv )
{
    if ( argc != 2 )
    {
        cout << "m0100.exe csvdatafile" << endl;
        exit ( 0 );
    }
    file.open ( argv );
    if ( !file.is_open ( ) )
    {
        cout << "Unable to open: " << argv << endl;
        exit ( 0 );
    }
}

//getline(instrFile, fullTime);
//space = fullTime.find(' ');
//f.startTime = fullTime.substr(0, space);

int read ( ifstream& file, vector<rune>& data )
{
    string line,traitStr,runeName;
    getline ( file, line );
    int size,space;

    while ( getline ( file, line ) ) 
    {
        space = ( int ) line.find ( ',' );
        runeName = line.substr ( 0, space );
        traitStr = line.substr ( space + 1, line.size ( ) );

        trait type;
        if ( traitStr == "Potency" ) 
        {
            type = POTENCY;
        }
        else if ( traitStr == "Essence" ) 
        {
            type = ESSENCE;
        }
        else 
        {
            type = ASPECT;
        }

        data.push_back ( { runeName, type } );
    }
    size = ( int ) data.size ( );
    return size;
}



void permuteRunes ( vector<rune>& data, vector<rune>& perm, vector<int>& used, int pos, int length )
{
    int i;
    if ( pos == 3 )
    {
        for ( i = 0; i < 3; i++ )
        {
            if ( i != 2 )
            {
                cout << perm [ i ] .name << " ";
            }
            else
            {
                cout << perm [ i ] .name;
            }
        }
        cout << endl;
        return;
    }
    else
    {
        for ( i = 0; i < length; i++ )
        {
            if ( used [ i ] == 0 && data [ i ] .type == pos)
            {
                perm [ pos ] = data [ i ];
                used [ i ] = 1;
                permuteRunes ( data, perm, used, pos + 1, length );
                used [ i ] = 0;
            }
        }
    }
}