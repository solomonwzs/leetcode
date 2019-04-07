/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-07
 * @license MIT
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

const N = 1000000007

func dfs(n *TreeNode, path []int, sum *int) {
	path = append(path, n.Val)
	if n.Left == nil && n.Right == nil {
		tmp := 0
		for _, i := range path {
			tmp = (tmp%N)*2 + i
		}
		*sum = (*sum + tmp) % N
	} else {
		if n.Left != nil {
			dfs(n.Left, path, sum)
		}
		if n.Right != nil {
			dfs(n.Right, path, sum)
		}
	}
}

func sumRootToLeaf(root *TreeNode) int {
	ans := 0
	path := make([]int, 0, 1000)
	dfs(root, path, &ans)
	return ans
}
