/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-21
 * @license MIT
 */

package two_city_scheduling

import "testing"

func TestTwo(t *testing.T) {
	t.Log(twoCitySchedCost([][]int{
		[]int{259, 770},
		[]int{448, 54},
		[]int{926, 667},
		[]int{184, 139},
		[]int{840, 118},
		[]int{577, 469},
	}) == 1859)
}
