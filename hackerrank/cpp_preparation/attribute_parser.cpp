#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

class Attributes
{
public:
    std::map<std::string, std::string> properties;
    std::map<std::string, Attributes> children;
    Attributes() {};
};

int main_tooComplex()
{
    // std::istringstream input(
    //     "4 3\n"
    //     "<tag1 value = \"HelloWorld\">\n"
    //     "<tag2 name = \"Name1\">\n"
    //     "</tag2>\n"
    //     "</tag1>\n");

    std::istringstream input(
        "6 3\n"
        "<tag1 value = \"value\">\n"
        "<tag2 name = \"name\"  >\n"
        "<tag3 another=\"another\" final=\"final\" >\n"
        "</tag3>\n"
        "</tag2>\n"
        "</tag1>\n");
    std::cin.rdbuf(input.rdbuf());

    int lines, queries;
    std::cin >> lines >> queries;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "lines to read: " << lines << "; queries to process: " << queries << std::endl;

    // std::map<std::string, Attributes> data;
    Attributes *curr = new Attributes();
    std::string curr_directory = "root";
    for (int i = 0; i < lines; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        std::cout << "processing line " << i << ", " << line << std::endl;
        if (line[1] != '/')
        {
            int j = 1;
            std::string tag_name;
            while (line[j] != ' ')
            {
                tag_name += line[j];
                j++;
            }
            j++;
            std::cout << "tag_name: " << tag_name << std::endl;
            std::string key, value;
            int mode = 0;
            curr->children[tag_name] = Attributes();
            while (1)
            {
                if (line[j] == '>')
                {
                    if (key.size())
                    {
                        cleanUp(key, value);
                        if (key.size() && value.size())
                            curr->children[tag_name].properties[key] = value;
                    }
                    break;
                }
                if (line[j] == '=')
                {
                    mode = 1;
                    j++;
                }
                if (line[j] == ' ' && mode == 1 && value.size())
                {
                    cleanUp(key, value);
                    if (key.size() && value.size())
                        curr->children[tag_name].properties[key] = value;
                    mode = 0;
                    key = "";
                    value = "";
                }
                if (mode == 0)
                    key += line[j];
                else
                    value += line[j];
                j++;
            }
        }
    }

    return 0;
}

void cleanUp(std::string &key, std::string &value)
{
    std::string return_key, return_value;
    int i = 0;
    while (!isalnum(key[i]))
        i++;
    for (int j = i; j < key.size(); j++)
    {
        char x = key[j];
        if (x == ' ' || x == '"')
            break;
        return_key += x;
    }

    i = 0;
    while (!isalnum(value[i]))
        i++;
    for (int j = i; j < value.size(); j++)
    {
        char x = value[j];
        if (x == ' ' || x == '"')
            break;
        return_value += x;
    }
    key = return_key;
    value = return_value;
}

void fillData(std::vector<std::string> &stack, std::string &key, std::string &value, std::map<std::string, std::string> &data)
{
    std::string temp;
    for (int i = 0; i < stack.size(); i++)
    {
        temp += stack[i];
        if (i != stack.size() - 1)
            temp += ".";
    }
    temp += "~";
    temp += key;
    data[temp] = value;
}

int main()
{
    std::istringstream input(
        "6 4\n"
        "<a>\n"
        "<b name = \"tag_one\">\n"
        "<c name = \"tag_two\" value = \"val_907\">\n"
        "</c>\n"
        "</b>\n"
        "</a>\n"
        "a.b~name\n"
        "a.b.c~value\n"
        "a.b.c~src\n"
        "a.b.c.d~name\n");

    // std::istringstream input(
    //     "6 3\n"
    //     "<tag1 value = \"value\">\n"
    //     "<tag2 name = \"name\"  >\n"
    //     "<tag3 another=\"another\" final=\"final\" >\n"
    //     "</tag3>\n"
    //     "</tag2>\n"
    //     "</tag1>\n"
    //     "tag1~value\n"
    //     "tag1.tag2.tag3~name\n"
    //     "tag1.tag2.tag3~final\n");
    std::cin.rdbuf(input.rdbuf());

    int lines, queries;
    std::cin >> lines >> queries;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::map<std::string, std::string> data;
    std::vector<std::string> stack;
    for (int i = 0; i < lines; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        if (line[1] != '/')
        {
            int j = 1;
            std::string tag_name;
            while (line[j] != ' ')
            {
                if (line[j] == '>')
                    break;
                tag_name += line[j];
                j++;
            }
            j++;
            stack.push_back(tag_name);
            std::string key, value;
            int mode = 0;
            while (j < line.size())
            {
                if (line[j] == '>')
                {
                    if (key.size())
                    {
                        cleanUp(key, value);
                        if (key.size() && value.size())
                            fillData(stack, key, value, data);
                    }
                    break;
                }
                if (line[j] == '=')
                {
                    mode = 1;
                    j++;
                }
                if (line[j] == ' ' && mode == 1 && value.size())
                {
                    cleanUp(key, value);
                    if (key.size() && value.size())
                        fillData(stack, key, value, data);
                    mode = 0;
                    key = "";
                    value = "";
                }
                if (mode == 0)
                    key += line[j];
                else
                    value += line[j];
                j++;
            }
        }
        else
        {
            stack.pop_back();
        }
    }

    for (int i = 0; i < queries; i++)
    {
        std::string line, ans;
        std::getline(std::cin, line);
        if (data.count(line) == 0)
            ans = "Not Found!";
        else
            ans = data[line];
        std::cout << ans << std::endl;
    }
    return 0;
}