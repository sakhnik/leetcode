impl Solution {
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        // Counting sort
        let mut counts = [0; 100001];
        let (mut min, mut max) = (i32::MAX, i32::MIN);
        for v in nums.into_iter() {
            counts[v as usize] += 1;
            min = min.min(v);
            max = max.max(v);
        }

        let mut max_sum = 0;
        while min < max {
            if counts[min as usize] == 0 {
                min += 1;
            } else if counts[max as usize] == 0 {
                max -= 1;
            } else {
                max_sum = max_sum.max(min + max);
                let c = counts[min].min(counts[max]);
                counts[min] -= c;
                counts[max] -= c;
            }
        }
        if counts[min] > 0 {
            max_sum = max_sum.max(min * 2);
        }

        max_sum       
    }
}
