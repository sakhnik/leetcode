#include <string>
#include <unordered_set>

using namespace std;

// @leet start
class Solution {
public:
    int numTilePossibilities(string tiles) {
        std::unordered_set<std::string> seq;

        std::string pattern;
        auto search = [&](auto &&search) {
            if (pattern.size() == tiles.size())
                return;
            for (int i = 0; i < tiles.size(); ++i) {
                char ch = tiles[i];
                if (ch != ' ') {
                    tiles[i] = ' ';
                    pattern.push_back(ch);
                    seq.insert(pattern);
                    search(search);
                    pattern.pop_back();
                    tiles[i] = ch;
                }
            }
        };
        search(search);
 
        return seq.size();
    }
};
// @leet end
