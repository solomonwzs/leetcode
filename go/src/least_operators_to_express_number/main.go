package main

import "fmt"

func leastOpsExpressTargetNotWork(x int, target int) int {
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
		if (x-arr[i])*cnt[i]+cnt[i+1] <= arr[i]*cnt[i] {
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

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func leastOpsExpressTarget(x int, target int) int {
	pos := 0
	neg := 0
	k := 0
	for target > 0 {
		cur := target % x
		target /= x

		if k > 0 {
			newPos := min(cur*k+pos, (cur+1)*k+neg)
			newNeg := min((x-cur)*k+pos, (x-cur-1)*k+neg)

			pos = newPos
			neg = newNeg
		} else {
			pos = cur * 2
			neg = (x - cur) * 2
		}
		k++
	}
	return min(pos, k+neg) - 1
}
