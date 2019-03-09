#ifndef file_manager_hpp
#define file_manager_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> FileLines;

vector<FileLines> getCSVFileLines(string fileName);

#endif
