#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
struct empData
{
    int id;
    char firstName[20];
    char lastName[40];
    double salary;
    double bonus;
};


void printFile(fstream &fstr);


bool applyBonus(fstream& fstr,int id);


int main(int argc, char* argv[])
{
    fstream file; 
    if (argc != 3)//Check for command line
    {
        cout << "Usage: m0040.exe binaryData employeeID" << endl;
        return 0;
    }
    file.open(argv[1], ios::in | ios::out|ios::ate|ios::binary);//open input file 
    if (!file.is_open())//check input 
    {
        cout << "Unable to open binary file: " << argv[1] << endl;
        file.close();
        return 0;
    }

    printFile(file);
    cout << endl;
    int id1 = stoi(argv[2]);
    if (applyBonus(file, id1) == 1)
    {
        cout << "Employee ID " << stoi(argv[2]) << " has been updated." << endl;
    }
    else
    { 
        cout << "Employee ID " << stoi(argv[2]) << " was not found." << endl;
    }
    cout << endl;
    printFile(file);
    file.close();
    return 0; 
}
 


void printFile(fstream& file)
{
    file.clear();
    file.seekg(0, ios::beg);
    empData data;
    while (file.read( (char *) &data, sizeof(empData)))
    {
        cout << fixed << showpoint << setprecision(2)
            << setw(7) << data.id << " "
            << left << setw(20) << data.firstName
            << setw(40) << data.lastName << right
            << " Salary: " << setw(10) << data.salary
            << " Bonus: " << setw(10) << data.bonus << endl;
    }
    file.clear();
}



bool applyBonus(fstream& file, int id)
{
    empData data;
    int sizeofstruct = (int)sizeof(empData);
    double bon = 500;
    file.seekg(0, ios::beg);
    while (file.read((char*)&data, sizeof(empData)))
    {
        if (data.id == id)
        {
            data.bonus += 500;
            file.clear();
            file.seekp(-(sizeofstruct), ios::cur);
            file.write((char*)&data, sizeof(empData));
            return 1;
        }
    }
    return 0;
}