package main

func maxTurbulenceSize(a []int) int {
	if len(a) == 0 {
		return 0
	}

	max := 1
	cur := 1
	lt := true
	for i := 1; i < len(a); i++ {
		if a[i-1] == a[i] {
			if cur > max {
				max = cur
			}
			cur = 1
		} else if cur == 1 {
			lt = a[i-1] < a[i]
			cur += 1
		} else {
			if lt == !(a[i-1] < a[i]) {
				cur += 1
			} else {
				if cur > max {
					max = cur
				}
				cur = 2
			}
			lt = a[i-1] < a[i]
		}
	}

	if cur > max {
		max = cur
	}

	return max
}
