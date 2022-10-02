#include <vector>

using namespace std;


class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); )
        {
            if ((data[i] & 0x80) == 0)
            {
                ++i;
                continue;
            }
            int n = 0;
            if ((data[i] & 0xe0) == 0xc0)
                n = 2;
            else if ((data[i] & 0xf0) == 0xe0)
                n = 3;
            else if ((data[i] & 0xf8) == 0xf0)
                n = 4;
            else
                return false;
            if (i + n > data.size())
                return false;
            for (++i; n > 1; ++i, --n)
            {
                if ((data[i] & 0xc0) != 0x80)
                    return false;
            }
        }
        return true;
    }
};
