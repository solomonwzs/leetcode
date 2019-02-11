package main

func subarraysWithKDistinctOld(a []int, k int) int {
	if len(a) < k {
		return 0
	}

	res := 0
	for i := 0; i < len(a)-k+1; i++ {
		cnt := make(map[int]int, 200000)
		j := i
		for ; j < len(a) && len(cnt) < k; j++ {
			if n, exist := cnt[a[j]]; exist {
				cnt[a[j]] = n + 1
			} else {
				cnt[a[j]] = 1
			}
		}
		if len(cnt) == k {
			res += 1
			for ; j < len(a); j++ {
				if n, exist := cnt[a[j]]; exist {
					res += 1
					cnt[a[j]] = n + 1
				} else {
					break
				}
			}
		}
	}
	return res
}

func subarraysWithKDistinct(a []int, k int) int {
	if len(a) < k || len(a) == 0 {
		return 0
	}

	cnt := make(map[int]int, 200000)
	right := 0
	for ; right < len(a) && len(cnt) < k; right++ {
		cnt[a[right]] += 1
	}
	if len(cnt) < k {
		return 0
	}
	m := 1
	for ; right < len(a); right++ {
		if _, exist := cnt[a[right]]; exist {
			cnt[a[right]] += 1
			m += 1
		} else {
			break
		}
	}
	res := m

	for i := 1; i < len(a)-k+1; i++ {
		if n := cnt[a[i-1]]; n == 1 {
			delete(cnt, a[i-1])
			if right == len(a) {
				break
			}

			cnt[a[right]] = 1
			m = 1
			for right = right + 1; right < len(a); right++ {
				if _, exist := cnt[a[right]]; exist {
					cnt[a[right]] += 1
					m += 1
				} else {
					break
				}
			}
		} else {
			j := i
			for ; j < right && a[j] != a[i-1]; j++ {
			}
			if m > right-j {
				m = right - j
			}
			cnt[a[i-1]] = n - 1
		}
		res += m
	}

	return res
}
