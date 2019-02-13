pub struct Solution {}

use std::cmp::max;
use std::cmp::min;

impl Solution {
    pub fn tallest_billboard(rods: Vec<i32>) -> i32 {
        let mut sum: usize = 0;
        for rod in rods.iter() {
            sum += *rod as usize;
        }
        let bound: usize = sum * 2 + 1;

        let mut m: Vec<Vec<i32>> = vec![vec![0; bound]; rods.len() + 1];
        let mut dp: Vec<Vec<bool>> = vec![vec![false; bound]; rods.len() + 1];
        dp[0][sum] = true;
        for i in 0..rods.len() {
            for j in 0..bound {
                if j >= rods[i] as usize && dp[i][j - rods[i] as usize] {
                    dp[i + 1][j] = true;
                    m[i + 1][j] =
                        max(m[i + 1][j], m[i][j - rods[i] as usize] + rods[i]);
                }

                if bound > j + rods[i] as usize && dp[i][j + rods[i] as usize] {
                    dp[i + 1][j] = true;
                    m[i + 1][j] = max(m[i + 1][j], m[i][j + rods[i] as usize]);
                }

                if dp[i][j] {
                    dp[i + 1][j] = true;
                    m[i + 1][j] = max(m[i + 1][j], m[i][j]);
                }
            }
        }
        m[rods.len()][sum]
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn tallest_billboard_v2(rods: Vec<i32>) -> i32 {
        let mut dp: HashMap<i32, i32> = HashMap::new();
        dp.insert(0, 0);
        for rod in rods.iter() {
            let mut cur: HashMap<i32, i32> = HashMap::new();
            for (k, v) in &dp {
                cur.insert(*k, *v);
            }

            for (r, d) in &cur {
                let tmp0: i32 = match dp.get(&(r + rod)) {
                    Some(val) => *val,
                    None => 0,
                };
                dp.insert(r + rod, max(*d, tmp0));

                let tmp1: i32 = match dp.get(&i32::abs(r - rod)) {
                    Some(val) => *val,
                    None => 0,
                };
                dp.insert(i32::abs(r - rod), max(d + min(r, rod), tmp1));
            }
        }
        match dp.get(&0) {
            Some(val) => *val,
            None => 0,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        println!(">>>");
        assert_eq!(Solution::tallest_billboard(vec!(1, 2, 3, 6)), 6);
    }

    #[test]
    fn it_works_v2() {
        println!(">>>");
        assert_eq!(Solution::tallest_billboard_v2(vec!(1, 2, 3, 6)), 6);
    }
}
