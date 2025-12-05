#include <vector>
#include <string>

/*
std::vector<int> lengths;
    std::vector<std::vector<std::string>> lines;
    int i = 0;
    int temp = 0;
    int length = 0;
    std::vector<std::string> line;
    while (i < words.size())
    {
        if (!temp && temp + words[i].size() == maxWidth)
        {
            lines.push_back({words[i]});
            lengths.push_back(words[i].size());
        }
        else if (temp + words[i].size() + 1 <= maxWidth)
        {
            line.push_back(words[i]);
            temp += words[i].size() + 1;
            length += words[i].size();
        }
        else
        {
            lines.push_back(line);
            lengths.push_back(length);
            temp = words[i].size();
            length = words[i].size();
            line = {words[i]};
        }
        i++;
    }
    if (line.size())
    {
        lines.push_back(line);
        lengths.push_back(length);
    }
*/

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth)
{
    std::vector<std::vector<std::string>> lines;
    std::vector<int> lengths;

    std::vector<std::string> line;
    int length = 0;
    for (auto w : words)
    {
        if (line.size() && length + w.size() + line.size() > maxWidth)
        {
            lines.push_back(line);
            lengths.push_back(length);
            line.clear();
            length = 0;
        }
        line.push_back(w);
        length += w.size();
    }
    if (line.size())
    {
        lines.push_back(line);
        lengths.push_back(length);
    }
    std::vector<std::string> ans;

    for (int i = 0; i < lines.size(); i++)
    {
        if (i == lines.size() - 1)
        {
            std::string temp_line;
            for (int j = 0; j < lines[i].size(); j++)
            {
                temp_line += lines[i][j];
                if (j != lines[i].size() - 1)
                {
                    temp_line += ' ';
                }
            }
            int empty_space = maxWidth - temp_line.size();
            if (empty_space > 0)
                temp_line += std::string(empty_space, ' ');
            ans.push_back(temp_line);
            continue;
        }
        int total_space = maxWidth - lengths[i];
        int gap = lines[i].size() - 1;
        if (gap == 0)
        {
            // only 1 word
            std::string temp_line;
            temp_line += lines[i][0];
            temp_line += std::string(maxWidth - lines[i][0].size(), ' ');
            ans.push_back(temp_line);
            continue;
        }
        int space_each = total_space / gap;
        int extra = total_space % gap;

        std::string temp_line;
        for (int j = 0; j < lines[i].size(); j++)
        {
            temp_line += lines[i][j];
            if (j != lines[i].size() - 1)
            {
                temp_line += std::string(space_each + (j < extra ? 1 : 0), ' ');
            }
        }
        ans.push_back(temp_line);
    }
    return ans;
}

int main()
{
    // std::vector<std::string> words = {
    //     "Science",
    //     "is",
    //     "what",
    //     "we",
    //     "understand",
    //     "well",
    //     "enough",
    //     "to",
    //     "explain",
    //     "to",
    //     "a",
    //     "computer.",
    //     "Art",
    //     "is",
    //     "everything",
    //     "else",
    //     "we",
    //     "do",
    // };
    // std::vector<std::string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    // std::vector<std::string> words = {"Listen","to","many,","speak","to","a","few."};
    std::vector<std::string> words = {"a", "b", "c", "d", "e"};
    int maxWidth = 3;
    auto ans = fullJustify(words, maxWidth);
    return 0;
}