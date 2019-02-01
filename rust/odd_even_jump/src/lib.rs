pub struct Solution;

use std::collections::BTreeMap;
use std::ops::Bound::*;

impl Solution {
    pub fn odd_even_jumps(a: Vec<i32>) -> i32 {
        let n: usize = a.len();
        if n == 0 {
            return 0;
        }

        let mut higher: Vec<bool> = vec![false; n];
        let mut lower: Vec<bool> = vec![false; n];
        let mut ordlist: BTreeMap<i32, usize> = BTreeMap::new();

        higher[n - 1] = true;
        lower[n - 1] = true;
        ordlist.insert(a[n - 1], n - 1);

        let mut res: i32 = 1;
        for i in (0..n - 1).rev() {
            if let Some(hi) = ordlist.range((Included(&a[i]), Unbounded)).next()
            {
                higher[i] = lower[*hi.1];
            }
            if let Some(lo) =
                ordlist.range((Unbounded, Included(&a[i]))).rev().next()
            {
                lower[i] = higher[*lo.1];
            }
            ordlist.insert(a[i], i);

            if higher[i] {
                res += 1;
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works0() {
        let a = vec![10, 13, 12, 14, 15];
        println!(">>> {:?}", a);
        assert_eq!(Solution::odd_even_jumps(a), 2);
    }

    #[test]
    fn it_works1() {
        let a = vec![2, 3, 1, 1, 4];
        println!(">>> {:?}", a);
        assert_eq!(Solution::odd_even_jumps(a), 3);
    }

    #[test]
    fn it_works2() {
        let a = vec![1, 2, 3, 2, 1, 4, 4, 5];
        println!(">>> {:?}", a);
        assert_eq!(Solution::odd_even_jumps(a), 6);
    }
}
