
// @leet start
use std::cmp;

impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let mut max_sum = 0;
        let mut sum = nums[0];
        for i in 1 .. nums.len() {
            if nums[i] > nums[i - 1] {
                sum += nums[i];
            } else {
                max_sum = cmp::max(max_sum, sum);
                sum = nums[i];
            }
        }
        cmp::max(max_sum, sum)
    }
}
// @leet end
