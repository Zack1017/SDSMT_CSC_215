/** ***************************************************************************
 * @file
 *
 * @brief A program that finds the fast way to the end of the maze.  
 *****************************************************************************/
 /** ***************************************************************************
    * @mainpage THPE23 - Maze Solver
    *
    * @section M01
    *
    * @authors Zackery Holloway
    *
    * @date December 3, 2023
    *
    * @par Instructor
    *         Professor Roger Schrader
    *
    * @par Course
    *         CSC 215  - Section M01 - 9:00 am
    *
    * @par Location
    *         McLaury - Room 207
    *
    * @section program_section Program Information
    *
    * @details The user wishes to be able find the end of the maze.  They need
    * to find the shortest solution to the end.  They have no supplies and are low
    * on hunger. 
    *
    * Because of space, the rest of the details have been omitted.
    *
    * @section compile_section Compiling and Usage
    *
    * @par Compiling Instructions:
    *      None
    *
    * @par Usage
      @verbatim
     C:\>thpe23.exe inputMaze outputMaze
             inputMaze - a file containg one or more mazes to solve"
             outputMaze - a file that contains the solution to all the mazes"
     }
      @endverbatim
    *
    * @section todo_bugs_modification_section Todo, Bugs, and Modifications
    *
    * @par Modifications and Development Timeline:
    *     <a href="https://gitlab.cse.sdsmt.edu/101113328/csc215f23programs/-/graphs/main?ref_type=heads" target=_blank>
    *     Gitlab Commit Log</a>
    *
    *****************************************************************************/
#include <iostream>
#include<fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

/** **************************************************************************
 * @struct mazeSolve
 * @brief Struct representing a subtitle frame with start time, end time, and caption.
 *
 ****************************************************************************/
struct mazeSolve
{
    char** shortestMaze; /**<The array that holds the shortest path*/
    int steps; /**<The shortest number of steps*/
    int cols; /**<The number of cols in the maze*/
    int rows; /**<The number of rows in the maze*/
    int startRow; /**<The start position of the maze in rows*/
    int startCol; /**<The start position of the maze in cols*/
};

char** allocateMaze(int rows, int cols);
void deleteMaze(char** maze, int rows);
void printMaze(char** maze, ofstream& out, int rows, int cols, int count, mazeSolve mazeInfo);
void process(ifstream& in, ofstream& out);
bool solveMaze(char** &maze, int rows, int cols, int currentRow, int currentCol, int&steps, mazeSolve &mazeInfo);


/** ***************************************************************************
    * @author Zackery Holloway
    *
    * @par Description
    * This is the starting point to the program. Based on command line arguments
    * it will validate the arguments.  After completing it will call the function 
    * to process the maze.  If the options provied are not correct it will 
    * exit with error code.
    *
    * @param[in] argc - the number of arguments from the command prompt.
    * @param[in] argv - the opperation commands
    *
    * @returns 0 system success
    ** @par Example:
    @verbatim

        main( 2 ,argv );

        Output:
        Return 0 if successful 
    @endverbatim
    *
    * *****************************************************************************/
