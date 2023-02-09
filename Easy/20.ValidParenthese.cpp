class Solution {
public:
    bool isValid(std::string s)
    {        
        std::stack<char> stk;
        for (const auto& c:s)
        {
            switch(c)
            {
                case '(': stk.push(')'); break;
                case '{': stk.push('}'); break;
                case '[': stk.push(']'); break; // only close paren is inserted

                default:
                    if(stk.empty()||c!=stk.top()) return false;
                    else stk.pop(); // close paren is removed
            }
        }
        return stk.empty();
    }
};
