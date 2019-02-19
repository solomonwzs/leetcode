pub struct Solution {}

use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    fn is_square(a: &i32, b: &i32) -> bool {
        let x: i32 = ((a + b) as f64).sqrt() as i32;
        x * x == a + b
    }

    fn dfs(
        side: &HashMap<i32, HashSet<i32>>,
        num_cnt: &mut HashMap<i32, i32>,
        n: usize,
        path: &mut Vec<i32>,
        ans: &mut i32,
    ) {
        let len: usize = path.len();
        if len == n {
            *ans += 1;
        } else {
            let last: i32 = path[len - 1];
            if let Some(sets) = side.get(&last) {
                for next in sets {
                    let cnt: i32 = *num_cnt.entry(*next).or_insert(0);
                    if cnt == 0 {
                        continue;
                    }

                    path.push(*next);
                    num_cnt.insert(*next, cnt - 1);
                    Solution::dfs(side, num_cnt, n, path, ans);
                    num_cnt.insert(*next, cnt);
                    path.pop();
                }
            }
        }
    }

    pub fn num_squareful_perms(a: Vec<i32>) -> i32 {
        let mut side: HashMap<i32, HashSet<i32>> = HashMap::new();
        let mut num_cnt: HashMap<i32, i32> = HashMap::new();
        for x in &a {
            if !side.contains_key(x) {
                side.insert(*x, HashSet::new());
            }
            let cnt: &mut i32 = num_cnt.entry(*x).or_insert(0);
            *cnt += 1;
        }

        for i in 0..(a.len() - 1) {
            for j in (i + 1)..a.len() {
                if Solution::is_square(&a[i], &a[j]) {
                    side.entry(a[i]).and_modify(|sets| {
                        sets.insert(a[j]);
                    });
                    side.entry(a[j]).and_modify(|sets| {
                        sets.insert(a[i]);
                    });
                }
            }
        }

        let mut path: Vec<i32> = Vec::new();
        let mut ans: i32 = 0;
        for (x, _) in &side {
            path.push(*x);
            num_cnt.entry(*x).and_modify(|e| *e -= 1);
            Solution::dfs(&side, &mut num_cnt, a.len(), &mut path, &mut ans);
            num_cnt.entry(*x).and_modify(|e| *e += 1);
            path.pop();
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let a: Vec<i32> = vec![1, 17, 8];
        assert_eq!(Solution::num_squareful_perms(a), 2);
    }

    #[test]
    fn it_works1() {
        let a: Vec<i32> = vec![0, 0, 0, 1, 1, 1];
        assert_eq!(Solution::num_squareful_perms(a), 4);
    }
}
