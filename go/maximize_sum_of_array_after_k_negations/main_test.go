/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-10
 * @license MIT
 */

package main

import "testing"

func TestLargest(t *testing.T) {
	t.Log(largestSumAfterKNegations([]int{2, -3, -1, 5, -4}, 2) == 13)
}

func TestLargest1(t *testing.T) {
	t.Log(largestSumAfterKNegations([]int{-8, 3, -5, -3, -5, -2}, 6) == 22)
}
