package main

import (
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(root *TreeNode, path *[]byte, ans *string) {
	*path = append(*path, byte(root.Val)+'a')
	if root.Left != nil {
		dfs(root.Left, path, ans)
	}
	if root.Right != nil {
		dfs(root.Right, path, ans)
	}
	if root.Left == nil && root.Right == nil {
		length := len(*path)
		p := make([]byte, length)
		for i := 0; i < length; i++ {
			p[i] = (*path)[length-i-1]
		}
		ps := string(p)
		if *ans > ps {
			*ans = ps
		}
	}
	*path = (*path)[:len(*path)-1]
}

func smallestFromLeaf(root *TreeNode) string {
	ans := strings.Repeat("z", 1000)
	path := make([]byte, 0, 1000)
	dfs(root, &path, &ans)
	return ans
}
