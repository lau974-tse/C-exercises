#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {

bool check(const std::string& text)
{
    std::stack<char> stack;

    for (char c : text)
    {
        // OUVRANTS
        if (c == '(' || c == '[' || c == '{')
        {
            stack.push(c);
        }
        // FERMANTS
        else if (c == ')' || c == ']' || c == '}')
        {
            if (stack.empty())
            {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }

    return stack.empty();
}

}  // namespace matching_brackets
