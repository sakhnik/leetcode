#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    int getNum(char d)
    {
        switch (d)
        {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        if (s.empty())
            return 0;
        int res = getNum(s[0]);
        int prev_num = res;
        for (int i = 1; i < s.size(); ++i)
        {
            int num = getNum(s[i]);
            res += num;
            if (s[i] == s[i - 1])
            {
                prev_num += num;
            }
            else
            {
                if (prev_num < num)
                {
                    res -= 2 * prev_num;
                }
                prev_num = num;
            }
        }
        return res;
    }
};
