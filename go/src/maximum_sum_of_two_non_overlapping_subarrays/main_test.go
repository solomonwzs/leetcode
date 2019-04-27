/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-21
 * @license MIT
 */

package maximum_sum_of_two_non_overlapping_subarrays

import "testing"

func TestMax(t *testing.T) {
	t.Log(maxSumTwoNoOverlap([]int{0, 6, 5, 2, 2, 5, 1, 9, 4}, 1, 2) == 20)
}

func TestMax2(t *testing.T) {
	t.Log(maxSumTwoNoOverlap([]int{3, 8, 1, 3, 2, 1, 8, 9, 0}, 3, 2) == 29)
}
