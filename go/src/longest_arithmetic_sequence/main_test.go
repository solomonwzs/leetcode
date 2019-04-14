/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package longest_arithmetic_sequence

import "testing"

func TestLongest(t *testing.T) {
	t.Log(longestArithSeqLength([]int{3, 6, 9, 12}) == 4)
}

func TestLongest1(t *testing.T) {
	t.Log(longestArithSeqLength([]int{9, 4, 7, 2, 10}) == 3)
}

func TestLongest2(t *testing.T) {
	t.Log(longestArithSeqLength([]int{20, 1, 15, 3, 10, 5, 8}) == 4)
}
