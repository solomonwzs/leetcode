/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package recover_a_tree_from_preorder_traversal

import (
	"fmt"
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

func (e stackElem) String() string {
	return fmt.Sprintf("%+v", e.n)
}

func recoverFromPreorder(s string) *TreeNode {
	plist := make([]node, 0)
	depth, val := 0, 0
	isDigital := false
	for _, char := range s {
		if isDigital {
			if char == '-' {
				plist = append(plist, node{
					val:   val,
					depth: depth,
				})

				isDigital = false
				depth = 1
			} else {
				val = val*10 + int(char-'0')
			}
		} else {
			if char == '-' {
				depth += 1
			} else {
				isDigital = true
				val = int(char - '0')
			}
		}
	}
	plist = append(plist, node{
		val:   val,
		depth: depth,
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
