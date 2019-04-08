/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package add_to_array_form_of_integer

func addToArrayForm(a []int, k int) []int {
	b := make([]int, 0)
	for k > 0 {
		b = append(b, k%10)
		k /= 10
	}

	length := len(a)
	if len(b) > length {
		length = len(b)
	}

	c := make([]int, length)
	carry := 0
	ia := len(a) - 1
	ib := 0
	ic := length - 1
	for ia >= 0 || ib < len(b) {
		if ia >= 0 && ib < len(b) {
			c[ic] = a[ia] + b[ib] + carry
			ia -= 1
			ib += 1
		} else if ia >= 0 {
			c[ic] = a[ia] + carry
			ia -= 1
		} else if ib < len(b) {
			c[ic] = b[ib] + carry
			ib += 1
		}

		if c[ic] < 10 {
			carry = 0
		} else {
			carry = 1
			c[ic] = c[ic] % 10
		}
		ic -= 1
	}

	if carry == 0 {
		return c
	} else {
		cx := make([]int, len(c)+1)
		cx[0] = 1
		copy(cx[1:], c)
		return cx
	}
}
