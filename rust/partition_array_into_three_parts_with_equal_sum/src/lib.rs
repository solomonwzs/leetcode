pub struct Solution;

impl Solution {
    pub fn can_three_parts_equal_sum(a: Vec<i32>) -> bool {
        let mut sum: i32 = 0;
        for i in &a {
            sum += i;
        }
        if sum % 3 != 0 {
            return false;
        }

        let avg: i32 = sum / 3;
        let mut tmp: i32 = 0;
        let mut ok: i32 = 0;
        for i in &a {
            tmp +=i;
            if tmp == avg {
                ok += 1;
                tmp = 0;
            }
        }
        return ok == 3;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(
            Solution::can_three_parts_equal_sum(vec![
                0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1
            ]),
            true
        );
    }

    #[test]
    fn it_works1() {
        assert_eq!(
            Solution::can_three_parts_equal_sum(vec![
                0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1
            ]),
            false
        );
    }

    #[test]
    fn it_works2() {
        assert_eq!(
            Solution::can_three_parts_equal_sum(vec![
                3, 3, 6, 5, -2, 2, 5, 1, -9, 4
            ]),
            true
        );
    }
}
