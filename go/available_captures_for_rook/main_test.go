/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-24
 * @license MIT
 */

package main

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
