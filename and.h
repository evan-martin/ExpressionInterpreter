class And: public SubExpression
{
public:
    And(Expression* left, Expression* right):
            SubExpression(left, right)
    {
    }
    int evaluate()
    {
        if(left->evaluate() && right->evaluate())
            return 1;
        else return 0;
    }
};