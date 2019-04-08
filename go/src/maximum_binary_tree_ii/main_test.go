/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-24
 * @license MIT
 */

package main

import "testing"

func TestInsert(t *testing.T) {
	n1 := &TreeNode{1, nil, nil}
	n2 := &TreeNode{2, nil, nil}
	n3 := &TreeNode{3, nil, nil}
	n4 := &TreeNode{4, nil, nil}

	n4.Left = n1
	n4.Right = n3
	n3.Left = n2
	t.Log(insertIntoMaxTree(n4, 5))
}
