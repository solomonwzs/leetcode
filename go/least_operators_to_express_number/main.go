package main

import "fmt"

func leastOpsExpressTarget(x int, target int) int {
	arr := make([]int, 0)
	for target > 0 {
		n := target % x
		target /= x
		arr = append(arr, n)
	}
	arr = append(arr, 0)

	cnt := make([]int, len(arr))
	cnt[0] = 2
	for i := 1; i < len(arr); i++ {
		cnt[i] = i
	}

	fmt.Println(arr)
	for i := 0; i < len(arr)-1; i++ {
		if (x-arr[i])*cnt[i]+cnt[i+1] < arr[i]*cnt[i] {
			arr[i+1] += 1
			arr[i] = x - arr[i]
		}
	}
	fmt.Println(arr)
	fmt.Println(cnt)

	res := -1
	for i := 0; i < len(arr); i++ {
		res += arr[i] * cnt[i]
	}
	return res
}
