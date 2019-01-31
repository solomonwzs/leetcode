package main

func countTripletsV1(a []int) int {
	res := 0
	for _, x := range a {
		for _, y := range a {
			for _, z := range a {
				if x&y&z == 0 {
					res += 1
				}
			}
		}
	}
	return res
}

func countTripletsV2(a []int) int {
	m := make(map[int]int, 0xffff)
	for _, x := range a {
		for _, y := range a {
			k := x & y
			if s, exist := m[k]; exist {
				m[k] = s + 1
			} else {
				m[k] = 1
			}
		}
	}

	res := 0
	for k, s := range m {
		for _, z := range a {
			if k&z == 0 {
				res += s
			}
		}
	}
	return res
}
