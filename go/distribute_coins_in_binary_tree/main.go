package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func distributeCoins0(root *TreeNode, move *int) int {
	var (
		val  int = root.Val
		cval int
	)
	if root.Left != nil {
		cval = distributeCoins0(root.Left, move)
		if cval > 1 {
			*move += cval - 1
			val += (cval - 1)
		} else if cval < 1 {
			*move += 1 - cval
			val -= (1 - cval)
		}
	}
	if root.Right != nil {
		cval = distributeCoins0(root.Right, move)
		if cval > 1 {
			*move += cval - 1
			val += (cval - 1)
		} else if cval < 1 {
			*move += 1 - cval
			val -= (1 - cval)
		}
	}
	return val
}

func distributeCoins(root *TreeNode) int {
	if root == nil {
		return 0
	}

	move := 0
	distributeCoins0(root, &move)
	return move
}
