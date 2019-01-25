package main

import "sort"

type orderList [][2]int

func (l *orderList) add(elem [2]int) {
	i := sort.Search(len(*l), func(i int) bool {
		a := (*l)[i]
		return elem[1] < a[1] || (elem[1] == a[1] && elem[0] < a[0])
	})
	*l = append(*l, [2]int{})
	copy((*l)[i+1:], (*l)[i:])
	(*l)[i] = elem
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

	for i := n - 2; i >= 0; i-- {
	}

	return 0
}
