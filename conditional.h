class Conditional: public SubExpression
{
public:
    Conditional(Expression* left, Expression* right, Expression* condition):
            SubExpression(left, right)
    {
        this->condition=condition;
    }
    int evaluate()
    {
        if(condition->evaluate())
            return left->evaluate();
        else return right->evaluate();
    }
private:
    Expression *condition;
};