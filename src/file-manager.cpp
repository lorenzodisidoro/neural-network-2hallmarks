#include "file-manager.hpp"
#include <iostream>
#include <fstream>
using namespace std;

char CSV_DELIMITER = ';';

vector<FileLines> getCSVFileLines(string fileName)
{
    vector<FileLines> lines;
    string line;
    long pos;
    
    ifstream in(fileName);
    
    if(!in)
    {
        cout << "An error occurred when try to open file" << endl;
        return lines;
    }
    
    while( getline(in, line) )
    {
        FileLines ln;
        pos = line.find(CSV_DELIMITER);
        while(pos >= 0)
        {
            pos = line.find(CSV_DELIMITER);
            string field = line.substr(0, pos);
            line = line.substr(pos + 1);
            ln.push_back(field);
        }
        
        lines.push_back(ln);
    }
    
    return lines;
}
