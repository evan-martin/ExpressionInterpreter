class Divide: public SubExpression
{
public:
    Divide(Expression* left, Expression* right):
            SubExpression(left, right)
    {
    }
    int evaluate()
    {
        if(right->evaluate()==0){
            return 0;
        }
        return left->evaluate() / right->evaluate();
    }
};