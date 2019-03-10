/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-10
 * @license MIT
 */

package main

import "testing"

func TestClumsy(t *testing.T) {
	t.Log(clumsy(4) == 7)
}

func TestClumsy1(t *testing.T) {
	t.Log(clumsy(10) == 12)
}
