#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;


void parseAssignments(stringstream &streamLine);

int main(){

    string line;
    fstream file;
    file.open("../input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {

            Expression* expression;
            char paren, comma;
            stringstream streamLine(line);
            streamLine >> paren;
            expression = SubExpression::parse(streamLine);
            streamLine >> comma;
            parseAssignments(streamLine);
            cout << line << '\t' << "Value = " << expression->evaluate() << endl;

        }
        file.close();
    }

    return 0;
}


void parseAssignments(stringstream &streamLine)
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName(streamLine);
        streamLine >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}