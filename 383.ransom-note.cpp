#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        std::array<int, 26> ab;
        ab.fill(0);
        for (char ch : magazine)
        {
            ++ab[ch - 'a'];
        }

        for (char ch : ransomNote)
        {
            if (0 > --ab[ch - 'a'])
                return false;
        }
        return true;
    }
};
