/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

func dp(i, j, m, k int, cache map[int]int, prefix []int) int {
	key := i<<16 | j<<8 | m
	if (j-i+1-m)%(k-1) != 0 || (i == j && m != 1) {
		cache[key] = -1
		return -1
	}

	if c, exist := cache[key]; exist {
		return c
	}

	var res int
	if i == j {
		res = 0
	} else if m == 1 {
		res = dp(i, j, k, k, cache, prefix) + prefix[j+1] - prefix[i]
	} else {
		res = -1
		for mid := i; mid < j; mid += (k - 1) {
			a := dp(i, mid, 1, k, cache, prefix)
			if a == -1 {
				continue
			}
			b := dp(mid+1, j, m-1, k, cache, prefix)
			if b == -1 {
				continue
			}
			if res < 0 || res > a+b {
				res = a + b
			}
		}
	}

	cache[key] = res
	return res
}

func mergeStones(stones []int, k int) int {
	n := len(stones)
	if (n-1)%(k-1) != 0 {
		return -1
	}

	cache := make(map[int]int)
	prefix := make([]int, n+1)
	prefix[0] = 0
	for i, s := range stones {
		prefix[i+1] = prefix[i] + s
	}

	ans := dp(0, n-1, 1, k, cache, prefix)
	return ans
}
