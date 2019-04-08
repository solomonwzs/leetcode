/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package construct_binary_search_tree_from_preorder_traversal

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func bstFromPreorder(preorder []int) (root *TreeNode) {
	root = nil
	if n := len(preorder); n == 0 {
		return
	} else {
		root = &TreeNode{
			Val:   preorder[0],
			Left:  nil,
			Right: nil,
		}

		i := 1
		for ; i < n && preorder[i] < root.Val; i++ {
		}
		root.Left = bstFromPreorder(preorder[1:i])

		if i < n {
			root.Right = bstFromPreorder(preorder[i:])
		}
		return
	}
}
