#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;

// @leet start
class Solution {
public:
    int numOfSubarrays(const vector<int>& arr) {
        constexpr const int p = 1'000'000'007;

        int prevSum = 0;
        uint64_t sum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prevSum = (arr[i] & 1) ? (1 + i - prevSum) : prevSum;
            sum += prevSum;
        }

        return sum % p;
    }
};
// @leet end

int main()
{
    std::cout << Solution{}.numOfSubarrays({1, 3, 5}) << std::endl;
    std::cout << Solution{}.numOfSubarrays({2, 4, 6}) << std::endl;
    std::cout << Solution{}.numOfSubarrays({1, 2, 3, 4, 5, 6, 7}) << std::endl;
    return 0;
}
