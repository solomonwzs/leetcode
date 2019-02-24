/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-24
 * @license MIT
 */

package main

import "testing"

func TestFind0(t *testing.T) {
	t.Log(findJudge(1, [][]int{}))
}

func TestFind1(t *testing.T) {
	t.Log(findJudge(2, [][]int{[]int{1, 2}}) == 2)
}

func TestFind2(t *testing.T) {
	t.Log(findJudge(3, [][]int{
		[]int{1, 3},
		[]int{2, 3},
	}) == 3)
}

func TestFind3(t *testing.T) {
	t.Log(findJudge(3, [][]int{
		[]int{1, 3},
		[]int{2, 3},
		[]int{3, 1},
	}) == -1)
}
