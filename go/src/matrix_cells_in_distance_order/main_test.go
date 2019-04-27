/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-21
 * @license MIT
 */

package matrix_cells_in_distance_order

import "testing"

func TestAll(t *testing.T) {
	t.Log(allCellsDistOrder(1, 2, 0, 0))
}

func TestAll1(t *testing.T) {
	t.Log(allCellsDistOrder(2, 2, 0, 1))
}
