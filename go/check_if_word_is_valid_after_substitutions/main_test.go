/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

import "testing"

func TestIs(t *testing.T) {
	t.Log(isValid("aabcbc") == true)
}

func TestIs1(t *testing.T) {
	t.Log(isValid("abcabcababcc") == true)
}
