#include <stack>
#include <string>
bool isValid(std::string s)
{
    std::stack<char> st;
    for (auto x : s)
    {
        if (x == '(' || x == '[' || x == '{')
            st.push(x);
        else
        {
            switch (x)
            {

            case ')':
                if (st.size() && st.top() == '(')
                    st.pop();
                else
                    return false;
                break;
            case ']':
                if (st.size() && st.top() == '[')
                    st.pop();
                else
                    return false;
                break;
            case '}':
                if (st.size() && st.top() == '{')
                    st.pop();
                else
                    return false;
                break;
            }
        }
    }
    if (st.size())
        return false;
    return true;
}
int main()
{
    std::string s = "([)]";
    auto ans = isValid(s);
    return 0;
}