/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-24
 * @license MIT
 */

package main

var directions = [9][2]int{
	[2]int{0, 0},
	[2]int{0, 1},
	[2]int{1, 0},
	[2]int{1, 1},
	[2]int{0, -1},
	[2]int{-1, 0},
	[2]int{-1, -1},
	[2]int{1, -1},
	[2]int{-1, 1},
}

type lamp struct {
	row   int
	col   int
	diaLR int
	diaRL int
}

type litMpa struct {
	rows  map[int]int
	cols  map[int]int
	diaLR map[int]int
	diaRL map[int]int
}

func gridIllumination(N int, lamps [][]int, queries [][]int) []int {
	lm := &litMpa{
		rows:  map[int]int{},
		cols:  map[int]int{},
		diaLR: map[int]int{},
		diaRL: map[int]int{},
	}

	lampMap := map[uint64]lamp{}
	for _, l := range lamps {
		ll := lamp{
			row:   l[0],
			col:   l[1],
			diaLR: l[0] - l[1],
			diaRL: l[0] + l[1],
		}

		lampKey := (uint64(l[0] << 32)) | (uint64(l[1]))
		lampMap[lampKey] = ll

		lm.rows[ll.row] += 1
		lm.cols[ll.col] += 1
		lm.diaLR[ll.diaLR] += 1
		lm.diaRL[ll.diaRL] += 1
	}

	ans := make([]int, 0, len(queries))
	for _, query := range queries {
		illumination := 0
		if lm.rows[query[0]] > 0 || lm.cols[query[1]] > 0 ||
			lm.diaLR[query[0]-query[1]] > 0 || lm.diaRL[query[0]+query[1]] > 0 {
			illumination = 1
			for _, d := range directions {
				key := (uint64(query[0]+d[0]) << 32) | uint64(query[1]+d[1])
				if ll, exist := lampMap[key]; exist {
					lm.rows[ll.row] -= 1
					lm.cols[ll.col] -= 1
					lm.diaLR[ll.diaLR] -= 1
					lm.diaRL[ll.diaRL] -= 1

					delete(lampMap, key)
				}
			}
		}
		ans = append(ans, illumination)
	}
	return ans
}
