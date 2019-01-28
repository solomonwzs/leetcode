package main

import (
	"sort"
)

type orderList [][2]int

func (l *orderList) add(elem [2]int) (i int) {
	i = sort.Search(len(*l), func(i int) bool {
		a := (*l)[i]
		return elem[1] < a[1] || (elem[1] == a[1] && elem[0] < a[0])
	})
	*l = append(*l, [2]int{})
	copy((*l)[i+1:], (*l)[i:])
	(*l)[i] = elem
	return
}

func oddEvenJumpsNew(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	higher := make([]bool, n)
	lower := make([]bool, n)
	list := orderList(make([][2]int, 0, n))

	higher[n-1] = true
	lower[n-1] = true
	list.add([2]int{n - 1, a[n-1]})

	res := 1
	for i := n - 2; i >= 0; i-- {
		idx := list.add([2]int{i, a[i]})

		if hi := idx + 1; hi < len(list) {
			higher[i] = lower[list[hi][0]]
		}

		if idx+1 < len(list) && list[idx+1][1] == a[i] {
			lower[i] = higher[list[idx+1][0]]
		} else if lo := idx - 1; lo >= 0 {
			for ; lo-1 >= 0 && list[lo-1][1] == list[lo][1]; lo-- {
			}
			lower[i] = higher[list[lo][0]]
		}

		if higher[i] {
			res += 1
		}
	}

	return res
}
