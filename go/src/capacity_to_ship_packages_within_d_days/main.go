/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package capacity_to_ship_packages_within_d_days

func shipWithinDays(weights []int, d int) int {
	left := 0
	right := 0
	for _, w := range weights {
		if w > left {
			left = w
		}
		right += w
	}

	for left < right {
		mid := (left + right) / 2
		days := 1
		cargo := 0

		for i := 0; i < len(weights) && days <= d; i++ {
			if cargo+weights[i] > mid {
				days += 1
				cargo = 0
			}
			cargo += weights[i]
		}

		if days > d {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}
