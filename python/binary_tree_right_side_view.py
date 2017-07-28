#!/usr/bin/python2
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"

from leetcode import TreeNode


class Solution:
    def rightSideView(self, root):
        if root==None:
            return []

        rsv=[]
        curLevel=[root]
        while len(curLevel)!=0:
            rsv.append(curLevel[-1].val)
            nextLevel=[]
            for node in curLevel:
                if node.left!=None:
                    nextLevel.append(node.left)

                if node.right!=None:
                    nextLevel.append(node.right)

            curLevel=nextLevel

        return rsv



if __name__=="__main__":
    nodes=[]
    for i in range(5):
        nodes.append(TreeNode(i+1))
    nodes[0].left=nodes[1]
    nodes[0].right=nodes[2]
    nodes[1].right=nodes[4]
    nodes[2].right=nodes[3]

    s=Solution()
    print s.rightSideView(nodes[0])
