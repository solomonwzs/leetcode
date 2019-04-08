/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package distribute_coins_in_binary_tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func moveCoins(root *TreeNode, move *int) {
	if root.Left != nil {
		moveCoins(root.Left, move)
		cval := root.Left.Val
		if cval > 1 {
			*move += cval - 1
			root.Val += (cval - 1)
		} else if cval < 1 {
			*move += 1 - cval
			root.Val -= (1 - cval)
		}
	}
	if root.Right != nil {
		moveCoins(root.Right, move)
		cval := root.Right.Val
		if cval > 1 {
			*move += cval - 1
			root.Val += (cval - 1)
		} else if cval < 1 {
			*move += 1 - cval
			root.Val -= (1 - cval)
		}
	}
}

func distributeCoins(root *TreeNode) int {
	if root == nil {
		return 0
	}

	move := 0
	moveCoins(root, &move)
	return move
}
