/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package camelcase_matching

func match(query, pattern string) bool {
	if len(query) < len(pattern) {
		return false
	}
	i := 0
	j := 0
	for ; j < len(query) && i < len(pattern); j++ {
		if query[j] == pattern[i] {
			i += 1
		} else if 'A' <= query[j] && query[j] <= 'Z' {
			return false
		}
	}
	for ; j < len(query); j++ {
		if 'A' <= query[j] && query[j] <= 'Z' {
			return false
		}
	}
	return i == len(pattern)
}

func camelMatch(queries []string, pattern string) []bool {
	ans := make([]bool, len(queries))
	for i, query := range queries {
		ans[i] = match(query, pattern)
	}
	return ans
}
