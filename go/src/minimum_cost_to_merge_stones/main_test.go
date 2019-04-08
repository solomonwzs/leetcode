/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

import "testing"

func TestMerge(t *testing.T) {
	t.Log(mergeStones([]int{3, 2, 4, 1}, 2))
}
