use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

pub struct Solution {}

macro_rules! try_opt {
    ($expr: expr) => {
        match $expr {
            Some(value) => value,
            None => return None,
        }
    };
}

impl Solution {
    fn move_coins(root: Option<Rc<RefCell<TreeNode>>>, mov: &mut i32) -> i32 {
        match root {
            None => return 0,
            Some(x) => {
                let rn = x.borrow();
                let mut val: i32 = x.borrow().val;

                0
            }
        }
    }

    pub fn distribute_coins(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root == None {
            return 0;
        }

        let mut mov: i32 = 0;
        0
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn it_work0() {
        let mut n0 = TreeNode::new(1);
        let mut n1 = TreeNode::new(0);
        let n2 = TreeNode::new(0);
        let n3 = TreeNode::new(3);

        n0.left = Some(Rc::new(RefCell::new(n1)));
        n0.right = Some(Rc::new(RefCell::new(n2)));
        n1.right = Some(Rc::new(RefCell::new(n3)));

        let root = Some(Rc::new(RefCell::new(n0)));
        println!("{}", Solution::distribute_coins(root));
    }
}
