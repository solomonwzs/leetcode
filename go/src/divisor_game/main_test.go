/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package divisor_game

import "testing"

func TestDiv(t *testing.T) {
	t.Log(divisorGame(2) == true)
}

func TestDiv1(t *testing.T) {
	t.Log(divisorGame(9) == false)
}
