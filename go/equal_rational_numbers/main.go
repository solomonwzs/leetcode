package main

import (
	"math"
)

type number struct {
	partInt   string
	partNonRe string
	partRe    string
}

func newNumber(s string) number {
	n := number{}

	i := 0
	for ; i < len(s) && s[i] != '.'; i++ {
	}
	n.partInt = s[:i]

	i += 1
	j := i
	for ; i < len(s) && s[i] != '('; i++ {
	}
	if j < len(s) {
		n.partNonRe = s[j:i]
	}

	i += 1
	j = i
	for ; i < len(s) && s[i] != ')'; i++ {
	}
	if j < len(s) {
		n.partRe = s[j:i]
	}

	i = len(n.partNonRe) - 1
	j = len(n.partRe) - 1
	for i >= 0 && j >= 0 {
		if n.partNonRe[i] == n.partRe[j] {
			n.partRe = n.partNonRe[i:] + n.partRe[:j]
			n.partNonRe = n.partNonRe[:i]
			i -= 1
		} else {
			break
		}
	}

	return n
}

func (n *number) simplify0() {
	for l := 1; l <= int(math.Sqrt(float64(len(n.partRe)))); l++ {
		if len(n.partRe)%l == 0 {
			re := true
			for i := l; i < len(n.partRe); i += l {
				if n.partRe[0:l] != n.partRe[i:i+l] {
					re = false
					break
				}
			}
			if re {
				n.partRe = n.partRe[0:l]
				break
			}
		}
	}
}

func (n *number) simplify1() {
	if n.partRe == "0" {
		n.partRe = ""
	} else if n.partRe == "9" {
		n.partRe = ""
		if l := len(n.partNonRe); l > 0 {
			for l = l - 1; l >= 0 && n.partNonRe[l] == '9'; l-- {
			}

			if l >= 0 {
				p := []byte(n.partNonRe[:l+1])
				p[l] += 1
				n.partNonRe = string(p)
				return
			} else {
				n.partNonRe = ""
			}
		}

		if l := len(n.partInt); l > 0 {
			p := []byte(n.partInt)
			for l = l - 1; l >= 0 && p[l] == '9'; l-- {
				p[l] = 0
			}
			if l >= 0 {
				p[l] += 1
			}
			n.partInt = string(p)
		}
		return
	}
	if l := len(n.partNonRe); l > 0 {
		for l = l - 1; l >= 0 && n.partNonRe[l] == '0'; l-- {
		}
		n.partNonRe = n.partNonRe[:l+1]
	}
}

func isRationalEqual(s string, t string) bool {
	if s == t {
		return true
	}

	n0 := newNumber(s)
	n1 := newNumber(t)
	if n0 == n1 {
		return true
	}

	n0.simplify0()
	n1.simplify0()
	if n0 == n1 {
		return true
	}

	n0.simplify1()
	n1.simplify1()
	return n0 == n1
}
