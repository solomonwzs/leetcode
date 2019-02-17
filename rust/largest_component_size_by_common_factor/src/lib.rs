pub struct Solution {}

use std::cell::RefCell;
use std::rc::Rc;

struct CompMeta {
    pub count: i32,
    pub rank: i32,
    pub parent: Option<Rc<RefCell<CompMeta>>>,
}

struct CompMetaRef (Rc<RefCell<CompMeta>>);

impl CompMeta {
    pub fn get_parent(&self) {
        match self.parent {
            None => self
        }
    }
}

impl Solution {
    pub fn largest_component_size(a: Vec<i32>) -> i32 {
        1
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
