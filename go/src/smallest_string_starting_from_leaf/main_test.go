/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package smallest_string_starting_from_leaf

import (
	"testing"
	. "tree_node"
)

func TestSmall(t *testing.T) {
	root := BuildTree("0,1,2,3,4,3,4")
	t.Log(smallestFromLeaf(root) == "dba")
}

func TestSmall1(t *testing.T) {
	root := BuildTree("25,1,3,1,3,0,2")
	t.Log(smallestFromLeaf(root) == "adz")
}

func TestSmall2(t *testing.T) {
	root := BuildTree("2,2,1,null,1,0,null,0")
	t.Log(smallestFromLeaf(root) == "abc")
}
