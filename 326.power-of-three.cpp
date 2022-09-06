#include <limits>
#include <cassert>

const constexpr int threshold = std::numeric_limits<int>::max() / 3;

constexpr int p3()
{
    int a = 1;
    while (a < threshold)
        a *= 3;
    return a;
}
constexpr auto MAXP3 = p3();

class Solution {
public:

    bool isPowerOfThree(int n)
    {
        return n > 0 && 0 == (MAXP3 % n);
    }
};

#ifdef TEST
int main()
{
    assert(Solution{}.isPowerOfThree(1162261467));
    return 0;
}
#endif
