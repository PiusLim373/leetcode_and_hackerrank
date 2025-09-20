#include <vector>
void recv(std::vector<std::vector<int>> &ans, std::vector<int> curr_ans, int size, int remainder, int number)
{
    if (size == 0 && remainder == 0)
    {
        ans.push_back(curr_ans);
        return;
    }
    if (size <= 0)
        return;
    for(int i = number; i <= std::min(9, remainder); i++)
    {
        std::vector<int> temp = curr_ans;
        temp.push_back(i);
        recv(ans, temp, size - 1, remainder - i, i + 1);
    }
    return;
}

std::vector<std::vector<int>> combinationSum3(int k, int n)
{
    std::vector<std::vector<int>> ans;
    recv(ans, {}, k, n, 1);
    return ans;
}
int main()
{
    int k = 3;
    int n = 9;
    auto res = combinationSum3(k, n);
    return 0;
}