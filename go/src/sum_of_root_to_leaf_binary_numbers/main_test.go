/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package sum_of_root_to_leaf_binary_numbers

import (
	"testing"
	. "tree_node"
)

func TestSum(t *testing.T) {
	root := BuildTree("1,0,1,0,1,0,1")
	t.Log(sumRootToLeaf(root) == 22)
}
