#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(const vector<string>& nums) {
        const int n = nums.size();

        //std::unordered_set<uint32_t> vals;
        //for (const auto &n : nums) {
        //    vals.insert(std::stoul(n, nullptr, 2));
        //}


        //for (uint32_t i = 0, in = (1 << n); i < in; ++i) {
        //    if (!vals.count(i)) {
        //        return std::bitset<16>(i).to_string().substr(16 - n);
        //    }
        //}

        std::string res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            res.push_back('0' + '1' - nums[i][i]);
        }

        return res;
    }
};

//int main()
//{
//    return Solution{}.findDifferentBinaryString({"00", "01"}).size();
//}
