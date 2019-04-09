extern crate tree_node;

use std::cell::RefCell;
use std::rc::Rc;
use tree_node::TreeNode;

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
        let root = TreeNode::build_tree("1,0,0,null,3");
        assert_eq!(Solution::distribute_coins(root), 4);
    }

    #[test]
    fn it_work1() {
        let root = TreeNode::build_tree("3,null,0,0,null,0,null,2");
        assert_eq!(Solution::distribute_coins(root), 4);
    }
}
