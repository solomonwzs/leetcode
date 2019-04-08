/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package cousins_in_binary_tree

import "testing"

func TestCousins(t *testing.T) {
	n1 := &TreeNode{1, nil, nil}
	n2 := &TreeNode{2, nil, nil}
	n3 := &TreeNode{3, nil, nil}
	n4 := &TreeNode{4, nil, nil}

	n1.Left = n2
	n1.Right = n3
	n2.Left = n4

	t.Log(isCousins(n1, 4, 3))
}

func TestCousins1(t *testing.T) {
	n1 := &TreeNode{1, nil, nil}
	n2 := &TreeNode{2, nil, nil}
	n3 := &TreeNode{3, nil, nil}
	n4 := &TreeNode{4, nil, nil}
	n5 := &TreeNode{5, nil, nil}

	n1.Left = n2
	n1.Right = n3
	n2.Right = n4
	n3.Right = n5

	t.Log(isCousins(n1, 4, 5))
}
