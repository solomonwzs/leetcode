package main

import "testing"

func TestUniquePath(t *testing.T) {
	grid := [][]int{
		[]int{1, 0, 0, 0},
		[]int{0, 0, 0, 0},
		[]int{0, 0, 2, -1},
	}
	t.Log(uniquePathsIII(grid))
}
