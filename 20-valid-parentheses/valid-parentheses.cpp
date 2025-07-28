class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> stk;

        for(int i = 0;i < n;i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                if(!stk.empty() && (stk.top() == ']' || stk.top() == ')' || stk.top() == '}'))
                    return false;
                
                stk.push(s[i]);
            }
            else
            {
                if(!stk.empty() && ((stk.top() == '{' && s[i] == '}') || (stk.top() == '(' && s[i] == ')') || (stk.top() == '[' && s[i] == ']')) )
                {
                    stk.pop();
                }
                else
                    return false;
            }
        }

        return stk.empty();
    }
};