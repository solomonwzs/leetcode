// Definition for a binary tree node.
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

use std::cell::RefCell;
use std::cmp::min;
use std::rc::Rc;

macro_rules! tree_child {
    ($i:ident, $j:ident) => {
        match $i.borrow().$j.as_ref() {
            Some(x) => Some(x.clone()),
            None => None,
        }
    };
}

impl Solution {
    fn cal_monitor_case(root: Option<Rc<RefCell<TreeNode>>>) -> [i32; 3] {
        // case 0: status was valid and camera was installed on root;
        // case 1: status was valid and camera was not installed on root;
        // case 2: left and right subtrees were valid, but root was not;
        match root {
            None => [1001, 0, 0],
            Some(node) => {
                let left_res: [i32; 3] =
                    Solution::cal_monitor_case(tree_child!(node, left));
                let right_res: [i32; 3] =
                    Solution::cal_monitor_case(tree_child!(node, right));

                let res0: i32 = 1
                    + min(min(left_res[0], left_res[1]), left_res[2])
                    + min(min(right_res[0], right_res[1]), right_res[2]);
                let res1: i32 = min(
                    min(left_res[0] + right_res[1], left_res[1] + right_res[0]),
                    left_res[0] + right_res[0],
                );
                let res2: i32 = left_res[1] + right_res[1];
                [res0, res1, res2]
            }
        }
    }

    pub fn min_camera_cover(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let res: [i32; 3] = Solution::cal_monitor_case(root);
        min(res[0], res[1])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works0() {
        let n0 = Rc::new(RefCell::new(TreeNode::new(0)));
        let n1 = Rc::new(RefCell::new(TreeNode::new(1)));
        let n2 = Rc::new(RefCell::new(TreeNode::new(2)));
        let n3 = Rc::new(RefCell::new(TreeNode::new(3)));

        n0.borrow_mut().left = Some(n1.clone());
        n1.borrow_mut().left = Some(n2.clone());
        n1.borrow_mut().right = Some(n3.clone());

        assert_eq!(Solution::min_camera_cover(Some(n0)), 1);
    }

    #[test]
    fn it_works1() {
        let n0 = Rc::new(RefCell::new(TreeNode::new(0)));
        let n1 = Rc::new(RefCell::new(TreeNode::new(1)));
        let n2 = Rc::new(RefCell::new(TreeNode::new(2)));
        let n3 = Rc::new(RefCell::new(TreeNode::new(3)));
        let n4 = Rc::new(RefCell::new(TreeNode::new(4)));

        n0.borrow_mut().left = Some(n1.clone());
        n1.borrow_mut().left = Some(n2.clone());
        n2.borrow_mut().left = Some(n3.clone());
        n3.borrow_mut().left = Some(n4.clone());

        assert_eq!(Solution::min_camera_cover(Some(n0)), 2);
    }
}
