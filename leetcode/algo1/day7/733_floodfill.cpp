#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int image_size_x = image[0].size();
    int image_size_y = image.size();

    vector<int> dir_x{0, 1, 0, -1};
    vector<int> dir_y{-1, 0, 1, 0};
    queue<pair<int, int>> visit_queue;
    map<pair<int, int>, bool> visited;

    visited[{sr, sc}] = true;
    visit_queue.push(make_pair(sr, sc));

    int initial_color = image[sr][sc];

    while (!visit_queue.empty())
    {
        pair<int, int> curr = visit_queue.front();
        visit_queue.pop();

        image[curr.first][curr.second] = newColor;
        for (int i = 0; i < dir_x.size(); i++)
        {
            pair<int, int> child_coor = {curr.first + dir_x[i], curr.second + dir_y[i]};
            if (child_coor.first >= 0 && child_coor.second >= 0 && child_coor.first < image_size_y && child_coor.second < image_size_x)
            {
                if (!visited[child_coor] && image[child_coor.first][child_coor.second] == initial_color)
                {
                    visit_queue.push(child_coor);
                    visited[child_coor] = true;
                }
            }
        }
    }
    return image;
}
int main()
{

    // vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    // int sr = 0, sc = 0, newColor = 2;

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> new_image = floodFill(image, sr, sc, newColor);
    for (auto x : new_image)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}