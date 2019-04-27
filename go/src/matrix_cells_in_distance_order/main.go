/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-21
 * @license MIT
 */

package matrix_cells_in_distance_order

var directions [][]int = [][]int{
	[]int{1, 1},
	[]int{1, -1},
	[]int{-1, 1},
	[]int{-1, -1},
}

func allCellsDistOrder(r int, c int, r0 int, c0 int) [][]int {
	m := make([][]bool, r)
	for i := 0; i < r; i++ {
		m[i] = make([]bool, c)
	}

	ans := make([][]int, 1, r*c)
	ans[0] = []int{r0, c0}
	for dist := 1; dist < r+c; dist++ {
		for rd := 0; rd <= dist; rd++ {
			cd := dist - rd
			for _, dir := range directions {
				rx := r0 + rd*dir[0]
				cx := c0 + cd*dir[1]
				if rx >= 0 && rx < r && cx >= 0 && cx < c && !m[rx][cx] {
					ans = append(ans, []int{rx, cx})
					m[rx][cx] = true
				}
			}
		}
	}
	return ans
}
