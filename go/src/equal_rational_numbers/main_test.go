/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package equal_rational_numbers

import "testing"

func TestEq0(t *testing.T) {
	t.Log(isRationalEqual("0.(52)", "0.5(25)"))
}

func TestEq1(t *testing.T) {
	t.Log(isRationalEqual("0.1666(6)", "0.166(66)"))
}

func TestEq3(t *testing.T) {
	t.Log(isRationalEqual("0.9(9)", "1."))
}

func TestEq4(t *testing.T) {
	t.Log(isRationalEqual("0.0", "0.(0)"))
}

func TestEq5(t *testing.T) {
	t.Log(isRationalEqual("1.9(0)", "1.8(9)"))
}

func TestEq6(t *testing.T) {
	t.Log(isRationalEqual("1.9(0)", "1.8799(9)"))
}
