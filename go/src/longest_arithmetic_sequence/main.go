/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package longest_arithmetic_sequence

func longestArithSeqLength(a []int) int {
	ans := make([]map[int]int, len(a))
	ans[0] = make(map[int]int)

	max := 0
	for i := 1; i < len(a); i++ {
		ans[i] = make(map[int]int)
		for j := 0; j < i; j++ {
			d := a[i] - a[j]
			if x := ans[j][d] + 1; x > ans[i][d] {
				ans[i][d] = x
				if x > max {
					max = x
				}
			}
		}
	}
	return max + 1
}
