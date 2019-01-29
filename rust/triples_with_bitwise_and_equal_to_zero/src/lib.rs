pub struct Solution {}

use std::collections::HashMap;

impl Solution {
    pub fn count_triplets(a: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for x in &a {
            for y in &a {
                let k: i32 = x & y;
                let s: &mut i32 = cnt.entry(k).or_insert(0);
                *s += 1;
            }
        }
        let mut res: i32 = 0;
        for (k, s) in &cnt {
            for z in &a {
                if k & z == 0 {
                    res += s;
                }
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let a: Vec<i32> = vec![2, 1, 3];
        assert_eq!(Solution::count_triplets(a), 12);
    }
}
