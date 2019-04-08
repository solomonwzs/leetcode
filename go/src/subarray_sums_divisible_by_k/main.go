package main

func subarraysDivByK_old(a []int, k int) (r int) {
	for i := 0; i < len(a); i++ {
		a[i] = a[i] % k
	}
	mark := make([]bool, len(a))

	r = 0
	for i := 0; i < len(a); i++ {
		if mark[i] {
			continue
		}

		sum := 0
		m := 0
		for j := i; j < len(a); j++ {
			sum += a[j]
			if sum == 0 || sum == k || sum == -k {
				sum = 0
				m += 1

				if j+1 < len(a) {
					mark[j+1] = true
				}
			} else if sum > k {
				sum -= k
			} else if sum < -k {
				sum += k
			}
		}
		r += (1 + m) * m / 2
	}

	return
}

func subarraysDivByK(a []int, k int) (r int) {
	modK := make([]int, k)
	modK[0] = 1
	sum := 0
	for _, i := range a {
		sum += i
		mod := sum % k
		if mod < 0 {
			mod += k
		}
		modK[mod] += 1
	}

	r = 0
	for _, n := range modK {
		r += n * (n - 1) / 2
	}
	return
}