int main ( int argc, char* argv [ ] )
{
    ifstream in;
    ofstream out;

    if (argc != 3)
    {
        cout << "Usage: thpe23.exe inputMaze outputMaze" << endl;
        exit(0);
    }
    in.open(argv[1]);
    if (!in.is_open())
    {
        cout << "Unable to open file: " << argv[1] << endl;
        exit(0);
    }
    out.open(argv[2]);
    if (!out.is_open())
    {
        cout << "Unable to open file: " << argv[2] << endl;
        in.close();
        exit(0);
    }
    process(in,out);
    in.close();
    out.close();
    return 0;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function allocates memory for the maze.
 *
 * @param rows - The number of rows in the maze.
 * @param cols - The number of cols in the maze.
 * @par Example:
   @verbatim

       allocateMaze ( 5, 5 );

       Output:
       Returns pointer to 2D array
   @endverbatim
 *
 ******************************************************************************/
char** allocateMaze(int rows, int cols)
{
    int i;
    char** maze = nullptr;
    maze = new(nothrow) char* [rows];
    if (maze == nullptr) //checks for error
    {
        cout << "Memory Error" << endl;
        exit(1);
    }

    for (i = 0; i < rows; i++)
    {
        maze[i] = new(nothrow) char[cols];
    }
    if (maze[0] == nullptr) //checks for errors 
    {
        cout << "Memory Error" << endl;
        exit(1);
    }
    return maze;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function deallocates memory for the maze.
 *
 * @param rows - The number of rows in the maze.
 * @param cols - The number of cols in the maze.
 * @par Example:
   @verbatim

       allocateMaze ( 5, 5 );

       Output:
       NONE
   @endverbatim
 *
 ******************************************************************************/
void deleteMaze(char** maze, int rows)
{
    int i;
    for (i = 0; i < rows; i++)
    {
        delete[] maze[i];
    }
    delete[] maze;
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function prints the maze.
 *
 * @param maze - The 2D array containing the maze.
 * @param out - The file to write the data to.
 * @param rows - The number of rows in the maze.
 * @param cols - The number of cols in the maze.
 * @param count - The number of mazes to print.
 * @param mazeInfo - The struct with maze data.
 * @par Example:
   @verbatim

       printMaze ( maze, out, 5, 5, 2, mazeInfo );

       Output:
       Returns NONE, Print To file
   @endverbatim
 *
 ******************************************************************************/
void printMaze(char** maze, ofstream& out, int rows, int cols, int count, mazeSolve mazeInfo)
{
    if (count > 1)
    {
        out << "\n";
    }
    out << "Maze " << count << ":" << "\n";
    out << "    " << "Size: " << rows << " x " << cols << "\n";
    out << "    " << "Starting Coordinates: " << mazeInfo.startRow << " " << mazeInfo.startCol << "\n";
    out << "    " << "Shortest Path: " << mazeInfo.steps << " steps" << "\n";

    for (int i = 0; i < rows; ++i)
    {
        out << "    ";
        for (int j = 0; j < cols; ++j)
        {

            out << maze[i][j];

        }
        out << "\n";
    }

}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function reads in the data the maze, allocate and process the maze.
 *
 * @param in - Input stream from which data is read.
 * @param out - Output stream from which data is exported.
 * @par Example:
   @verbatim

       process ( in , out );

       Output:
       NONE
   @endverbatim
 *
 ******************************************************************************/
void process(ifstream& in, ofstream& out)
{
    mazeSolve info;
    string size;
    string pos;
    string sizeR;
    string sizeC;
    string posR;
    string posC;
    size_t  temp;
    int steps;
    int count = 0;
    char** maze;
    while (getline(in, size) && size.empty() == false)//reads data in 
    {
        count++;//adds number of mazes
        getline(in, pos);
        temp = size.find(' ');
        sizeR = size.substr(0, temp); // rows
        sizeC = size.substr(temp + 1, size.size()); //cols
        temp = size.find(' ');
        posR = pos.substr(0, temp); //start rows
        posC = pos.substr(temp, pos.size());  //start cols
        info.rows = stoi(sizeR); //number coverstion 
        info.cols = stoi(sizeC);
        info.startRow = stoi(posR);
        info.startCol = stoi(posC);

        maze = allocateMaze(info.rows, info.cols);//maze allocate 
        info.shortestMaze = allocateMaze(info.rows, info.cols);//maze allocate
        in >> noskipws;
        for (int i = 0; i < info.rows; ++i)//reads in 
        {
            for (int j = 0; j < info.cols; ++j)
            {
                in >> maze[i][j]; 
                if (in.peek() == '\n')
                {
                    in.get();
                }
            } 
        }
        steps = 0;
        info.steps = info.rows * info.cols;
        solveMaze(maze, info.rows, info.cols, info.startRow, info.startCol, steps, info);//solves maze 
        info.steps++;
        printMaze(info.shortestMaze, out, info.rows, info.cols, count, info);
        deleteMaze(maze, stoi(sizeR));
    }
}



/** ***************************************************************************
 * @author Zackery Holloway
 *
 * @par Description:
 * This function solves the maze through bruit force.
 *
 * @param maze - The 2D array containing the maze passed by refernce. 
 * @param rows - The number of rows in the maze.
 * @param cols - The number of cols in the maze.
 * @param currentRow - The row we start on. 
 * @parama currentCol - The cols we start on. 
 * @parama steps - The number of steps taken passed by refernce. 
 * @param mazeInfo - The strucutre conating data. 
 * @par Example:
   @verbatim

       sovleMaze ( maze , 5, 5, 2, 2, 0, mazeInfo );

       Output:
       True
   @endverbatim
 *
 ******************************************************************************/
bool solveMaze(char** &maze, int rows, int cols, int currentRow, int currentCol, int &steps, mazeSolve &mazeInfo) 
{
    char temp;
    int tempStep = steps; 
    if (maze[currentRow][currentCol] == 'E')
    {
        if (mazeInfo.steps > steps)
        {
            mazeInfo.steps = steps;
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    mazeInfo.shortestMaze[i][j] = maze[i][j];
                }
            }
            steps = 0;
            return true;
        }
        steps = tempStep;
        return false;
    }
    if (maze[currentRow][currentCol] == '*' || maze[currentRow][currentCol] == '-' ||
        maze[currentRow][currentCol] == '+' || maze[currentRow][currentCol] == 'L' ||
        maze[currentRow][currentCol] == '=')
    {
        return false;
    }
    temp = maze[currentRow][currentCol];
    if (maze[currentRow][currentCol] == 'W')
    {
        steps = steps + 2;
        maze[currentRow][currentCol] = '=';
    }
    else if (maze[currentRow][currentCol] == 'S')
    {
        steps = steps + 3;
        maze[currentRow][currentCol] = '+';
    }
    else
    {
        steps++;
        maze[currentRow][currentCol] = '-';
    }
    tempStep = steps;
    solveMaze(maze, rows, cols, currentRow - 1, currentCol, steps, mazeInfo);  // Up
    solveMaze(maze, rows, cols, currentRow, currentCol + 1, steps, mazeInfo);// Right
    solveMaze(maze, rows, cols, currentRow + 1, currentCol, steps, mazeInfo);  // Down
    solveMaze(maze, rows, cols, currentRow, currentCol - 1, steps, mazeInfo);   // Left
    maze[currentRow][currentCol] = temp;
    if (temp == 'W')
    {
        steps = tempStep - 2;
    }
    else if (temp == 'S')
    {
        steps = tempStep - 3;
    }
    else
    {
        steps = tempStep - 1;
    }
    return false;
}