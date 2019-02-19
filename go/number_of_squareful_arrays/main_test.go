/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-19
 * @license MIT
 */

package main

import "testing"

func TestNum(t *testing.T) {
	t.Log(numSquarefulPerms([]int{1, 17, 8}) == 2)
}

func TestNum1(t *testing.T) {
	t.Log(numSquarefulPerms([]int{2, 2, 2}) == 1)
}

func TestNum2(t *testing.T) {
	t.Log(numSquarefulPerms([]int{0, 0, 0, 1, 1, 1}) == 4)
}
