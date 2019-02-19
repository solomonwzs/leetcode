pub struct Solution {}

use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

static PRIMES: &'static [i32] = &[
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
    157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
    239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
];

struct CompMeta {
    pub count: i32,
    pub rank: i32,
    pub parent: Option<Rc<RefCell<CompMeta>>>,
}

struct CompMetaRef(Rc<RefCell<CompMeta>>);

impl CompMetaRef {
    pub fn new() -> CompMetaRef {
        CompMetaRef(Rc::new(RefCell::new(CompMeta {
            count: 0,
            rank: 0,
            parent: None,
        })))
    }

    pub fn get_parent(&self) -> CompMetaRef {
        let mut p: Rc<RefCell<CompMeta>> = self.0.clone();
        loop {
            match p.clone().borrow().parent.as_ref() {
                None => return CompMetaRef(p.clone()),
                Some(x) => p = x.clone(),
            }
        }
    }
}

impl Solution {
    pub fn largest_component_size(a: Vec<i32>) -> i32 {
        if a.len() <= 1 {
            return 1;
        }

        let mut pl: Vec<Vec<i32>> = vec![Vec::new(); a.len()];
        let mut comps: HashMap<i32, CompMetaRef> = HashMap::new();
        for i in 0..a.len() {
            let mut x: i32 = a[i];
            let mut j: usize = 0;
            while j < PRIMES.len() && PRIMES[j] < x {
                if x % PRIMES[j] == 0 {
                    if pl[i].len() == 0 || pl[i][pl[i].len() - 1] != PRIMES[j] {
                        if !comps.contains_key(&PRIMES[j]) {
                            comps.insert(PRIMES[j], CompMetaRef::new());
                        }
                        pl[i].push(PRIMES[j]);
                    }
                    x /= PRIMES[j];
                } else {
                    j += 1;
                }
            }

            if x != 1 {
                if !comps.contains_key(&x) {
                    comps.insert(x, CompMetaRef::new());
                }
                pl[i].push(x);
            }
        }

        let mut ans: i32 = 1;
        for i in 0..pl.len() {
            if pl[i].len() == 0 {
                continue;
            }

            if let Some(m) = comps.get(&pl[i][0]) {
                let mut meta: CompMetaRef = m.get_parent();
                meta.0.borrow_mut().count += 1;
                for j in 1..pl[i].len() {
                    if let Some(mx) = comps.get(&pl[i][j]) {
                        let metax: CompMetaRef = mx.get_parent();
                        let mut swap: bool = false;
                        if !Rc::ptr_eq(&meta.0, &metax.0) {
                            let mut m0 = meta.0.borrow_mut();
                            let mut m1 = metax.0.borrow_mut();
                            if m0.rank > m1.rank {
                                m1.parent = Some(meta.0.clone());
                                m0.count += m1.count;
                            } else {
                                m0.parent = Some(metax.0.clone());
                                m1.count += m0.count;
                                if m0.rank == m1.rank {
                                    m1.rank += 1;
                                }
                                swap = true;
                            }
                        }
                        if swap {
                            meta = CompMetaRef(metax.0.clone());
                        }
                    }
                }
                if meta.0.borrow().count > ans {
                    ans = meta.0.borrow().count;
                }
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::largest_component_size(vec![4, 6, 15, 35]), 4);
    }

    #[test]
    fn it_works1() {
        assert_eq!(Solution::largest_component_size(vec![20, 50, 9, 63]), 2);
    }
}
