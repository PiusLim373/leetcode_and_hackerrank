#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
int singleNumber(std::vector<int> &nums)
{
    std::vector<std::string> bits;
    for (auto x : nums)
        bits.push_back(std::bitset<32>(x).to_string());

    std::string outliner;
    for (int str_index = 0; str_index < 32; str_index++)
    {
        int sum = 0;
        for (auto b: bits)
            sum += b[str_index] - '0';
        outliner += (sum % 3) + '0';
    }
    return static_cast<int>(std::bitset<32>(outliner).to_ulong());
}

int main()
{
    std::vector<int> nums = {-2,-2,1,1,4,1,4,4,-4,-2};
    auto ans = singleNumber(nums);
    return 0;
}