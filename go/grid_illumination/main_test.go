/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-24
 * @license MIT
 */

package main

import "testing"

func TestGrid(t *testing.T) {
	lamps := [][]int{
		[]int{0, 0},
		[]int{4, 4},
	}
	queries := [][]int{
		[]int{1, 1},
		[]int{1, 0},
	}
	t.Log(gridIllumination(5, lamps, queries))
}
