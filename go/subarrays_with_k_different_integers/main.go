package main

func subarraysWithKDistinctOld(a []int, k int) int {
	if len(a) < k {
		return 0
	}

	res := 0
	for i := 0; i < len(a)-k+1; i++ {
		cnt := make(map[int]int)
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

	cnt := make([]int, len(a)+1)
	right := 0
	kn := 0
	for ; right < len(a) && kn < k; right++ {
		if cnt[a[right]] == 0 {
			kn += 1
		}
		cnt[a[right]] += 1
	}
	if kn < k {
		return 0
	}
	m := 1
	for ; right < len(a); right++ {
		if cnt[a[right]] != 0 {
			cnt[a[right]] += 1
			m += 1
		} else {
			break
		}
	}
	res := m

	for i := 1; i < len(a)-k+1; i++ {
		cnt[a[i-1]] -= 1
		if cnt[a[i-1]] == 0 {
			kn -= 1
			if right == len(a) {
				break
			}

			cnt[a[right]] = 1
			m = 1
			for right = right + 1; right < len(a); right++ {
				if cnt[a[right]] != 0 {
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
		}
		res += m
	}

	return res
}

func atMostK(a []int, k int) int {
	i := 0
	j := 0
	res := 0
	cnt := map[int]int{}
	for ; j < len(a); j++ {
		if cnt[a[j]] == 0 {
			k -= 1
		}
		cnt[a[j]] += 1

		for ; k < 0; i++ {
			cnt[a[i]] -= 1
			if cnt[a[i]] == 0 {
				k += 1
			}
		}
		res += j - i + 1
	}
	return res
}

func subarraysWithKDistinctV2(a []int, k int) int {
	return atMostK(a, k) - atMostK(a, k-1)
}

func subarraysWithKDistinctV3(a []int, k int) int {
	cnt := make([]int, len(a)+1)
	i := 0
	j := 0
	m := 0
	kn := 0
	res := 0
	for ; i < len(a); i++ {
		if cnt[a[i]] == 0 {
			kn += 1
		}
		cnt[a[i]] += 1

		if kn > k {
			kn -= 1
			cnt[a[j]] -= 1
			j += 1
			m = 0
		}

		for ; j < i && cnt[a[j]] > 1; j++ {
			m += 1
			cnt[a[j]] -= 1
		}

		if kn == k {
			res += m + 1
		}
	}
	return res
}
