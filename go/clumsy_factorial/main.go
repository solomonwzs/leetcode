/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-10
 * @license MIT
 */

package main

func clumsy(n int) int {
	ans := 0
	tmp := 0
	plus := 1
	for i := 0; i < n; i++ {
		x := n - i
		switch i % 4 {
		case 0:
			tmp = x
		case 1:
			tmp *= x
		case 2:
			tmp /= x
		case 3:
			ans += x
			ans += tmp * plus
			plus = -1
			tmp = 0
		}
	}
	return ans + tmp*plus
}
