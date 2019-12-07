#include "stub.h"
bool isParenthesisBalanced(const string& str)
{
    bool result = false;
    if(!str.empty())
    {
        stack<char> parenthesis_stack;
        for(auto x:str)
        {
            if( x == '(')
                parenthesis_stack.push(x);
            else if(x == ')')
            {
                if(!parenthesis_stack.empty())
                {
                  parenthesis_stack.pop();
                }
            }

        }
        if(parenthesis_stack.empty())
        {
            result = true;
        }
    }
    return result;
}

int wwe()
{
    string str = "(a+b)-(c)()(()()";
    if(isParenthesisBalanced(str))
    {
        cout <<"Balanced";
    }
    else
    {
       cout <<"Not Balanced";
    }
    cout <<'\n';
    return 0;
}
