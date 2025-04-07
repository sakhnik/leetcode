#include <bitset>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        std::bitset<500> counts;
        for (auto a : nums) {
            counts.flip(a - 1);
        }
        return !counts.any();
    }
};
// @leet end
