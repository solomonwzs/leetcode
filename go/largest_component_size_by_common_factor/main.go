package main

var primes []int = []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
	59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
	139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
	227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
	311, 313}

type groupMeta struct {
	count  int
	rank   int
	parent *groupMeta
}

func newGroupMeta() *groupMeta {
	return &groupMeta{
		count:  0,
		rank:   0,
		parent: nil,
	}
}

func (m *groupMeta) getParent() *groupMeta {
	if m.parent == nil {
		return m
	} else {
		return m.parent.getParent()
	}
}

func largestComponentSize(a []int) int {
	if len(a) <= 1 {
		return len(a)
	}

	pl := make([][]int, len(a))
	gmMap := make(map[int]*groupMeta)
	for i := 0; i < len(a); i++ {
		pl[i] = make([]int, 0)
		j := 0
		x := a[i]
		for j < len(primes) && primes[j] <= x {
			if x%primes[j] == 0 {
				if len(pl[i]) == 0 || pl[i][len(pl[i])-1] != primes[j] {
					if _, exist := gmMap[primes[j]]; !exist {
						gmMap[primes[j]] = newGroupMeta()
					}
					pl[i] = append(pl[i], primes[j])
				}
				x /= primes[j]
			} else {
				j += 1
			}
		}
		if x != 1 {
			if _, exist := gmMap[x]; !exist {
				gmMap[x] = newGroupMeta()
			}
			pl[i] = append(pl[i], x)
		}
	}

	ans := 1
	for i := 0; i < len(pl); i++ {
		if len(pl[i]) == 0 {
			continue
		}

		meta := gmMap[pl[i][0]].getParent()
		meta.count += 1
		for j := 1; j < len(pl[i]); j++ {
			if meta1 := gmMap[pl[i][j]].getParent(); meta1 != meta {
				if meta.rank > meta1.rank {
					meta1.parent = meta
					meta.count += meta1.count
				} else {
					meta.parent = meta1
					meta1.count += meta.count
					if meta.rank == meta1.rank {
						meta1.rank += 1
					}
					meta = meta1
				}
			}
		}
		if meta.count > ans {
			ans = meta.count
		}
	}
	return ans
}
