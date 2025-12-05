#include <stack>
#include <vector>
#include <string>
int evalRPN(std::vector<std::string> &tokens)
{
    std::stack<int> st;
    for (auto t : tokens)
    {
        if (t == "+" || t == "-" || t == "*" || t == "/")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            if (t == "+")
                st.push(num1 + num2);
            else if (t == "-")
                st.push(num1 - num2);
            else if (t == "*")
                st.push(num1 * num2);
            else if (t == "/")
                st.push(num1 / num2);
        }
        else
            st.push(std::stoi(t));
    }
    return st.top();
}
int main()
{
    // std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    auto ans = evalRPN(tokens);
    return 0;
}
