package main

import "testing"

func TestVer0(t *testing.T) {
	n0 := &TreeNode{3, nil, nil}
	n1 := &TreeNode{9, nil, nil}
	n2 := &TreeNode{20, nil, nil}
	n3 := &TreeNode{15, nil, nil}
	n4 := &TreeNode{7, nil, nil}

	n0.Left = n1
	n0.Right = n2
	n2.Left = n3
	n2.Right = n4

	t.Log(verticalTraversal(n0))
}
