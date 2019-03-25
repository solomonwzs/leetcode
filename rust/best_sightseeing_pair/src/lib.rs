pub struct Solution;

use std::collections::BTreeMap;

impl Solution {
    pub fn max_score_sightseeing_pair_old(a0: Vec<i32>) -> i32 {
        let mut a: Vec<i32> = vec![0; a0.len()];
        for i in 0..a.len() {
            a[i] = a0[i] - (i as i32)
        }

        let mut m: BTreeMap<i32, i32> = BTreeMap::new();
        for i in &a {
            m.entry(*i).and_modify(|cnt| *cnt += 1).or_insert(1);
        }

        let mut ans: i32 = 0;
        for i in 0..a.len() {
            let x: i32 = a[i];
            if let Some(cnt) = m.get(&x) {
                if *cnt == 1 {
                    m.remove(&x);
                } else {
                    m.insert(x, cnt - 1);
                }
            }

            if let Some(p) = m.iter().rev().next() {
                let tmp: i32 = x + p.0 + (i as i32) * 2;
                if tmp > ans {
                    ans = tmp;
                }
            }
        }
        return ans;
    }
}

use std::cmp;

impl Solution {
    pub fn max_score_sightseeing_pair(a: Vec<i32>) -> i32 {
        let mut ans: i32 = 0;
        let mut cur: i32 = 0;
        for i in &a {
            ans = cmp::max(ans, cur + *i);
            cur = cmp::max(cur, *i) -1;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(
            Solution::max_score_sightseeing_pair(vec![2, 8, 1, 5, 2, 6]),
            11
        );
    }
}
