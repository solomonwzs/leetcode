/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-10
 * @license MIT
 */

package main

func minDominoRotations0(a []int, b []int) int {
	n := len(a)
	ah := a[0]
	bh := b[0]
	aok := true
	bok := true
	ans := 0
	for i := 1; i < n && (aok || bok); i++ {
		if aok {
			if a[i] == ah {
				if b[i] != bh {
					bok = false
				}
			} else if b[i] == ah {
				ans += 1
				if a[i] != bh {
					bok = false
				}
			} else {
				aok = false
			}
		}

		if !aok && bok {
			if b[i] == bh {
			} else if a[i] == bh {
				ans += 1
			} else {
				bok = false
			}
		}
	}

	if aok || bok {
		return ans
	} else {
		ans = -1
	}
	return ans
}

func minDominoRotations1(a []int, b []int) int {
	ansA := minDominoRotations0(a, b)
	if ansA == -1 {
		return ansA
	}

	ansB := minDominoRotations0(b, a)
	if ansA < ansB {
		return ansA
	} else {
		return ansB
	}
}

func minDominoRotations(a []int, b []int) int {
	ans := minDominoRotations1(a, b)
	if ans == -1 {
		return ans
	}

	if a[0] != b[0] {
		tmp := a[0]
		a[0] = b[0]
		b[0] = tmp
		ans1 := minDominoRotations1(a, b) + 1
		if ans1 < ans {
			ans = ans1
		}
	}
	return ans
}
