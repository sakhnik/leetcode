impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        // The string must be different in at least one position
        let mut res = String::new();

        for i in 0..nums.len() {
            res.push(('0' as u8 + ('1' as u8 - nums[i].as_bytes()[i])) as char);
        }

        res       
    }
}
