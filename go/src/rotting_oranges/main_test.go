package main

import "testing"

func TestOrianges(t *testing.T) {
	t.Log(orangesRotting([][]int{
		[]int{2, 1, 1},
		[]int{1, 1, 0},
		[]int{0, 1, 1},
	}))
}
