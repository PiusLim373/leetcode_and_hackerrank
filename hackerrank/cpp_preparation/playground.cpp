#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class hotel1
{
private:
    int price;

public:
    hotel1(int prices)
    {
        price = prices;
    }
    int getprice()
    {
        return price;
    }
};

class atashotel : public hotel1
{
private:
    int price;

public:
    atashotel(int prices)
        : hotel1(prices) {}

    int getprice()
    {
        cout << "goof morning0" << endl;
        return hotel1::getprice() + 100;
    }
    using hotel1::getprice;
};

int main()
{
    // vector<hotel1*> rooms;
    // rooms.push_back(new atashotel(10000));
    // for (auto room: rooms)
    // cout << room->getprice() <<endl;
    // return 1;

    // vector<hotel1*> rooms;
    // atashotel* a = new atashotel(1000);
    // hotel1* b = new hotel1(300);
    // rooms.push_back(a);
    // rooms.push_back(b);
    // cout << rooms[0] -> getprice();

    vector<vector<int>> grid_map{
        // {1, 1, 1},
        // {1, 0, 1},
        // {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 1},
    };

    pair<int, int> first = {3, 2};
    pair<int, int> second = {3, 1};
    if (first == make_pair(3, 2))
        cout << "wooww";
    map<int, pair<int, int>> abs;
    map<pair<int, int>, int> aoh;
}