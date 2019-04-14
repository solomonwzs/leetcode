/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package recover_a_tree_from_preorder_traversal

import (
	"testing"
)

func TestRecover(t *testing.T) {
	t.Log(recoverFromPreorder("1-2--3--4-5--6--7").String() ==
		"1,2,5,3,4,6,7")
}

func TestRecover1(t *testing.T) {
	t.Log(recoverFromPreorder("1-2--3---4-5--6---7").String() ==
		"1,2,5,3,null,6,null,4,null,7")
}
