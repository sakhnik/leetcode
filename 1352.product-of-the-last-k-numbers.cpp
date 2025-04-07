#include <vector>

using namespace std;

// @leet start
class ProductOfNumbers {
public:
    std::vector<int> prods = {1};

    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (!num) {
            prods.erase(prods.begin() + 1, prods.end());
        } else {
            prods.push_back(prods.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prods.size())
            return 0;
        return prods.back() / prods[prods.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @leet end
