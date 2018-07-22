#!/usr/bin/python3
# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def foo(self, root, res):
        if root.left is not None:
            self.foo(root.left, res)
        if root.right is not None:
            self.foo(root.right, res)
        if root.left is None and root.right is None:
            res.append(root.val)

    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        res1 = []
        res2 = []
        self.foo(root1, res1)
        self.foo(root2, res2)
        return res1 == res2


if __name__ == "__main__":
    t1 = TreeNode(3)
    t1.left = TreeNode(5)
    t1.ritg = TreeNode(1)
    t2 = TreeNode(3)
    t2.left = TreeNode(5)
    t2.ritg = TreeNode(1)
    s = Solution()
    print(s.leafSimilar(t1, t2))
