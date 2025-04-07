#include <vector>
#include <algorithm>

using namespace std;

// @leet start
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto range = std::equal_range(nums.begin(), nums.end(), 0);
        return std::max(range.first - nums.begin(), nums.end() - range.second);
    }
};
// @leet end
