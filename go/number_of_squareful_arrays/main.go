/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-19
 * @license MIT
 */

package main

import (
	"math"
)

func isSquare(a, b int) bool {
	x := int(math.Sqrt(float64(a + b)))
	return x*x == a+b
}

func dfs(side map[int]map[int]bool, numCnt map[int]int,
	n int, path []int, ans *int) {
	length := len(path)
	i := path[length-1]
	if length == n {
		*ans += 1
	} else {
		for j, _ := range side[i] {
			if numCnt[j] == 0 {
				continue
			}
			path = append(path, j)
			numCnt[j] -= 1
			dfs(side, numCnt, n, path, ans)
			numCnt[j] += 1
			path = path[:length]
		}
	}
}

func numSquarefulPerms(a []int) int {
	side := make(map[int]map[int]bool, len(a))
	numCnt := make(map[int]int)
	for i := 0; i < len(a); i++ {
		if _, exist := side[a[i]]; !exist {
			side[a[i]] = make(map[int]bool)
		}
		numCnt[a[i]] += 1
	}

	for i := 0; i < len(a)-1; i++ {
		for j := i + 1; j < len(a); j++ {
			if isSquare(a[i], a[j]) {
				side[a[i]][a[j]] = true
				side[a[j]][a[i]] = true
			}
		}
	}

	path := make([]int, 1, len(a))
	ans := 0
	for i, _ := range side {
		path[0] = i
		numCnt[i] -= 1
		dfs(side, numCnt, len(a), path, &ans)
		numCnt[i] += 1
	}
	return ans
}
