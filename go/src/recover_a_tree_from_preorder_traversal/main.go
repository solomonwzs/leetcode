/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package recover_a_tree_from_preorder_traversal

import (
	"strconv"
	. "tree_node"
)

type node struct {
	val   int
	depth int
}

type stackElem struct {
	n  *node
	tn *TreeNode
}

func recoverFromPreorder(s string) *TreeNode {
	plist := make([]node, 0)
	d, j := 0, 0
	isDigital := false
	for i, char := range s {
		if isDigital {
			if char == '-' {
				val, _ := strconv.Atoi(s[j:i])
				plist = append(plist, node{
					val:   val,
					depth: d,
				})

				isDigital = false
				d = 1
			}
		} else {
			if char == '-' {
				d += 1
			} else {
				isDigital = true
				j = i
			}
		}
	}
	val, _ := strconv.Atoi(s[j:])
	plist = append(plist, node{
		val:   val,
		depth: d,
	})

	root := &TreeNode{
		Val:   plist[0].val,
		Left:  nil,
		Right: nil,
	}
	stack := make([]stackElem, 1, len(plist))
	stack[0] = stackElem{
		n:  &plist[0],
		tn: root,
	}

	top := 0
	for i := 1; i < len(plist); i++ {
		for top >= 0 && stack[top].n.depth+1 != plist[i].depth {
			top -= 1
		}
		stack = stack[:top+1]

		tn := &TreeNode{
			Val:   plist[i].val,
			Left:  nil,
			Right: nil,
		}
		if stack[top].tn.Left == nil {
			stack[top].tn.Left = tn
			stack = append(stack, stackElem{
				n:  &plist[i],
				tn: tn,
			})
			top += 1
		} else if stack[top].tn.Right == nil {
			stack[top].tn.Right = tn

			stack[top].n = &plist[i]
			stack[top].tn = tn
		}
	}

	return root
}
