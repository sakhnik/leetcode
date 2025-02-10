// @leet start
use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut products = HashMap::new();
        for i in 1 .. nums.len() {
            for j in 0 .. i {
                products.entry(nums[i] * nums[j]).and_modify(|c| *c += 1).or_insert(1);
            }
        }
        let mut count = 0;
        products.iter().for_each(|(&p, &c)| {
            count += 4 * c * (c - 1);
        });
        count
    }
}
// @leet end
