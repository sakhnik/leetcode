#include <algorithm>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    vector<int>& pivotArray(vector<int>& nums, int pivot) {
        std::vector<int> tmp(nums.size());

        int k = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < pivot) {
                nums[j++] = nums[i];
            }
            if (nums[i] > pivot) {
                tmp[k++] = nums[i];
            }
        }

        auto it_greater = nums.begin() + nums.size() - k;
        std::copy(tmp.begin(), tmp.begin() + k, it_greater);
        std::fill(nums.begin() + j, it_greater, pivot);

        //auto it = std::stable_partition(nums.begin(), nums.end(), [&](int a) { return a < pivot; });
        //std::stable_partition(it, nums.end(), [&](int a) { return a == pivot; });
        return nums;
    }
};
// @leet end

int main()
{
    std::vector<int> nums = {9,12,5,10,14,3,10};
    Solution{}.pivotArray(nums, 10);
    return 0;
}
