#include <string>
#include <stack>
#include <algorithm>
std::string decodeString(std::string s)
{
    std::stack<char> char_s;
    for (auto c : s)
    {
        if (c == ']')
        {
            // backtrack the stack until the openning bracket
            std::string str_temp;
            while (!char_s.empty() && char_s.top() != '[')
            {
                str_temp += char_s.top();
                char_s.pop();
            }
            std::reverse(str_temp.begin(), str_temp.end());

            // pop the opening bracket
            char_s.pop();

            // get the frequency
            std::string fre_temp;
            while (!char_s.empty() && isdigit(char_s.top()))
            {
                fre_temp += char_s.top();
                char_s.pop();
            }
            std::reverse(fre_temp.begin(), fre_temp.end());
            int fre = std::stoi(fre_temp);

            // formulate the string
            std::string data;
            for (int i = 0; i < fre; i++)
                data += str_temp;

            // push the string back to the stack
            for (auto d : data)
                char_s.push(d);
        }
        else
            char_s.push(c);
    }

    std::string ans;
    while (!char_s.empty())
    {
        ans += char_s.top();
        char_s.pop();
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}
std::string decodeStringNotWorking(std::string s)
{
    std::stack<int> fre_s;
    std::stack<std::string> str_s;

    std::string temp_fre;
    std::string temp_str;
    std::string ans;

    int pos = 0;
    while (pos < s.size() && !isdigit(s[pos]))
    {
        ans += s[pos];
        pos++;
    }
    for (int i = pos; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {

            temp_fre += s[i];
            if (temp_str != "")
            {
                str_s.push(temp_str);
                temp_str = "";
            }
        }
        else if (isalpha(s[i]))
            temp_str += s[i];
        else if (s[i] == '[')
        {
            fre_s.push(std::stoi(temp_fre));
            temp_fre = "";
        }
        else
        {
            if (temp_str != "")
                str_s.push(temp_str);
            if (fre_s.size() > 1)
            {
                std::string temp;
                for (int j = 0; j < fre_s.top(); j++)
                    temp += str_s.top();
                fre_s.pop();
                str_s.pop();
                if (!str_s.empty())
                    temp = str_s.top() += temp;
                str_s.pop();
                str_s.push(temp);
                temp_str = "";
            }
            else
            {
                std::string temp;
                for (int j = 0; j < fre_s.top(); j++)
                    temp += str_s.top();
                ans += temp;
                fre_s.pop();
                str_s.pop();
                temp_str = "";
            }
        }
    }
    if (temp_str != "")
        ans += temp_str;
    return ans;
}
// 33: a
// 2: c
int main()
{
    // std::string s = "3[a2[c]]";
    // std::string s = "2[abc]3[cd]ef";
    // std::string s = "abc3[cd]xyz";
    // std::string s = "leetcode";
    std::string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";

    auto ans = decodeString(s);
    return 0;
}