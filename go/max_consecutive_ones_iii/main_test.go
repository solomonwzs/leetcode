/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

import "testing"

func TestMax(t *testing.T) {
	t.Log(longestOnes([]int{
		1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0,
	}, 2) == 6)
}

func TestMax1(t *testing.T) {
	t.Log(longestOnes([]int{
		0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1,
	}, 3) == 10)
}
