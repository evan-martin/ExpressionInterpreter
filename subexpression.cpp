#include <iostream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression * SubExpression::parse(stringstream &streamLine)
{
    Expression* left;
    Expression* right;
    char operation, paren;

    left = Operand::parse(streamLine);
    streamLine >> operation;
    right = Operand::parse(streamLine);
    streamLine >> paren;
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
    }
    return 0;
}