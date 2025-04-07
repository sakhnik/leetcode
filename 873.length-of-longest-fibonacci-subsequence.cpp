#include <vector>
#include <unordered_map>

using namespace std;

// @leet start
class Solution {
public:
    using VecT = std::vector<int>;

    int lenLongestFibSubseq(const VecT &arr) {
        const int len = arr.size();

        std::vector<int> dp(len * len, 0);
        int maxLen = 0;

        for (int i = 0; i < len; ++i) {
            int j = 0;
            int k = i - 1;
            while (j < k) {
                int sum = arr[j] + arr[k];
                if (sum > arr[i])
                    --k;
                else if (sum < arr[i])
                    ++j;
                else {
                    maxLen = std::max(maxLen, dp[k * len + i] = 1 + dp[j * len + k]);
                    ++j, --k;
                }
            }
        }

        return maxLen ? maxLen + 2 : 0;
    }
};
// @leet end
