#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    int longestNiceSubarray(const vector<int>& nums) {
        int maxLen = 0;
        int curMask = 0;
        int curLen = 0;

        for (int i = 0; i < nums.size(); ) {
            auto n = nums[i];
            if (!(curMask & n)) {
                curMask |= n;
                ++curLen;
                ++i;
            } else {
                if (curLen > maxLen) {
                    maxLen = curLen;
                    if (curLen == 31) {
                        return curLen;
                    }
                }
                maxLen = std::max(maxLen, curLen);
                curMask &= ~nums[i - curLen];
                --curLen;
            }
        }

        return std::max(maxLen, curLen);
    }
};
// @leet end

int main()
{
    return Solution{}.longestNiceSubarray({1, 3, 8, 48, 10});
}
