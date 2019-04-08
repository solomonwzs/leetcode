/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package cousins_in_binary_tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Node struct {
	parent   int
	depth    int
	treeNode *TreeNode
}

func isCousins(root *TreeNode, x int, y int) bool {
	list := []Node{Node{
		parent:   -1,
		depth:    0,
		treeNode: root,
	}}
	var nx *Node = nil
	var ny *Node = nil
	for i := 0; i < len(list); i++ {
		if list[i].treeNode.Val == x {
			nx = &list[i]
		}
		if list[i].treeNode.Val == y {
			ny = &list[i]
		}

		if nx != nil && ny != nil {
			break
		}

		if list[i].treeNode.Left != nil {
			list = append(list, Node{
				parent:   list[i].treeNode.Val,
				depth:    list[i].depth + 1,
				treeNode: list[i].treeNode.Left,
			})
		}
		if list[i].treeNode.Right != nil {
			list = append(list, Node{
				parent:   list[i].treeNode.Val,
				depth:    list[i].depth + 1,
				treeNode: list[i].treeNode.Right,
			})
		}
	}
	return nx != nil && ny != nil && nx.parent != ny.parent && nx.depth == ny.depth
}
