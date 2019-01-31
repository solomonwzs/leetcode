package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
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

func dfs(root *TreeNode) [3]int {
	if root == nil {
		return [3]int{1001, 0, 0}
	}

	leftRes := dfs(root.Left)
	rightRes := dfs(root.Right)

	var res [3]int
	res[0] = 1 + min(leftRes[0], min(leftRes[1], leftRes[2])) +
		min(rightRes[0], min(rightRes[1], rightRes[2]))
	res[1] = min(
		min(leftRes[0]+rightRes[1], leftRes[1]+rightRes[0]),
		leftRes[0]+rightRes[0])
	res[2] = leftRes[1] + rightRes[1]

	return res
}

func minCameraCover(root *TreeNode) int {
	res := dfs(root)
	return min(res[0], res[1])
}
