#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

float* findMinimum(float* ptr, int size);
float* findMaximum(float* ptr, int size);

int main(int argc, char* argv[])
{
    ifstream fin;
    ofstream fout;
    int i = 0;
    int j = 0;
    int dataSize;
    float* iptr = nullptr;

    if (argc != 3)//Check for command line
    {
        cout << "Usage: m0020.exe inputfile outputfile" << endl;
        return 0;
    }
    fin.open(argv[1]);//open input file 
    if (!fin.is_open())//check input 
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        fin.close();
        fout.close();
        return 0;
    }
    fout.open(argv[2]);//open output file
    if (!fout.is_open())//check output
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        fin.close();
        fout.close();
        return 0;

    }
    fin >> dataSize;//gets data size 
    iptr = new (nothrow) float[dataSize];//create point from size 
    if (iptr == nullptr)//checks for memory error
    {
        cout << "Unable to allocate memory" << endl;
        delete[] iptr;
        return 0;
    }
    while (j < dataSize && fin >> iptr[j])//reads data in 
    {
        j++;
    }
    fout << j << endl;
    fout << fixed << setprecision(3);
    fout << *findMinimum(iptr, j) << " - " << *findMaximum(iptr, j) << endl;
    fout << right;
    for (i = 0; i < j; i++)
    {
        fout << setw(15) << iptr[i];
        if ((i + 1) % 5 == 0)
        {
            fout << endl;
        }
    } 
    if ((i % 5) != 0)
    {
        fout << endl;
    }

    delete[]iptr;
    fin.close();
    fout.close();
    return 0;
}

float* findMinimum(float* ptr, int size)
{
    int i;
    float* search = &ptr[0];
    for (i = 1; i < size; i++)
    {
        if (ptr[i] < *search)
        {
            search = &ptr[i];
        }
    }
    return search;
}

float* findMaximum(float* ptr, int size)
{
    int i;
    float* search = &ptr[0];
    for (i = 1; i < size; i++)
    {
        if (ptr[i] > *search)
        {
            search = &ptr[i];
        }
    }
    return search;
}