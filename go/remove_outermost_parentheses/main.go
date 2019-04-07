/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-07
 * @license MIT
 */

package main

func removeOuterParentheses(s string) string {
	ans := make([]byte, 0, len(s))
	stack := make([]byte, 0, len(s))
	outer := true
	for _, ch := range s {
		if ch == '(' {
			if outer {
				outer = false
			} else {
				stack = append(stack, '(')
				ans = append(ans, '(')
			}
		} else {
			if l := len(stack); l == 0 {
				outer = true
			} else {
				stack = stack[:l-1]
				ans = append(ans, ')')
			}
		}
	}
	return string(ans)
}
