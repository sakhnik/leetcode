#include <vector>
#include <algorithm>

using namespace std;

using VecT = std::vector<int>;
using MatT = std::vector<VecT>;

class Iter
{
public:
    MatT *m;
    int r, c;

    Iter(MatT &m, int r, int c)
        : m{&m}, r{r}, c{c}
    {
    }

    Iter& operator=(const Iter &o) = default;

    //auto operator<=>(const Iter &o) const = default;
    bool operator==(const Iter &o) const { return r == o.r; }
    bool operator!=(const Iter &o) const { return r != o.r; }
    bool operator<(const Iter &o) const { return r < o.r; }

    Iter& operator++() { ++r; ++c; return *this; }
    Iter& operator--() { --r; --c; return *this; }

    Iter operator+(int b) { return {*m, r + b, c + b}; }
    Iter operator-(int b) { return {*m, r - b, c - b}; }

    int operator-(const Iter &o) const { return r - o.r; }

    int& operator*() { return (*m)[r][c]; }

    typedef random_access_iterator_tag iterator_category;
    typedef int value_type;
    typedef int difference_type;
    typedef int* pointer;
    typedef int& reference;
};

class Solution
{
public:
    MatT& diagonalSort(MatT& mat) {
        int H = mat.size();
        int W = mat[0].size();

        auto getCount = [&](int r, int c) {
            return std::min(W - c, H - r);
        };

        auto sortDiag = [&](int r, int c) {
            auto count = getCount(r, c);
            Iter b{mat, r, c};
            Iter e{mat, r + count, c + count};
            std::sort(b, e);
        };

        for (int r = 0; r < H; ++r)
            sortDiag(r, 0);

        for (int c = 1; c < W; ++c)
            sortDiag(0, c);

        return mat;
    }
};

#ifdef TEST
int main()
{
    MatT m{{3,3,1,1}, {2,2,1,2}, {1,1,1,2}};
    Solution{}.diagonalSort(m);
    return 0;
}
#endif
