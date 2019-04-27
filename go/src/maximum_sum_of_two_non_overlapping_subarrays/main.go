/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-21
 * @license MIT
 */

package maximum_sum_of_two_non_overlapping_subarrays

import (
	"sort"
)

type node struct {
	value int
	start int
}

func getList(a []int, l int) []int {
	lList := make([]int, len(a)-l+1)
	lList[0] = a[0]
	for i := 1; i < l; i++ {
		lList[0] += a[i]
	}
	for i := 1; i < len(lList); i++ {
		lList[i] = lList[i-1] - a[i-1] + a[i+l-1]
	}
	return lList
}

func getSortList(lList []int) []node {
	lNodeList := make([]node, len(lList))
	for i, x := range lList {
		lNodeList[i].start = i
		lNodeList[i].value = x
	}

	sort.SliceStable(lNodeList, func(i, j int) bool {
		return lNodeList[i].value > lNodeList[j].value
	})

	list := make([]node, 0, len(lList))
	p := 0
	for i := 0; i < len(lList); i++ {
		for ; lNodeList[p].start < i; p++ {
		}
		list = append(list, lNodeList[p])
	}
	return list
}

func maxSumTwoNoOverlap(a []int, l int, m int) int {
	lList := getList(a, l)
	mList := getList(a, m)

	lNodeList := getSortList(lList)
	mNodeList := getSortList(mList)

	ans := 0
	for i, x := range lList {
		j := i + l
		if j < len(mNodeList) && x+mNodeList[j].value > ans {
			ans = x + mNodeList[j].value
		}
	}
	for i, x := range mList {
		j := i + m
		if j < len(lNodeList) && x+lNodeList[j].value > ans {
			ans = x + lNodeList[j].value
		}
	}
	return ans
}
