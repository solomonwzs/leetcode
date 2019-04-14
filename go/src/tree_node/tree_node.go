/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package tree_node

import (
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (root *TreeNode) String() string {
	if root == nil {
		return ""
	}

	list := make([]*TreeNode, 1)
	list[0] = root
	i := 0
	for i < len(list) {
		node := list[i]

		if node != nil && (node.Left != nil || node.Right != nil) {
			if node.Left != nil {
				list = append(list, node.Left)
			} else {
				list = append(list, nil)
			}
			if node.Right != nil {
				list = append(list, node.Right)
			} else {
				list = append(list, nil)
			}
		}
		i += 1
	}

	vals := make([]string, len(list))
	for i, n := range list {
		if n == nil {
			vals[i] = "null"
		} else {
			vals[i] = strconv.Itoa(n.Val)
		}
	}

	last := len(list)
	for ; vals[last-1] == "null"; last-- {
	}
	return strings.Join(vals[:last], ",")
}

func BuildTree(str string) *TreeNode {
	vals := strings.Split(str, ",")
	if len(vals) == 0 {
		return nil
	}

	list := make([]*TreeNode, 1, len(vals))
	val, _ := strconv.Atoi(vals[0])
	list[0] = &TreeNode{
		Val:   val,
		Left:  nil,
		Right: nil,
	}
	p := 0
	for i := 1; i < len(vals); i++ {
		if vals[i] != "null" {
			val, _ := strconv.Atoi(vals[i])
			node := &TreeNode{
				Val:   val,
				Left:  nil,
				Right: nil,
			}

			parent := list[p/2]
			if p%2 == 0 {
				parent.Left = node
			} else {
				parent.Right = node
			}

			list = append(list, node)
		}
		p += 1
	}
	return list[0]
}
