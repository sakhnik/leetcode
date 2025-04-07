#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        constexpr const auto MINHEAP = std::greater<int>{};
        constexpr const uint64_t MAX = std::numeric_limits<int>::max();

        std::make_heap(nums.begin(), nums.end(), MINHEAP);
        for (int i = 0; ; ++i) {
            std::pop_heap(nums.begin(), nums.end(), MINHEAP);
            int x = nums.back();
            if (x >= k) {
                return i;
            }
            nums.pop_back();
            if (nums.empty())
                return -1;
            std::pop_heap(nums.begin(), nums.end(), MINHEAP);
            int y = nums.back();
            uint64_t z = 2ull * std::min(x, y) + std::max(x, y);
            nums.back() = std::min(z, MAX);
            std::push_heap(nums.begin(), nums.end(), MINHEAP);
        }
        return -1;
    }
};
// @leet end
