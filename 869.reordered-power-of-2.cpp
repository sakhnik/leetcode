#include <algorithm>
#include <array>
#include <vector>

using CountsT = std::array<int8_t, 10>;

CountsT Count(int n)
{
    CountsT counts;
    counts.fill(0);
    while (n > 0)
    {
        ++counts[n % 10];
        n /= 10;
    }
    return counts;
}

using PowersT = std::vector<CountsT>;

class Solution {
public:
    PowersT GetPowers()
    {
        PowersT powers;
        for (int i = 0; i < 31; ++i)
            powers.push_back(Count(1 << i));
        return powers;
    }

    bool reorderedPowerOf2(int n) {
        static PowersT powers = GetPowers();
        auto counts = Count(n);
        return std::find(powers.begin(), powers.end(), counts) != powers.end();
    }
};

#ifdef TEST
#include <iostream>
int main()
{
    std::cout << Solution{}.reorderedPowerOf2(1) << std::endl;
    return 0;
}
#endif
