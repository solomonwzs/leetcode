/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-24
 * @license MIT
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func tree2list(root *TreeNode) []int {
	if root == nil {
		return make([]int, 0)
	}
	left := tree2list(root.Left)
	right := tree2list(root.Right)

	ans := make([]int, 0, len(left)+1+len(right))
	ans = append(ans, left...)
	ans = append(ans, root.Val)
	ans = append(ans, right...)
	return ans
}

func list2Tree(list []int) *TreeNode {
	if len(list) == 0 {
		return nil
	}

	max := -1
	idx := -1
	for i, x := range list {
		if x > max {
			idx = i
			max = x
		}
	}

	return &TreeNode{
		Val:   max,
		Left:  list2Tree(list[:idx]),
		Right: list2Tree(list[idx+1:]),
	}
}

func insertIntoMaxTree(root *TreeNode, val int) *TreeNode {
	a := tree2list(root)
	a = append(a, val)

	tree := list2Tree(a)
	return tree
}
