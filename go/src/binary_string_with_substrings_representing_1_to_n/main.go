/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package binary_string_with_substrings_representing_1_to_n

func queryString(s0 string, n int) bool {
	s := make([]int, len(s0))
	for i, c := range s0 {
		s[i] = int(c - '0')
	}

	min := 1
	max := 1
	bits := 1
	for bits <= len(s0) {
		x := 0
		for i := 0; i < bits; i++ {
			x = (x << 1) + s[i]
		}

		sets := map[int]bool{}
		if x >= min && x <= max && x <= n {
			sets[x] = true
		}
		for i := bits; i < len(s); i++ {
			x = ((x << 1) & max) + s[i]
			if x >= min && x <= max && x <= n {
				sets[x] = true
			}
		}

		if max >= n {
			return len(sets) == n-min+1
		} else if len(sets) != max-min+1 {
			return false
		}

		min = min << 1
		max = max<<1 + 1
		bits += 1
	}
	return false
}
