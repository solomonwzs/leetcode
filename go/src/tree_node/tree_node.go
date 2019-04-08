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
