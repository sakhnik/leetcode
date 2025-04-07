#include <string>

using namespace std;

// @leet start
class Solution {
public:
    string getHappyString(int n, int k) {
        std::string s;
        s.reserve(n);
        
        auto generate = [&](auto &&generate) -> bool {
            if (s.size() == n) {
                return !--k;
            }
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                if (!s.empty() && ch == s.back()) continue;
                s.push_back(ch);
                if (generate(generate))
                    return true;
                s.pop_back();
            }
            return false;
        };

        if (generate(generate))
            return s;
        return "";
    }
};
// @leet end

int main()
{
    return Solution{}.getHappyString(3, 9).size();
}
