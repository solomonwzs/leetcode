/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-19
 * @license MIT
 */

package main

func flips(a []int, k int, i int, ans *int) {
	if len(a) == 0 {
		return
	}

	head := a[i-1]
	for ; i < len(a) && i < k && a[i] == head; i++ {
	}
	if i == k {
		if head == 0 {
			*ans += 1
		}
		flips(a[k:], k, 1, ans)
	} else if i == len(a) {
		if head == 0 {
			*ans = -1
		}
	} else if i+k > len(a) {
		*ans = -1
	} else {
		for j := i; j < i+k; j++ {
			a[j] = a[j] ^ 1
		}
		*ans += 1
		flips(a, k, i+1, ans)
	}
}

func minKBitFlips(a []int, k int) int {
	if len(a) == 0 {
		return 0
	}
	ans := 0
	flips(a, k, 1, &ans)
	return ans
}

func minKBitFlipsV2(a []int, k int) int {
	ans := 0
	flipped := 0
	f := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		if i >= k {
			flipped ^= f[i-k]
		}
		if flipped == a[i] {
			if i+k > len(a) {
				return -1
			}
			f[i] = 1
			flipped ^= 1
			ans += 1
		}
	}
	return ans
}

func minKBitFlipsV3(a []int, k int) int {
	ans := 0
	cur := 0
	for i := 0; i < len(a); i++ {
		if i >= k {
			cur -= a[i-k] / 2
		}
		if cur&1^a[i] == 0 {
			if i+k > len(a) {
				return -1
			}
			a[i] += 2
			cur += 1
			ans += 1
		}
	}
	return ans
}
