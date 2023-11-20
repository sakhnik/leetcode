#include <vector>
#include <algorithm>
#include <array>

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        int max_sum = 0;

        // Average CPU, average memory.
        //std::sort(nums.begin(), nums.end());
        //for (int *i = &nums[0], *j = i + nums.size() - 1; i < j; ++i, --j)
        //    max_sum = std::max(*i + *j, max_sum);
 
        // Counting sort: best CPU, worst memory
        std::array<int, 100001> counts;
        counts.fill(0);
        int min = 100000, max = 0;
        for (auto num : nums)
        {
            ++counts[num];
            min = std::min(min, num);
            max = std::max(max, num);
        }

        while (min < max)
        {
            if (!counts[min])
                ++min;
            else if (!counts[max])
                --max;
            else
            {
                max_sum = std::max(max_sum, min + max);
                auto count = std::min(counts[min], counts[max]);
                counts[min] -= count;
                counts[max] -= count;
            }
        }
        if (counts[min])
            max_sum = std::max(max_sum, min + max);
        return max_sum;
    }
};
