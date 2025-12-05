#include <deque>
#include <string>
#include <vector>

std::vector<std::string> split(std::string path, char delimiter)
{

    std::vector<std::string> ans;
    std::string temp;

    for (auto c : path)
    {
        if (c == delimiter)
        {
            if (temp.size())
                ans.push_back(temp);
            temp = "";
        }
        else
            temp += c;
    }
    if (temp.size())
        ans.push_back(temp);
    return ans;
}

std::string simplifyPath(std::string path)
{
    std::string ans = "/";
    std::deque<std::string> st;

    auto path_vector = split(path, '/');
    for (auto x : path_vector)
    {
        if (x == "..")
        {
            if(st.size())
                st.pop_back();
        }
        else if (x == ".")
        {
        }
        else
            st.push_back(x);
    }
    while (!st.empty())
    {
        ans += st.front();
        st.pop_front();
        if(st.size())
            ans += "/";
    }
    return ans;
}

int main()
{
    // std::string path = "/.../a/../b/c/../d/./";
    std::string path = "/../";
    auto ans = simplifyPath(path);
    return 0;
}