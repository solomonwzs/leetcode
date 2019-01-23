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

impl Solution {
    fn move_coins(root: Option<Rc<RefCell<TreeNode>>>, mov: &mut i32) {
        if let Some(node) = root {
            let mut val: i32 = node.borrow().val;

            if let Some(left) = node.borrow().left.as_ref() {
                Solution::move_coins(Some(left.clone()), mov);
                let cval: i32 = left.borrow().val;
                if cval > 1 {
                    *mov += cval - 1;
                    val += cval - 1;
                } else {
                    *mov += 1 - cval;
                    val -= 1 - cval;
                }
            }

            if let Some(right) = node.borrow().right.as_ref() {
                Solution::move_coins(Some(right.clone()), mov);
                let cval: i32 = right.borrow().val;
                if cval > 1 {
                    *mov += cval - 1;
                    val += cval - 1;
                } else {
                    *mov += 1 - cval;
                    val -= 1 - cval;
                }
            }

            node.borrow_mut().val = val;
        }
    }

    pub fn distribute_coins(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root == None {
            return 0;
        }
        let mut mov: i32 = 0;
        Solution::move_coins(root, &mut mov);
        mov
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn it_work0() {
        let n0 = Rc::new(RefCell::new(TreeNode::new(1)));
        let n1 = Rc::new(RefCell::new(TreeNode::new(0)));
        let n2 = Rc::new(RefCell::new(TreeNode::new(0)));
        let n3 = Rc::new(RefCell::new(TreeNode::new(3)));

        n0.borrow_mut().left = Some(n1.clone());
        n0.borrow_mut().right = Some(n2.clone());
        n1.borrow_mut().right = Some(n3.clone());

        assert_eq!(Solution::distribute_coins(Some(n0)), 4);
    }

    #[test]
    fn it_work1() {
        let n0 = Rc::new(RefCell::new(TreeNode::new(3)));
        let n1 = Rc::new(RefCell::new(TreeNode::new(0)));
        let n2 = Rc::new(RefCell::new(TreeNode::new(0)));
        let n3 = Rc::new(RefCell::new(TreeNode::new(0)));
        let n4 = Rc::new(RefCell::new(TreeNode::new(2)));

        n0.borrow_mut().right = Some(n1.clone());
        n1.borrow_mut().left = Some(n2.clone());
        n2.borrow_mut().left = Some(n3.clone());
        n3.borrow_mut().left = Some(n4.clone());

        assert_eq!(Solution::distribute_coins(Some(n0)), 4);
    }
}
