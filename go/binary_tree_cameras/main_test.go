package main

import "testing"

func TestMinCam0(t *testing.T) {
	n0 := &TreeNode{0, nil, nil}
	n1 := &TreeNode{0, nil, nil}
	n2 := &TreeNode{0, nil, nil}
	n3 := &TreeNode{0, nil, nil}

	n0.Left = n1
	n1.Left = n2
	n1.Right = n3

	t.Log(minCameraCover(n0))
}
func TestMinCam1(t *testing.T) {
	n0 := &TreeNode{0, nil, nil}
	n1 := &TreeNode{0, nil, nil}
	n2 := &TreeNode{0, nil, nil}
	n3 := &TreeNode{0, nil, nil}
	n4 := &TreeNode{0, nil, nil}

	n0.Left = n1
	n1.Left = n2
	n2.Left = n3
	n3.Left = n4

	t.Log(minCameraCover(n0))
}
