#include <limits>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    int maxAbsoluteSum(const vector<int>& nums) {
        int bestSum = 0;
        int sum1 = 0;
        int sum2 = 0;
        for (auto a : nums) {
            sum1 = std::max(0, sum1 + a);
            sum2 = std::max(0, sum2 - a);
            bestSum = std::max(bestSum, sum1);
            bestSum = std::max(bestSum, sum2);
        }
        return bestSum;
    }
};
// @leet end
