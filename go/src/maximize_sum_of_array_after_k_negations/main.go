/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-10
 * @license MIT
 */

package main

import (
	"sort"
)

func largestSumAfterKNegations(a []int, k int) int {
	sort.Ints(a)
	for i := 0; i < len(a) && k > 0; i++ {
		if a[i] < 0 {
			a[i] = -a[i]
			k -= 1
		} else {
			if k%2 == 1 {
				if i-1 >= 0 && a[i-1] < a[i] {
					a[i-1] = -a[i-1]
				} else {
					a[i] = -a[i]
				}
			}
			break
		}
	}

	ans := 0
	for i := 0; i < len(a); i++ {
		ans += a[i]
	}
	return ans
}
