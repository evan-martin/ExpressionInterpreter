class Conditional: public SubExpression
{
public:
    Conditional(Expression* left, Expression* right):
            SubExpression(left, right)
    {
    }
    int evaluate()
    {
        if(left->evaluate() || right->evaluate())
            return 1;
        else return 0;
    }
};