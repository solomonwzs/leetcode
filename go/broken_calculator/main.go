package main

import (
	"sort"
)

func brokenCalc(x int, y int) int {
	if x == y {
		return 0
	}

	yl := make([]int, 1)
	zl := make([]int, 1)
	yl[0] = y
	zl[0] = 0
	for i := 0; yl[i] > 1; i++ {
		yl = append(yl, (yl[i]+1)/2)

		z := zl[i] + 1
		if yl[i+1]*2 == yl[i]+1 {
			z += 1
		}
		zl = append(zl, z)
	}
	idx := sort.Search(len(yl), func(i int) bool { return yl[i] <= x })

	return x - yl[idx] + zl[idx]
}
