class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    static Expression *parse(stringstream &streamLine);
protected:
    Expression* left;
    Expression* right;
};