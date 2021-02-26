#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;


void parseAssignments();

int main(){

    string line;
    fstream file;
    file.open("../input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {

            cout << line << '\n';
            Expression* expression;
            char paren, comma;
            cout << "Enter expression: ";
            cin >> paren;
            expression = SubExpression::parse();
            cin >> comma;
            parseAssignments();
            cout << "Value = " << expression->evaluate() << endl;

        }
        file.close();
    }

    return 0;
}


void parseAssignments()
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName();
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}