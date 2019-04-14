/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package maximum_difference_between_node_and_ancestor

import (
	"testing"
	"tree_node"
)

func TestMax(t *testing.T) {
	root := tree_node.BuildTree("8,3,10,1,6,null,14,null,null,4,7,13")
	t.Log(maxAncestorDiff(root))
}
