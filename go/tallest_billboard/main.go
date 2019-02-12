package main

func tallestBillboard(rods []int) int {
	length := len(rods)
	sum := 0
	for _, rod := range rods {
		sum += rod
	}

	max := make([][]int, length+1)
	max[0] = make([]int, sum*2+1)

	dp := make([][]bool, length+1)
	dp[0] = make([]bool, sum*2+1)
	dp[0][sum] = true
	for i := 0; i < length; i++ {
		max[i+1] = make([]int, sum*2+1)
		dp[i+1] = make([]bool, sum*2+1)
		for j := 0; j < sum*2+1; j++ {
			// +1
			if j-rods[i] >= 0 && dp[i][j-rods[i]] {
				dp[i+1][j] = true
				if max[i+1][j] < max[i][j-rods[i]]+rods[i] {
					max[i+1][j] = max[i][j-rods[i]] + rods[i]
				}
			}

			// -1
			if j+rods[i] < sum*2+1 && dp[i][j+rods[i]] {
				dp[i+1][j] = true
				if max[i+1][j] < max[i][j+rods[i]] {
					max[i+1][j] = max[i][j+rods[i]]
				}
			}

			// 0
			if dp[i][j] {
				dp[i+1][j] = true
				if max[i+1][j] < max[i][j] {
					max[i+1][j] = max[i][j]
				}
			}
		}
	}
	return max[length][sum]
}
