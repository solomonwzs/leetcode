/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-02-24
 * @license MIT
 */

package main

func findJudge(n int, trust [][]int) int {
	nTrust := make([]int, n+1)
	nTrusted := make([]int, n+1)

	for _, t := range trust {
		nTrust[t[0]] += 1
		nTrusted[t[1]] += 1
	}

	for i := 1; i < n+1; i++ {
		if nTrust[i] == 0 && nTrusted[i] == n-1 {
			return i
		}
	}

	return -1
}
