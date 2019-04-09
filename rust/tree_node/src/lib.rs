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

    pub fn build_tree(s: &str) -> Option<Rc<RefCell<Self>>> {
        let vals: Vec<&str> = s.split(',').collect();
        if vals.len() == 0 {
            return None;
        }

        let mut list: Vec<Rc<RefCell<Self>>> = Vec::with_capacity(vals.len());
        let val: i32 = vals[0].to_string().parse::<i32>().unwrap();
        let root: Rc<RefCell<Self>> = Rc::new(RefCell::new(TreeNode::new(val)));
        list.push(root.clone());

        let mut p: usize = 0;
        for i in 1..vals.len() {
            if vals[i] != "null" {
                let val: i32 = vals[i].to_string().parse::<i32>().unwrap();
                let node: Rc<RefCell<Self>> =
                    Rc::new(RefCell::new(TreeNode::new(val)));

                let parent: Rc<RefCell<Self>> = list[p / 2].clone();
                if p % 2 == 0 {
                    parent.borrow_mut().left = Some(node.clone());
                } else {
                    parent.borrow_mut().right = Some(node.clone());
                }
                list.push(node);
            }
            p += 1;
        }
        return Some(root);
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
