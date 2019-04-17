extern crate tree_node;

use tree_node::TreeNode;

pub struct Solution {}

use std::cell::RefCell;
use std::rc::Rc;

struct Node {
    value: i32,
    depth: i32,
}

struct StackElem<'a> {
    n: &'a Node,
    tn: Rc<RefCell<TreeNode>>,
}

impl Solution {
    pub fn recover_from_preorder(s: String) -> Option<Rc<RefCell<TreeNode>>> {
        let mut plist: Vec<Node> = Vec::new();
        let mut depth: i32 = 0;
        let mut value: i32 = 0;
        let mut is_digital: bool = false;
        for ch in s.chars() {
            if is_digital {
                if ch == '-' {
                    plist.push(Node { value, depth });
                    is_digital = false;
                    depth = 1;
                } else {
                    value = value * 10 + ch as i32 - '0' as i32;
                }
            } else {
                if ch == '-' {
                    depth += 1;
                } else {
                    is_digital = true;
                    value = ch as i32 - '0' as i32;
                }
            }
        }
        plist.push(Node { value, depth });

        let root: Rc<RefCell<TreeNode>> =
            Rc::new(RefCell::new(TreeNode::new(plist[0].value)));
        let mut stack: Vec<StackElem> = Vec::with_capacity(plist.len());
        for n in &plist {
            if stack.len() == 0 {
                stack.push(StackElem {
                    n: &plist[0],
                    tn: root.clone(),
                });
                continue;
            }

            while stack.len() > 0
                && stack[stack.len() - 1].n.depth + 1 != n.depth
            {
                stack.pop();
            }

            let top: usize = stack.len() - 1;
            let tn: Rc<RefCell<TreeNode>> =
                Rc::new(RefCell::new(TreeNode::new(n.value)));
            if stack[top].tn.as_ref().borrow().left == None {
                stack[top].tn.as_ref().borrow_mut().left = Some(tn.clone());
                stack.push(StackElem {
                    n: n,
                    tn: tn.clone(),
                });
            } else if stack[top].tn.as_ref().borrow().right == None {
                stack[top].tn.as_ref().borrow_mut().right = Some(tn.clone());
                stack.pop();
                stack.push(StackElem {
                    n: n,
                    tn: tn.clone(),
                });
            }
        }

        return Some(root);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let root =
            Solution::recover_from_preorder(String::from("1-2--3--4-5--6--7"));
        if let Some(n) = &root {
            assert_eq!(n.as_ref().borrow().to_string(), "1,2,5,3,4,6,7");
        }
    }

    #[test]
    fn it_works1() {
        let root = Solution::recover_from_preorder(String::from(
            "1-2--3---4-5--6---7",
        ));
        if let Some(n) = &root {
            assert_eq!(
                n.as_ref().borrow().to_string(),
                "1,2,5,3,null,6,null,4,null,7"
            );
        }
    }
}
