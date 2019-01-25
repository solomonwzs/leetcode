package main

const (
	_UNKNOWN  = 0
	_GOOD_IDX = 1
	_BAD_IDX  = 2
)

type jumpNode struct {
	oddNextIdx  int
	oddNextVal  int
	evenNextIdx int
	evenNextVal int
}

func oddEvenJumps(a []int) int {
	if len(a) == 0 {
		return 0
	}

	node := make([]jumpNode, len(a))
	for i := 0; i < len(a); i++ {
		node[i] = jumpNode{
			oddNextIdx:  i,
			oddNextVal:  a[i],
			evenNextIdx: i,
			evenNextVal: a[i],
		}
	}

	for j := len(a) - 1; j >= 0; j-- {
		for i := j - 1; i >= 0; i-- {
			if a[i] <= a[j] &&
				(node[i].oddNextIdx == i ||
					node[i].oddNextVal >= a[j]) {
				node[i].oddNextIdx = j
				node[i].oddNextVal = a[j]
			}
			if a[i] >= a[j] &&
				(node[i].evenNextIdx == i ||
					node[i].evenNextVal <= a[j]) {
				node[i].evenNextIdx = j
				node[i].evenNextVal = a[j]
			}
		}
	}

	goodStart := make([][2]int, len(a))
	goodStart[len(a)-1][0] = _GOOD_IDX
	goodStart[len(a)-1][1] = _GOOD_IDX
	trace := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		if goodStart[i][1] != _UNKNOWN {
			continue
		}

		k := 1
		cur := i
		idxType := _BAD_IDX
		trace = trace[:1]
		trace[0] = i
		for {
			if k == 1 {
				if node[cur].oddNextIdx == cur {
					break
				} else {
					cur = node[cur].oddNextIdx
				}
			} else {
				if node[cur].evenNextIdx == cur {
					break
				} else {
					cur = node[cur].evenNextIdx
				}
			}
			trace = append(trace, cur)
			k = k ^ 1

			if goodStart[cur][k] != _UNKNOWN {
				idxType = goodStart[cur][k]
				break
			}
		}

		for j, idx := range trace {
			goodStart[idx][(j+1)%2] = idxType
		}
	}

	n := 0
	for _, i := range goodStart {
		if i[1] == _GOOD_IDX {
			n += 1
		}
	}
	return n
}
