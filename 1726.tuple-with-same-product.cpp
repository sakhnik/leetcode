#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;

// @leet start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        std::unordered_map<int, int> products;
        products.reserve(nums.size() * (nums.size() - 1) / 2);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                ++products[nums[i] * nums[j]];
            }
        }
        return std::accumulate(products.begin(), products.end(), 0, [](int a, const auto &p) {
            return a + p.second * (p.second - 1) * 4;
        });
    }
};
// @leet end
