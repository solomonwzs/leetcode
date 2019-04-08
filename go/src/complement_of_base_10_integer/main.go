/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package complement_of_base_10_integer

func bitwiseComplement(n int) int {
	if n == 0 {
		return 1
	}

	ans := 0
	x := 1
	for n > 0 {
		if n&1 == 0 {
			ans += x
		}
		n = n >> 1
		x = x << 1
	}
	return ans
}
