package main

import (
	"testing"
)

func TestDist(t *testing.T) {
	n0 := &TreeNode{Val: 1}
	n1 := &TreeNode{Val: 0}
	n2 := &TreeNode{Val: 0}
	n3 := &TreeNode{Val: 3}

	n0.Left = n1
	n0.Right = n2
	n1.Right = n3

	t.Log(distributeCoins(n0))
}

func TestDist0(t *testing.T) {
	n0 := &TreeNode{Val: 3}
	n1 := &TreeNode{Val: 0}
	n2 := &TreeNode{Val: 0}
	n3 := &TreeNode{Val: 0}
	n4 := &TreeNode{Val: 2}

	n0.Right = n1
	n1.Left = n2
	n2.Left = n3
	n3.Left = n4

	t.Log(distributeCoins(n0))
}
