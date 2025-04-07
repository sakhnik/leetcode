#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count{};
        int *p = nums.data(), *pN = p + nums.size() - 2;

        for (; p < pN; ++p) {
            if (!p[0]) {
                p[0] = 1 - p[0];
                p[1] = 1 - p[1];
                p[2] = 1 - p[2];
                ++count;
            }
        }
        return p[0] && p[1] ? count : -1;
    }
};
// @leet end
