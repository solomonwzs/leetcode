/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

func longestOnes(a []int, k int) int {
	n := make([]int, 0)
	p := make([]int, 0)

	pre := 1
	n0 := 0
	p0 := 0
	for i := 0; i < len(a); i++ {
		if a[i] != pre {
			if a[i] == 0 {
				n = append(n, n0)
				n0 = 0
				p0 = 1
			} else {
				p = append(p, p0)
				n0 = 1
				p0 = 0
			}
		} else {
			if a[i] == 0 {
				p0 += 1
			} else {
				n0 += 1
			}
		}
		pre = a[i]
	}

	if pre == 0 {
		p = append(p, p0)
		n = append(n, 0)
	} else {
		n = append(n, n0)
	}

	start := 0
	end := 0
	max := n[0]
	for ; end < len(p) && k >= p[end]; end++ {
		max += p[end] + n[end+1]
		k -= p[end]
	}
	val := max
	max += k

	for end < len(p) {
		for ; start < end && k < p[end]; start++ {
			val -= n[start] + p[start]
			k += p[start]
		}

		if k < p[end] {
			end += 1
			start = end
			if start < len(n) {
				val = n[start]
			}
		}

		for ; end < len(p) && k >= p[end]; end++ {
			val += p[end] + n[end+1]
			k -= p[end]
		}

		if val+k > max {
			max = val + k
		}
	}

	if max > len(a) {
		max = len(a)
	}

	return max
}
