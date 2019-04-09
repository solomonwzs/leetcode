pub struct Solution {}

impl Solution {
    pub fn max_turbulence_size(a: Vec<i32>) -> i32 {
        if a.len() == 0 {
            return 0;
        }

        let mut max: i32 = 1;
        let mut cur: i32 = 1;
        let mut less: bool = true;
        for i in 1..a.len() {
            if a[i - 1] == a[i] {
                if cur > max {
                    max = cur;
                }
                cur = 1;
            } else if cur == 1 {
                less = a[i - 1] < a[i];
                cur += 1;
            } else {
                if less == !(a[i - 1] < a[i]) {
                    cur += 1;
                } else {
                    if cur > max {
                        max = cur;
                    }
                    cur = 2;
                }
                less = a[i - 1] < a[i];
            }
        }
        if cur > max {
            max = cur;
        }

        max
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn it_work0() {
        println!(
            "{}",
            Solution::max_turbulence_size(vec![9, 4, 2, 10, 7, 8, 8, 1, 9])
        )
    }

    #[test]
    fn it_work1() {
        println!("{}", Solution::max_turbulence_size(vec![4, 8, 12, 16]))
    }

    #[test]
    fn it_work2() {
        println!("{}", Solution::max_turbulence_size(vec![8, 8, 9, 10, 6, 8, 2, 4, 2, 2, 10, 6, 6, 10, 10, 2, 3, 5, 1, 2, 10, 4, 2, 0, 9, 4, 9, 3, 0, 6, 3, 2, 3, 10, 10, 6, 4, 6, 4, 4, 2, 5, 1, 4, 1, 1, 9, 8, 9, 5, 3, 5, 5, 4, 5, 5, 6, 5, 3, 3, 7, 2, 0, 10, 9, 7, 7, 3, 5, 1, 0, 9, 6, 3, 1, 3, 4, 4, 3, 6, 3, 2, 1, 4, 10, 2, 3, 4, 4, 3, 6, 7, 6, 2, 1, 7, 0, 6, 8, 10]))
    }
}
