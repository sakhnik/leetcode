use std::collections::HashSet;

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let mut res: i32 = 0;

        const CHAR_COUNT: usize = 'z' as usize - 'a' as usize + 1;

        for ch in 'a'..='z' {
            let first = s.find(ch);
            if first.is_none() {
                continue;
            }
            let mid_begin = first.unwrap() + 1;
            let last = s.rfind(ch).unwrap();
            if mid_begin >= last {
                continue;
            }
            let mut char_set: HashSet<char> = HashSet::new();
            for mid in s[mid_begin..last].chars() {
                char_set.insert(mid);
                if char_set.len() == CHAR_COUNT {
                    break;
                }
            }
            res += char_set.len() as i32;
        }

        res
    }
}
