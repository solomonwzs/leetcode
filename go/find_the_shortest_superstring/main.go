/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-06
 * @license MIT
 */

package main

func shortestSuperstring(a []string) string {
	n := len(a)
	cost := make([][]int, n)
	for i := 0; i < n; i++ {
		cost[i] = make([]int, n)
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}

			li := len(a[i])
			lj := len(a[j])
			k := li
			if lj < k {
				k = lj
			}
			for ; k > 0; k-- {
				si := a[i][li-k:]
				sj := a[j][:k]
				if si == sj {
					cost[i][j] = k
					break
				}
			}
		}
	}

	dp := make([][]string, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]string, 1<<uint32(n))
		dp[i][1<<uint32(i)] = a[i]
	}

	for sets := 1; sets < 1<<uint32(n); sets++ {
		for i := 0; i < n; i++ {
			if (1<<uint32(i))&sets == 0 {
				continue
			}

			for j := 0; j < n; j++ {
				if i == j || (1<<uint32(j))&sets == 0 {
					continue
				}

				setsWithoutI := sets ^ (1 << uint32(i))
				s := dp[j][setsWithoutI] + a[i][cost[j][i]:]
				if len(dp[i][sets]) == 0 || len(dp[i][sets]) > len(s) {
					dp[i][sets] = s
				}
			}
		}
	}

	all := (1 << uint32(n)) - 1
	ans := dp[0][all]
	for i := 1; i < n; i++ {
		if len(ans) > len(dp[i][all]) {
			ans = dp[i][all]
		}
	}
	return ans
}
