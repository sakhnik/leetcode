#include <vector>

using namespace std;

using MatT = vector<vector<int>>;

class Solution {
public:
    void rotate(MatT& m) {
        const int n = m.size();

        for (int offset = 0; offset < n / 2; ++offset)
        {
            int side = n - offset * 2;
            if (side < 2)
                return;
            for (int i = 1; i < side; ++i)
            {
                int low = offset;
                int low_mid = offset + i;
                int high = offset + side - 1;
                int high_mid = high - i;

                int tmp = m[low][low_mid];
                m[low][low_mid] = m[high_mid][low];
                m[high_mid][low] = m[high][high_mid];
                m[high][high_mid] = m[low_mid][high];
                m[low_mid][high] = tmp;
            }
        }
    }
};

#ifdef TEST
int main()
{
    MatT m{{1,2,3}, {4,5,6}, {7,8,9}};
    Solution{}.rotate(m);
    MatT exp{{7,4,1}, {8,5,2}, {9,6,3}};
    if (m != exp)
        return 1;
    return 0;
}
#endif
