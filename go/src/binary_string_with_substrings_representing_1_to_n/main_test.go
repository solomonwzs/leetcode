/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-14
 * @license MIT
 */

package binary_string_with_substrings_representing_1_to_n

import "testing"

func TestBin(t *testing.T) {
	t.Log(queryString("0110", 3) == true)
}

func TestBin1(t *testing.T) {
	t.Log(queryString("0110", 4) == false)
}

func TestBin2(t *testing.T) {
	t.Log(queryString("1111000101", 5) == true)
}
