use std::cell::RefCell;
use std::fmt::Display;
use std::fmt::Formatter;
use std::fmt::Result;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl Display for TreeNode {
    fn fmt(&self, f: &mut Formatter) -> Result {
        write!(f, "{}", self.to_string())
    }
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

    pub fn to_string(&self) -> String {
        let root: Option<Rc<RefCell<TreeNode>>> =
            Some(Rc::new(RefCell::new(TreeNode {
                val: self.val,
                left: match &self.left {
                    Some(x) => Some(x.clone()),
                    None => None,
                },
                right: match &self.right {
                    Some(x) => Some(x.clone()),
                    None => None,
                },
            })));
        let mut list: Vec<Option<Rc<RefCell<TreeNode>>>> = vec![root];
        let mut i: usize = 0;
        while i < list.len() {
            let mut is_none: bool = true;
            let mut left: Option<Rc<RefCell<TreeNode>>> = None;
            let mut right: Option<Rc<RefCell<TreeNode>>> = None;
            if let Some(n) = &list[i] {
                is_none = false;
                if let Some(x) = &n.borrow().left {
                    left = Some(x.clone())
                }
                if let Some(x) = &n.borrow().right {
                    right = Some(x.clone())
                }
            }
            if !is_none {
                list.push(left);
                list.push(right);
            }
            i += 1;
        }

        loop {
            if let Some(_) = &list[i - 1] {
                break;
            }
            list.pop();
            i -= 1;
        }

        let mut s: String = String::new();
        for i in 0..list.len() {
            if i != 0 {
                s.push_str(",");
            }
            match &list[i] {
                Some(n) => s.push_str(n.borrow().val.to_string().as_str()),
                None => s.push_str("null"),
            }
        }
        return s;
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
    use super::*;

    #[test]
    fn it_works() {
        let root = TreeNode::build_tree("1,2,null,3,null,4,null,null,5");
        if let Some(n) = &root {
            println!("{}", n.as_ref().borrow())
        }
    }
}
