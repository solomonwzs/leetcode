package main

import (
	"testing"
)

func TestMaxTurbulenceSize(t *testing.T) {
	t.Log(maxTurbulenceSize([]int{9, 4, 2, 10, 7, 8, 8, 1, 9}))
	t.Log(maxTurbulenceSize([]int{4, 8, 12, 16}))
	t.Log(maxTurbulenceSize([]int{100}))
	t.Log(maxTurbulenceSize([]int{0, 1, 1, 0, 1, 0, 1, 1, 0, 0}))
	t.Log(maxTurbulenceSize([]int{8, 8, 9, 10, 6, 8, 2, 4, 2, 2, 10, 6, 6, 10, 10, 2, 3, 5, 1, 2, 10, 4, 2, 0, 9, 4, 9, 3, 0, 6, 3, 2, 3, 10, 10, 6, 4, 6, 4, 4, 2, 5, 1, 4, 1, 1, 9, 8, 9, 5, 3, 5, 5, 4, 5, 5, 6, 5, 3, 3, 7, 2, 0, 10, 9, 7, 7, 3, 5, 1, 0, 9, 6, 3, 1, 3, 4, 4, 3, 6, 3, 2, 1, 4, 10, 2, 3, 4, 4, 3, 6, 7, 6, 2, 1, 7, 0, 6, 8, 10}))
}
