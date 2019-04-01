pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }

    pub fn new_list(l: Vec<i32>) -> Option<Box<ListNode>> {
        if let Some((head, tail)) = l.split_first() {
            let mut node: ListNode = ListNode::new(*head);
            node.next = ListNode::new_list(tail.to_vec());
            return Some(Box::new(node));
        }
        return None;
    }
}

pub struct Solution;

impl Solution {
    pub fn next_larger_nodes(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut h: &Option<Box<ListNode>> = &head;
        let mut ans: Vec<i32> = Vec::new();
        let mut stack: Vec<(usize, i32)> = Vec::new();
        while let Some(x) = h {
            h = &x.next;

            ans.push(0);
            while stack.len() > 0 && stack[stack.len() - 1].1 < x.val {
                if let Some(e) = stack.pop() {
                    ans[e.0] = x.val;
                }
            }
            stack.push((ans.len() - 1, x.val));
        }
        return ans;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(
            Solution::next_larger_nodes(ListNode::new_list(vec![
                2, 7, 4, 3, 5
            ])),
            vec![7, 0, 5, 5, 0]
        );
    }

    #[test]
    fn it_works1() {
        assert_eq!(
            Solution::next_larger_nodes(ListNode::new_list(vec![
                1, 7, 5, 1, 9, 2, 5, 1
            ])),
            vec![7, 9, 9, 9, 0, 5, 0, 0]
        );
    }
}
