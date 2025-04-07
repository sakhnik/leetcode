#include <vector>
#include <unordered_map>
#include <array>

using namespace std;

// @leet start
class Solution {
public:
    int maximumSum(const vector<int>& nums) {
        auto getDigitSum = [](int num) {
            int sum{};
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        std::unordered_map<int, std::array<int, 2>> digitsToNum;
        for (auto num : nums) {
            auto sum = getDigitSum(num);
            auto &q = digitsToNum[sum];
            if (num > q[1]) {
                q[1] = num;
                if (q[1] > q[0])
                    std::swap(q[0], q[1]);
            }
        }

        int max_prod{-1};
        for (auto &[_, q] : digitsToNum) {
            if (q[1]) {
                max_prod = std::max(max_prod, q[0] + q[1]);
            }
        }
        return max_prod;
    }
};
// @leet end

int main()
{
    Solution{}.maximumSum({229,398,269,317,420,464,491,218,439,153,482,169,411,93,147,50,347,210,251,366,401});
}
