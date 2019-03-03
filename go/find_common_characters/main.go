/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

func commonChars(a []string) (ans []string) {
	words := make([]map[byte]int, len(a))
	for i, w := range a {
		words[i] = make(map[byte]int)
		for j := 0; j < len(w); j++ {
			words[i][w[j]] += 1
		}
	}

	ans = make([]string, 0)
	for char, cnt := range words[0] {
		for cnt > 0 {
			ok := true
			for i := 1; i < len(a); i++ {
				if c, exist := words[i][char]; exist && c > 0 {
					words[i][char] = c - 1
				} else {
					ok = false
					break
				}
			}

			if ok {
				cnt -= 1
				ans = append(ans, string([]byte{char}))
			} else {
				break
			}
		}
	}

	return ans
}
