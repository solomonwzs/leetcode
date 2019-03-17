/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-17
 * @license MIT
 */

package main

import "testing"

func TestShip(t *testing.T) {
	t.Log(shipWithinDays([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5) == 15)
}

func TestShip1(t *testing.T) {
	t.Log(shipWithinDays([]int{3, 2, 2, 4, 1, 4}, 3) == 6)
}

func TestShip2(t *testing.T) {
	t.Log(shipWithinDays([]int{1, 2, 3, 1, 1}, 4) == 3)
}

func TestShip3(t *testing.T) {
	t.Log(shipWithinDays([]int{147, 73, 265, 305, 191, 152, 192,
		293, 309, 292, 182, 157, 381, 287, 73, 162, 313, 366, 346, 48}, 10) == 602)
}

func TestShip4(t *testing.T) {
	t.Log(shipWithinDays([]int{180, 373, 75, 82, 497, 23, 303, 299, 53, 426, 152,
		314, 206, 433, 283, 370, 179, 254, 265, 431, 453, 17, 189, 224}, 12) == 631)
}
