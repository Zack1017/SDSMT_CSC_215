#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include<iterator>
#include <algorithm>    // std::sort c++.org

using namespace std;

struct empData
{
    int id;
    string firstName;
    string lastName;
    double salary;
    double bonus;
};



bool compareId(empData& left, empData& right);



bool compareSalary(empData& left, empData& right);



bool compareNames(empData& left, empData& right);



void print(string titles, vector<empData>& data, ofstream& fout);



void process ( string titles, ifstream& fin, vector<empData>& data, ofstream& fout );



int main ( int argc, char* argv[] )
{
    ifstream fin;
    ofstream fout; 
    vector<string> sort;
    vector<empData> emp;
    empData data;
    string titles;


    if ( argc != 4 )//Check for command line
    {
        cout << "Usage: m0050.exe inputCSVFile outputCSVFile sortMethod" << endl;
        return 0;
    }


    fin.open ( argv [ 1 ] );//open input file 
    if ( !fin.is_open() )//check input 
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        fin.close();
        fout.close();
        return 0;
    }


    fout.open ( argv [ 2 ] ) ;//open input file 
    if ( !fout.is_open() )//check input 
    {
        cout << "Unable to open output file: " << argv [ 2 ] << endl;
        fin.close();
        fout.close();
        return 0;
    }


    if ( ( strcmp ( argv [ 3 ] , "-i") == 0) || 
         ( strcmp ( argv [ 3 ] , "-n") == 0) || 
         ( strcmp ( argv [ 3 ] , "-s" ) == 0 ) )
    {
        process ( titles, fin, emp, fout );


        if ( ( strcmp ( argv [ 3 ] , "-i" ) == 0 ) )
        {
            std::sort ( emp.begin(), emp.end(), compareId );
        }
        else if ( ( strcmp ( argv [ 3 ] , "-s") == 0) )
        {
            std::sort ( emp.begin(), emp.end(), compareSalary );
        }
        else if ( ( strcmp ( argv [ 3 ] , "-n" ) == 0 ) )
        {
            std::sort ( emp.begin(), emp.end(), compareNames );
        }


        print ( titles, emp, fout );


        fin.close();
        fout.close();


        return 0;
    }


    else
    {
        cout << "Invalid Sort Method:" << endl << "-i - sort by id" << endl
            << "-n - sort by name" << endl << "-s - sort by salary" << endl;
        return 0;
    }


    return 0;
}



bool compareId ( empData& left, empData& right )
{
    return left.id < right.id;
}



bool compareSalary ( empData& left, empData& right )
{
    return left.salary > right.salary;
}



bool compareNames ( empData& left, empData& right ) 
{
    if ( left.lastName == right.lastName ) 
    {
        return left.firstName < right.firstName;
    }
    return left.lastName < right.lastName;
}



void print ( string titles, vector<empData>& data, ofstream& fout )
{
    for ( empData& data : data )//C++.org
    {
        fout << fixed << showpoint << setprecision ( 2 )
            << data.id << "," << data.firstName << ","
            << data.lastName << "," << data.salary << ","
            << data.bonus << "\n";
    }
}



void process ( string titles, ifstream& fin, 
    vector<empData>& info, ofstream& fout )
{
    empData data;
    getline ( fin, titles );
    while ( fin >> data.id )
    {
        fin.ignore();
        getline ( fin, data.firstName, ',' );
        getline ( fin, data.lastName, ',' );
        fin >> data.salary;
        fin.ignore();
        fin >> data.bonus;
        info.push_back ( data );
    }
    fout << titles << "\n";
}