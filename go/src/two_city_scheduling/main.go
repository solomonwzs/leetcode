/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-21
 * @license MIT
 */

package two_city_scheduling

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func twoCitySchedCost(costs [][]int) int {
	ans := 0
	n := len(costs) / 2
	for i, cost := range costs {
		if i < n {
			ans += cost[0]
		} else {
			ans += cost[1]
		}
	}

	for i := 0; i < n; i++ {
		save := 0
		jx := 0
		for j := n; j < len(costs); j++ {
			sx := costs[i][0] - costs[i][1] + costs[j][1] - costs[j][0]
			if sx > save {
				save = sx
				jx = j
			}
		}

		if save != 0 {
			t := costs[i][0]
			costs[i][0] = costs[jx][0]
			costs[jx][0] = t

			t = costs[i][1]
			costs[i][1] = costs[jx][1]
			costs[jx][1] = t

			ans -= save
		}
	}

	return ans
}
