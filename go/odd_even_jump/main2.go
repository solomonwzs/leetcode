package main

import (
	"sort"
)

func oddEvenJumpsNew(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	higher := make([]bool, n)
	lower := make([]bool, n)
	list := make([][2]int, 0, n)

	higher[n-1] = true
	lower[n-1] = true
	list = append(list, [2]int{a[n-1], n - 1})

	res := 1
	for i := n - 2; i >= 0; i-- {
		idx := sort.Search(len(list), func(ii int) bool {
			return a[i] <= list[ii][0]
		})

		if idx < len(list) && a[i] <= list[idx][0] {
			higher[i] = lower[list[idx][1]]
		}

		var j int
		if idx < len(list) && list[idx][0] <= a[i] {
			j = idx
		} else {
			j = idx - 1
		}
		if j >= 0 {
			lower[i] = higher[list[j][1]]
		}

		if idx < len(list) && a[i] == list[idx][0] {
			list[idx][1] = i
		} else {
			list = append(list, [2]int{})
			copy(list[idx+1:], list[idx:])
			list[idx] = [2]int{a[i], i}
		}

		if higher[i] {
			res += 1
		}
	}

	return res
}
