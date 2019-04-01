/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-01
 * @license MIT
 */

package main

func baseNeg2(n int) string {
	if n == 0 {
		return "0"
	}

	bin := make([]byte, 0)
	for n > 0 {
		if n&1 == 0 {
			bin = append(bin, 0)
		} else {
			bin = append(bin, 1)
		}
		n >>= 1
	}
	ans := make([]byte, len(bin)+2)
	for i := 0; i < len(bin); i++ {
		if bin[i] == 1 {
			ans[i] += 1
			if i&1 == 1 {
				ans[i+1] += 1
			}
		}
	}
	for i := 0; i < len(bin); i++ {
		for ans[i] > 1 {
			ans[i] -= 2
			if ans[i+1] > 0 {
				ans[i+1] -= 1
			} else {
				ans[i+1] += 1
				ans[i+2] += 1
			}
		}
	}
	l := len(ans)
	for ; ans[l-1] == 0; l-- {
	}

	for i := 0; i < l/2; i++ {
		t := ans[i]
		ans[i] = ans[l-i-1]
		ans[l-i-1] = t
	}

	for i := 0; i < l; i++ {
		ans[i] += '0'
	}

	return string(ans[:l])
}
