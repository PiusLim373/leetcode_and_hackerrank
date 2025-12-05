#include <string>
#include <stack>

int calculate(std::string s)
{
    std::stack<std::string> st;
    int index = 0;
    std::string temp;
    while (index < s.size())
    {
        char ch = s[index];
        if (ch == ' ')
        {
        }
        else if (ch == '(')
        {
            if (temp == "-")
                st.push("neg");
            st.push("(");
            temp.clear();
        }
        else if (s[index] == ')')
        {
            if (temp.size())
            {
                st.push(temp);
                temp.clear();
            }
            int sum = 0;
            while (!st.empty())
            {
                std::string top;
                top = st.top();
                st.pop();
                if (top == "(")
                {
                    if (!st.empty() && st.top() == "neg")
                    {
                        sum *= -1;
                        st.pop();
                    }
                    st.push(std::to_string(sum));
                    break;
                }
                else
                {
                    sum += std::stoi(top);
                }
            }
        }
        else if (isdigit(ch))
        {
            temp += ch;
        }
        else
        {
            if (ch == '-')
            {
                if (temp.size())
                    st.push(temp);
                temp = "-";
            }
            else
            {
                if (temp.size())
                    st.push(temp);
                temp.clear();
            }
        }
        index++;
    }

    if (temp.size())
    {
        st.push(temp);
        temp.clear();
    }
    int sum = 0;
    while (!st.empty())
    {
        std::string top;
        top = st.top();
        st.pop();
        if (top == "(")
        {
            if (!st.empty() && st.top() == "neg")
            {
                sum *= -1;
                st.pop();
            }
            st.push(std::to_string(sum));
            break;
        }
        else
        {
            sum += std::stoi(top);
        }
    }
    return sum;
}

int main()
{
    // std::string s = " (11-(444+5- 105-32)-3)-(6+8)";
    // std::string s = " 2-1 + 2 ";
    std::string s = "1-(     -2)";

    auto ans = calculate(s);
    return 0;
}