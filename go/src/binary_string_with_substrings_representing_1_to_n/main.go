/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package binary_string_with_substrings_representing_1_to_n

import "fmt"

func queryString(s0 string, n int) bool {
	s := make([]int, len(s0))
	for i, c := range s0 {
		s[i] = int(c - '0')
	}

	l := 1
	k := 2
	for {
		x := 0
		for i := 0; i < l; i++ {
			x = (x << 1) + s[i]
		}

		max := k - 1
		min := max >> 1
		c := map[int]bool{}
		if x >= min {
			c[x] = true
		}
		for i := 0; i < len(s)-l; i++ {
			x = ((x << 1) & max) + s[i+l]
			if x > min {
				c[x] = true
			}
		}
		fmt.Println(c, min, max)

		if k > n {
			return len(c) == n-(k<<2)
		}
		if len(c) != k {
			return false
		}

		k *= 2
		l += 1
	}
}
