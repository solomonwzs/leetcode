// Definition for an interval.
#[derive(Debug, PartialEq, Eq)]
pub struct Interval {
    pub start: i32,
    pub end: i32,
}

impl Interval {
    #[inline]
    pub fn new(start: i32, end: i32) -> Self {
        Interval { start, end }
    }
}

pub struct Solution {}

impl Solution {
    pub fn insert(
        intervals: Vec<Interval>,
        new_interval: Interval,
    ) -> Vec<Interval> {
        let mut result: Vec<Interval> = Vec::new();

        let mut i = 0;
        while i < intervals.len() && intervals[i].end < new_interval.start {
            let x = &intervals[i];
            result.push(Interval::new(x.start, x.end));
            i += 1;
        }

        let mut start = new_interval.start;
        let mut end = new_interval.end;
        while i < intervals.len() && intervals[i].start <= new_interval.end {
            let x = &intervals[i];
            if x.start < start {
                start = x.start;
            }
            if x.end > end {
                end = x.end;
            }
            i += 1;
        }
        result.push(Interval::new(start, end));

        while i < intervals.len() {
            let x = &intervals[i];
            result.push(Interval::new(x.start, x.end));
            i += 1;
        }

        result
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn it_work0() {
        let intervals = vec![Interval::new(1, 3), Interval::new(6, 9)];
        let new_interval = Interval::new(2, 5);
        println!("{:?}", Solution::insert(intervals, new_interval));
    }

    #[test]
    fn it_work1() {
        let intervals = vec![
            Interval::new(1, 2),
            Interval::new(3, 5),
            Interval::new(6, 7),
            Interval::new(8, 10),
            Interval::new(12, 16),
        ];
        let new_interval = Interval::new(4, 8);
        println!("{:?}", Solution::insert(intervals, new_interval));
    }
}
