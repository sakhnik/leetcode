use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn restore_array(adjacent_pairs: Vec<Vec<i32>>) -> Vec<i32> {
        // Collect the neighbours for lookups
        let mut neighbours: HashMap<i32, Vec<i32>> = HashMap::new();
        for p in &adjacent_pairs {
            neighbours.entry(p[0]).or_insert(vec![]).push(p[1]);
            neighbours.entry(p[1]).or_insert(vec![]).push(p[0]);
        }

        // Find an end: just one neighbor
        let (&start, _) = neighbours.iter().find(|(_, v)| v.len() == 1).unwrap();

        // Collect the chain by going through the neighbours
        let mut res = Vec::with_capacity(adjacent_pairs.len() + 1);
        let mut current = start;
        res.push(current);
        loop {
            let ways = &neighbours[&current];
            let next = ways[0];
            if res.len() > 1 && next == res[res.len() - 2] {
                if ways.len() == 1 {
                    break;
                }
                current = ways[1];
            } else {
                current = next;
            }
            res.push(current);
        }

        res
    }
}
