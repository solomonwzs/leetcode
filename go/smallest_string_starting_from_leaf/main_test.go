package main

import "testing"

func TestSmall(t *testing.T) {
	n0 := &TreeNode{0, nil, nil}
	n1 := &TreeNode{1, nil, nil}
	n2 := &TreeNode{2, nil, nil}
	n3 := &TreeNode{3, nil, nil}
	n4 := &TreeNode{4, nil, nil}
	n5 := &TreeNode{3, nil, nil}
	n6 := &TreeNode{4, nil, nil}

	n0.Left = n1
	n0.Right = n2
	n1.Left = n3
	n1.Right = n4
	n2.Left = n5
	n2.Right = n6
	t.Log(smallestFromLeaf(n0))
}
