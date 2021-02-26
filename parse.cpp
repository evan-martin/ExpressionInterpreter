#include <cctype>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "parse.h"

string parseName(stringstream &streamLine)
{
    char alnum;
    string name = "";

    streamLine >> ws;
    while (isalnum(streamLine.peek()))
    {
        streamLine >> alnum;
        name += alnum;
    }
    return name;
}
