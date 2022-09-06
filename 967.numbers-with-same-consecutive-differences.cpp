#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nums;

    void Traverse(int n, int k, int a, int last)
    {
        if (!n)
        {
            if (nums.empty() || nums.back() != a)
                nums.push_back(a);
            return;
        }

        if (last >= k)
        {
            int d = last - k;
            Traverse(n - 1, k, a * 10 + d, d);
        }
        if (last + k < 10)
        {
            int d = last + k;
            Traverse(n - 1, k, a * 10 + d, d);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; ++i)
            Traverse(n - 1, k, i, i);
        return nums;
    }
};
