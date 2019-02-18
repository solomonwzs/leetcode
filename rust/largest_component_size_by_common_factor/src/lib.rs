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
    pub id: i32,
    pub count: i32,
    pub rank: i32,
    pub parent: Option<Rc<RefCell<CompMeta>>>,
}

struct CompMetaRef(Rc<RefCell<CompMeta>>);

impl CompMetaRef {
    pub fn new(id: i32) -> CompMetaRef {
        CompMetaRef(Rc::new(RefCell::new(CompMeta {
            id: id,
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
                            comps
                                .insert(PRIMES[j], CompMetaRef::new(PRIMES[j]));
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
                    comps.insert(x, CompMetaRef::new(x));
                }
                pl[i].push(x);
            }
        }

        let mut ans: i32 = 1;
        for i in 0..pl.len() {
            if pl[i].len() == 0 {
                continue;
            }

            if let Some(meta) = comps.get(&pl[i][0]) {
                meta.0.borrow_mut().count += 1;
                for j in 1..pl[i].len() {
                    if let Some(meta1) = comps.get(&pl[i][j]) {
                        if meta1.0.borrow().id != meta.0.borrow().id {
                        }
                    }
                }
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
