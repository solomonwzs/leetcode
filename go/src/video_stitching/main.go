/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package main

import (
	"sort"
)

type ClipList [][]int

func (c ClipList) Len() int           { return len(c) }
func (c ClipList) Less(i, j int) bool { return c[i][0] < c[j][0] }
func (c ClipList) Swap(i, j int)      { c[i], c[j] = c[j], c[i] }

func videoStitching(clips [][]int, t int) int {
	sort.Sort(ClipList(clips))
	ans := make([]int, t+1)
	k := 0
	for _, clip := range clips {
		if clip[0] > t {
			break
		}
		if clip[0] > k {
			return -1
		}

		n := 1
		if clip[0] != 0 {
			n = ans[clip[0]] + 1
		}
		if clip[1] > k {
			for i := k + 1; i <= clip[1] && i <= t; i++ {
				ans[i] = n
			}
			k = clip[1]
		}
	}

	if ans[t] == 0 {
		return -1
	}
	return ans[t]
}
