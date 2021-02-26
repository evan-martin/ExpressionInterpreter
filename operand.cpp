#include <cctype>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream &streamLine)
{
    char paren;
    double value;

    streamLine >> ws;
    if (isdigit(streamLine.peek()))
    {
        streamLine >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (streamLine.peek() == '(')
    {
        streamLine >> paren;
        return SubExpression::parse(streamLine);
    }
    else
        return new Variable(parseName(streamLine));
    return 0;
}