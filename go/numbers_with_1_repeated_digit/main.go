/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-17
 * @license MIT
 */

package main

func rfactorial(m, n int) int {
	if n == 0 {
		return 1
	}
	ans := 1
	end := m - n + 1
	for ; m >= end; m-- {
		ans *= m
	}
	return ans
}

func numDupDigitsAtMostN(n int) int {
	d := make([]int, 0)
	for i := n; i > 0; i /= 10 {
		d = append(d, i%10)
	}
	l := len(d)

	res := 0
	for i := 1; i < l; i++ {
		res += 9 * rfactorial(9, i-1)
	}

	dSet := make(map[int]bool)
	for i := 0; i < l; i++ {
		x := d[l-i-1]

		j := 1
		if i > 0 {
			j = 0
		}
		for ; j < x; j++ {
			if _, exist := dSet[j]; !exist {
				res += rfactorial(9-i, l-i-1)
			}
		}

		if _, exist := dSet[x]; exist {
			break
		}
		dSet[x] = true
	}

	if len(dSet) == l {
		res += 1
	}

	return n - res
}
