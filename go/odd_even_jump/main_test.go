package main

import "testing"

func TestJump(t *testing.T) {
	a := []int{10, 13, 12, 14, 15}
	t.Log(oddEvenJumps(a))
}

func TestJump1(t *testing.T) {
	a := []int{2, 3, 1, 1, 4}
	t.Log(oddEvenJumps(a))
}

func TestJump2(t *testing.T) {
	a := []int{5, 1, 3, 4, 2}
	t.Log(oddEvenJumps(a))
}

func TestJump4(t *testing.T) {
	a := []int{1, 2, 3, 2, 1, 4, 4, 5}
	t.Log(oddEvenJumps(a))
}

func TestOrderList(t *testing.T) {
	l := orderList(make([][2]int, 0))
	l.add([2]int{1, 2})
	l.add([2]int{2, 1})
	t.Log(l)
}

func BenchmarkJump(b *testing.B) {
	a := []int{1, 2, 3, 2, 1, 4, 4, 5}
	for i := 0; i < b.N; i++ {
		oddEvenJumps(a)
	}
}
