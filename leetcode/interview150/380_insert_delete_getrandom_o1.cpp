#include <iostream>
#include <vector>
#include <unordered_map>

class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (m.count(val))
            return false;
        else
        {
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
    }

    bool remove(int val)
    {
        if (!m.count(val))
            return false;
        else
        {
            int index = m[val];
            int last_data = v.back();
            v[index] = last_data;
            m[last_data] = index;
            v.pop_back();
            m.erase(val);
            return true;
        }
    }

    int getRandom()
    {
        int rand = std::rand() % v.size();
        return v[rand];
    }

private:
    std::vector<int> v;
    std::unordered_map<int, int> m;
};

int main()
{
    RandomizedSet *rs = new RandomizedSet();
    rs->insert(0);
    rs->insert(1);
    rs->remove(0);
    rs->insert(2);
    rs->remove(1);
    std::cout << rs->getRandom() << std::endl;
}