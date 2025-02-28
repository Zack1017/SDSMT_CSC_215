#include "thpe02.h"


void readInstructions(ifstream& instrFile, srtList& data) {

    string line;
    frame f;
    string fullTime;
    string startTime;
    string endTime;
    string temp;
    size_t space;
    while (getline(instrFile, line)) 
    {
        
        if (line.find("--add") != string::npos) 
        {
            getline(instrFile, fullTime);
            space = fullTime.find(' ');
            f.startTime = fullTime.substr(0, space);
            space = fullTime.rfind(' ');
            f.endTime = fullTime.substr(space+1, fullTime.size());
            f.caption = "";
            string caption;
            while (getline(instrFile, line) && !line.empty()) {
                f.caption += line + "\n";
            }
            if (data.insert(f) == 0)
            {
                cout << "Unable to insert frame:" << endl;
                cout << f.startTime << " --> " << f.endTime << endl;
                temp = f.caption;
                space = temp.rfind('\n');
                temp = temp.substr(0, space);
                cout << temp << endl;
            }
        }
        else if (line.find("--editCap") == 0)
        {
            string caption;
            int frameNum;
            getline(instrFile, line); // frame number
            frameNum = stoi(line);
            f.caption = "";

            while (getline(instrFile, line) && !line.empty()) {
                f.caption += line + "\n";
            }
            if (data.editList(frameNum, f) == 0)
            {
                cout << "Unable to edit frame:" << endl;
            }
        }
        else if (line.find("--editTime") == 0)
        {
            string caption;
            int frameNum;
            getline(instrFile, line); // frame numbe 
            frameNum = stoi(line);

            getline(instrFile, fullTime);
            space = fullTime.find(' ');
            f.startTime = fullTime.substr(0, space); 
            space = fullTime.rfind(' '); 
            f.endTime = fullTime.substr(space + 1, fullTime.size()); 

            if (data.editList(frameNum, f) == 0)
            {
                cout << "Unable to edit frame:" << endl;
            }
        }
        else if (line.find("--remove") == 0) {

            getline(instrFile, line); // frame number
            int frameNum = stoi(line);

            if (data.remove(frameNum) == 0)
            {
                cout << "Unable to remove frame number: " << frameNum << endl;
            }

        }
        else if (line.find("--print") == 0) {

            getline(instrFile, line); // output file name
            string outFile = line;
            ofstream out;
            out.open(outFile);
            if (out.is_open() != 1)
            {
                cout << "Unable to open the file: " <<line << endl;
            }
            else
            {
                data.print(out);
            }

            out.close();
        }
    }
}

void readSRT(ifstream& srtFile, srtList& data)
{
    frame f;
    string line;
    string time;
    string fullTime;
    string startTime;
    string caption;
    string endTime;
    string temp;
    string junk;
    size_t space;
    while (getline(srtFile, line))
    {

        while(getline(srtFile, fullTime))
        {
            //getline(srtFile, fullTime);
            space = fullTime.find(' ');
            f.startTime = fullTime.substr(0, space);
            space = fullTime.rfind(' ');
            f.endTime = fullTime.substr(space + 1, fullTime.size());
            f.caption = "";
            while (getline(srtFile, line) && !line.empty())
            {
                f.caption += line + "\n";
            }
            srtFile.ignore();
            getline(srtFile, junk);
            if (data.insert(f) == 0)
            {
                cout << "Unable to insert frame:" << endl;
                cout << f.startTime << " --> " << f.endTime << endl;
                temp = f.caption;
                space = temp.rfind('\n');
                temp = temp.substr(0, space);
                cout << temp << endl;
            }
        }
    }
}

string getCaption(ifstream& file)
{
    string line, caption;
    while (getline(file, line))
    {
        if (line.empty())
        {
            break;
        }
        caption += line + "\n";
    }
    return caption;
}
