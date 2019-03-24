pub struct Solution;

impl Solution {
    pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
        if k % 2 == 0 || k % 5 == 0 {
            return -1;
        }

        let mut s: i32 = 1;
        let mut ans: i32 = 1;
        let mut p: i32 = 1;
        loop {
            if s == 0 || s == k {
                return ans;
            } else {
                p = (p * 10) % k;
                s = (s + p) % k;
                ans += 1
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::smallest_repunit_div_by_k(7), 6);
    }
}
