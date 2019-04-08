/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package main

import "testing"

func TestVideo(t *testing.T) {
	t.Log(videoStitching([][]int{
		[]int{0, 2},
		[]int{4, 6},
		[]int{8, 10},
		[]int{1, 9},
		[]int{1, 5},
		[]int{5, 9},
	}, 10) == 3)
}

func TestVideo1(t *testing.T) {
	t.Log(videoStitching([][]int{
		[]int{0, 1},
		[]int{1, 2},
	}, 5) == -1)
}

func TestVideo2(t *testing.T) {
	t.Log(videoStitching([][]int{
		[]int{0, 1},
		[]int{6, 8},
		[]int{0, 2},
		[]int{5, 6},
		[]int{0, 4},
		[]int{0, 3},
		[]int{6, 7},
		[]int{1, 3},
		[]int{4, 7},
		[]int{1, 4},
		[]int{2, 5},
		[]int{2, 6},
		[]int{3, 4},
		[]int{4, 5},
		[]int{5, 7},
		[]int{6, 9},
	}, 9) == 3)
}

func TestVideo3(t *testing.T) {
	t.Log(videoStitching([][]int{
		[]int{0, 4},
		[]int{2, 8},
	}, 5) == 2)
}

func TestVideo4(t *testing.T) {
	t.Log(videoStitching([][]int{
		[]int{0, 5}, []int{1, 6}, []int{2, 7}, []int{3, 8}, []int{4, 9}, []int{5, 10}, []int{6, 11}, []int{7, 12}, []int{8, 13}, []int{9, 14}, []int{10, 15}, []int{11, 16}, []int{12, 17}, []int{13, 18}, []int{14, 19}, []int{15, 20}, []int{16, 21}, []int{17, 22}, []int{18, 23}, []int{19, 24}, []int{20, 25}, []int{21, 26}, []int{22, 27}, []int{23, 28}, []int{24, 29}, []int{25, 30}, []int{26, 31}, []int{27, 32}, []int{28, 33}, []int{29, 34}, []int{30, 35}, []int{31, 36}, []int{32, 37}, []int{33, 38}, []int{34, 39}, []int{35, 40}, []int{36, 41}, []int{37, 42}, []int{38, 43}, []int{39, 44}, []int{40, 45}, []int{41, 46}, []int{42, 47}, []int{43, 48}, []int{44, 49}, []int{45, 50}, []int{46, 51}, []int{47, 52}, []int{48, 53}, []int{49, 54},
	}, 50))
}
