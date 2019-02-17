package main

func canCompleteCircuit(gas []int, cost []int) int {
	length := len(gas)
	i := 0
	for ; i < length && gas[i] < cost[i]; i++ {
	}
	if i == length {
		return -1
	}

	tank := gas[i] - cost[i]
	j := i
	n := 0
	for n < length {
		if tank >= 0 {
			j = (j + 1) % length
			tank += gas[j] - cost[j]
		} else {
			i = (i + length - 1) % length
			tank += gas[i] - cost[i]
		}
		n += 1
	}

	if n == length && tank >= 0 {
		return i
	} else {
		return -1
	}
}
