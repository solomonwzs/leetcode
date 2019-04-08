/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package available_captures_for_rook

import "testing"

func TestNum0(t *testing.T) {
	t.Log(numRookCaptures([][]byte{
		[]byte{'.', '.', '.', '.', '.', '.', '.', '.'},
		[]byte{'.', '.', '.', 'p', '.', '.', '.', '.'},
		[]byte{'.', '.', '.', 'R', '.', '.', '.', 'p'},
		[]byte{'.', '.', '.', '.', '.', '.', '.', '.'},
		[]byte{'.', '.', '.', '.', '.', '.', '.', '.'},
		[]byte{'.', '.', '.', 'p', '.', '.', '.', '.'},
		[]byte{'.', '.', '.', '.', '.', '.', '.', '.'},
		[]byte{'.', '.', '.', '.', '.', '.', '.', '.'},
	}) == 3)
}
