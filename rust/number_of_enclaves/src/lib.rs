pub struct Solution;

static DIRECTIONS: &'static [(i32, i32)] = &[(-1, 0), (0, -1), (1, 0), (0, 1)];
static LAND: i32 = 1;
static MARK_LAND: i32 = 2;

impl Solution {
    pub fn num_enclaves(a0: Vec<Vec<i32>>) -> i32 {
        let len_i: i32 = a0.len() as i32;
        let len_j: i32 = a0[0].len() as i32;

        let mut a: Vec<Vec<i32>> = Vec::with_capacity(len_i as usize);
        for i in 0..len_i as usize {
            a.push(Vec::with_capacity(len_j as usize));
            for j in 0..a0[0].len() {
                a[i].push(a0[i][j]);
            }
        }

        let mut ans: i32 = 0;
        for i in 0..len_i as usize {
            for j in 0..len_j as usize {
                if a[i][j] == LAND {
                    a[i][j] = MARK_LAND;
                    let mut list: Vec<(i32, i32)> = vec![(i as i32, j as i32)];
                    let mut k: usize = 0;
                    let mut enclosed: bool = i == 0
                        || i == (len_i - 1) as usize
                        || j == 0
                        || j == (len_j - 1) as usize;
                    while k < list.len() {
                        let (x, y) = list[k];
                        for (x0, y0) in DIRECTIONS {
                            let x1: i32 = x + x0;
                            let y1: i32 = y + y0;
                            if 0 <= x1
                                && x1 < len_i
                                && 0 <= y1
                                && y1 < len_j
                                && a[x1 as usize][y1 as usize] == LAND
                            {
                                enclosed = enclosed
                                    || x1 == 0
                                    || x1 == len_i - 1
                                    || y1 == 0
                                    || y1 == len_j - 1;
                                a[x1 as usize][y1 as usize] = MARK_LAND;
                                list.push((x1, y1));
                            }
                        }
                        k += 1;
                    }
                    if !enclosed {
                        ans += list.len() as i32;
                    }
                }
            }
        }
        return ans;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let a: Vec<Vec<i32>> = vec![
            vec![0, 0, 0, 0],
            vec![1, 0, 1, 0],
            vec![0, 1, 1, 0],
            vec![0, 0, 0, 0],
        ];
        assert_eq!(Solution::num_enclaves(a), 3);
    }

    #[test]
    fn it_works1() {
        let a: Vec<Vec<i32>> = vec![
            vec![0, 1, 1, 0],
            vec![0, 0, 1, 0],
            vec![0, 0, 1, 0],
            vec![0, 0, 0, 0],
        ];
        assert_eq!(Solution::num_enclaves(a), 0);
    }

    #[test]
    fn it_works2() {
        let a: Vec<Vec<i32>> = vec![
            vec![0, 0, 0, 1, 1, 1, 0, 1, 0, 0],
            vec![1, 1, 0, 0, 0, 1, 0, 1, 1, 1],
            vec![0, 0, 0, 1, 1, 1, 0, 1, 0, 0],
            vec![0, 1, 1, 0, 0, 0, 1, 0, 1, 0],
            vec![0, 1, 1, 1, 1, 1, 0, 0, 1, 0],
            vec![0, 0, 1, 0, 1, 1, 1, 1, 0, 1],
            vec![0, 1, 1, 0, 0, 0, 1, 1, 1, 1],
            vec![0, 0, 1, 0, 0, 1, 0, 1, 0, 1],
            vec![1, 0, 1, 0, 1, 1, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 1, 1, 0, 0, 0, 1],
        ];
        assert_eq!(Solution::num_enclaves(a), 3);
    }

    #[test]
    fn it_works3() {
        let a: Vec<Vec<i32>> = vec![
            vec![0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0],
            vec![1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1],
            vec![1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1],
            vec![1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0],
            vec![1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1],
            vec![1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0],
            vec![0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0],
            vec![0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0],
            vec![1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
            vec![1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0],
        ];
        assert_eq!(Solution::num_enclaves(a), 27);
    }
}
