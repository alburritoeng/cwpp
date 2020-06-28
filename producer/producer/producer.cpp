// producer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include "ErrorCodes.h"
#include "Utilities.h"

using namespace std;

const int BUFFER_SIZE = 1024;

void PrintUsage(int error, char* argv[])
{
    std::cout << "ERROR code" << error << std::endl;
    std::cerr << "Usage: " << argv[0] << " [path to file] [N - number of shared buffers]" << std::endl;
    std::cerr << "Usage: " << argv[0] << " c:\\temp\\file.txt 3" << std::endl;
}

void ReadFileInChunks(char* filename)
{
    std::ifstream fin(filename, std::ifstream::binary);
    
    char* buffer = new char[BUFFER_SIZE+1];
    memset(buffer, 0, BUFFER_SIZE+1);
    while (fin.read(buffer, BUFFER_SIZE)) {
             
        streamsize count = fin.gcount();
        

        std::cout << "Read " << count << "bytes\t " << buffer << std::endl << std::endl;
        memset(buffer, 0, BUFFER_SIZE);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        PrintUsage(PRODINVALDINPUTCNT, argv);
        return PRODINVALDINPUTCNT;
    }

    char* filename = argv[1];
    if (!Utilities::FileExists(filename))
    {
        PrintUsage(PRODFILEDNE, argv);
        return PRODFILEDNE;
    }

    int numberOfSharedBuffers = (int)argv[2];
    if (numberOfSharedBuffers <= 0)
    {
        PrintUsage(PRODINVALIDVALUE, argv);
        return PRODINVALIDVALUE;
    }
    
    //TODO : setup the memory map file/views
    
        
    //read the file line-by-line
    ReadFileInChunks(filename);


    cout << "end of producer" << std::endl;
    return 0;
}
