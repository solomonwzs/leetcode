/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

import "strings"

func isValid(s string) bool {
	length := len(s)
	for {
		if s == "abc" {
			return true
		} else if s[0] != 'a' || s[length-1] != 'c' {
			return false
		}

		if idx := strings.Index(s, "abc"); idx == -1 {
			return false
		} else {
			s = s[:idx] + s[idx+3:]
			length -= 3
		}
	}
}
