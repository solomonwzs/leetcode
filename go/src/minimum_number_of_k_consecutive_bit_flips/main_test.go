/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-19
 * @license MIT
 */

package main

import "testing"

func TestFlips(t *testing.T) {
	t.Log(minKBitFlips([]int{0, 0, 0, 1, 0, 1, 1, 0}, 3) == 3)
	t.Log(minKBitFlipsV2([]int{0, 0, 0, 1, 0, 1, 1, 0}, 3) == 3)
	t.Log(minKBitFlipsV3([]int{0, 0, 0, 1, 0, 1, 1, 0}, 3) == 3)
}

func TestFlips1(t *testing.T) {
	t.Log(minKBitFlips([]int{1, 0}, 2) == -1)
}

func TestFlips2(t *testing.T) {
	t.Log(minKBitFlips([]int{1, 1, 0}, 2) == -1)
}
