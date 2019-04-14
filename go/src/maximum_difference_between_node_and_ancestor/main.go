/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package maximum_difference_between_node_and_ancestor

import (
	. "tree_node"
)

type mTreeNode struct {
	val   int
	max   int
	min   int
	ans   int
	left  *mTreeNode
	right *mTreeNode
}

func abs(a, b int) int {
	if a > b {
		return a - b
	} else {
		return b - a
	}
}

func min(a ...int) int {
	m := a[0]
	for i := 1; i < len(a); i++ {
		if m > a[i] {
			m = a[i]
		}
	}
	return m
}

func max(a ...int) int {
	m := a[0]
	for i := 1; i < len(a); i++ {
		if m < a[i] {
			m = a[i]
		}
	}
	return m
}

func recursive(n *TreeNode) (m *mTreeNode) {
	m = &mTreeNode{
		val:   n.Val,
		max:   n.Val,
		min:   n.Val,
		ans:   0,
		left:  nil,
		right: nil,
	}

	if n.Left == nil && n.Right == nil {
		return
	}

	if n.Left != nil {
		m.left = recursive(n.Left)
		m.max = max(m.max, m.left.max)
		m.min = min(m.min, m.left.min)
		m.ans = max(
			m.ans,
			m.left.ans,
			abs(m.val, m.left.min),
			abs(m.val, m.left.max),
		)
	}
	if n.Right != nil {
		m.right = recursive(n.Right)
		m.max = max(m.max, m.right.max)
		m.min = min(m.min, m.right.min)
		m.ans = max(
			m.ans,
			m.right.ans,
			abs(m.val, m.right.min),
			abs(m.val, m.right.max),
		)
	}
	return
}

func maxAncestorDiff(root *TreeNode) int {
	m := recursive(root)
	return m.ans
}
