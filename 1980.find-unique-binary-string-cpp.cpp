#include <string>
#include <vector>

class Solution {
public:
    std::string findDifferentBinaryString(const std::vector<std::string>& nums) {
        // The string must be different in at least one position
        std::string res;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            res.push_back('0' + ('1' - nums[i][i]));
        }
        return res;
    }
};
