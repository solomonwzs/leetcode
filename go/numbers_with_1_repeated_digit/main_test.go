/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-17
 * @license MIT
 */

package main

import "testing"

func TestNum(t *testing.T) {
	t.Log(numDupDigitsAtMostN(1000))
}

func TestNum1(t *testing.T) {
	t.Log(numDupDigitsAtMostN(21))
}
