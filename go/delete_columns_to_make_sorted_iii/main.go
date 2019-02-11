package main

import "fmt"

func minDeletionSize(a []string) int {
	if len(a[0]) <= 1 {
		return 0
	}

	length := len(a[0])
	d := make([]int, length)
	for i := 0; i < length; i++ {
		d[i] = 1
	}

	for j := 1; j < length; j++ {
		for k := 0; k < j; k++ {
			ok := true
			for i := 0; ok && i < len(a); i++ {
				if a[i][k] > a[i][j] || d[j] > d[k]+1 {
					ok = false
				}
			}

			if ok {
				d[j] = d[k] + 1
			}
		}
	}

	max := d[0]
	for i := 1; i < len(d); i++ {
		if max < d[i] {
			max = d[i]
		}
	}
	fmt.Println(a, d)

	return length - max
}
