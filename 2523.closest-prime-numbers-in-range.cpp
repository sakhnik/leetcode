#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = std::sqrt(right);

        auto sieve = [](int n) {
            std::vector<int> primes(n + 1);
            std::iota(primes.begin(), primes.end(), 0);

            int j = 0;
            for (int i = 2; i <= n; ++i) {
                int a = primes[i];
                if (int a = primes[i]) {
                    primes[j++] = i;
                    for (int p = a + a; p <= n; p += a) {
                        primes[p] = 0;
                    }
                }
            }
            primes.erase(primes.begin() + j, primes.end());
            return primes;
        };
        auto factors = sieve(std::sqrt(right));

        auto isPrime = [&](int a) {
            for (int i = 0; i < factors.size(); ++i) {
                if (factors[i] * factors[i] > a)
                    break;
                if (a % factors[i] == 0)
                    return false;
            }
            return true;
        };

        int prevPrime = -999999;
        int minD = right;
        std::vector<int> resp = {-1, -1};

        left = std::max(2, left);
        for (int p = left; p <= right; ++p) {
            if (!isPrime(p))
                continue;
            int d = p - prevPrime;
            if (d < minD) {
                minD = d;
                resp = {prevPrime, p};
                if (d == 2)
                    break;
            }
            prevPrime = p;
        }

        return resp;
    }
};
// @leet end

int main()
{
    Solution{}.closestPrimes(19, 31);
    return 0;
}
