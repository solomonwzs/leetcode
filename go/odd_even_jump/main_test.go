package main

import "testing"

func TestJump(t *testing.T) {
	a := []int{10, 13, 12, 14, 15}
	t.Log(oddEvenJumps(a))
	t.Log(oddEvenJumpsNew(a))
}

func TestJump1(t *testing.T) {
	a := []int{2, 3, 1, 1, 4}
	t.Log(oddEvenJumps(a))
	t.Log(oddEvenJumpsNew(a))
}

func TestJump2(t *testing.T) {
	a := []int{5, 1, 3, 4, 2}
	t.Log(oddEvenJumps(a))
	t.Log(oddEvenJumpsNew(a))
}

func TestJump4(t *testing.T) {
	a := []int{1, 2, 3, 2, 1, 4, 4, 5}
	t.Log(oddEvenJumps(a))
	t.Log(oddEvenJumpsNew(a))
}

func BenchmarkJump(b *testing.B) {
	a := []int{1, 2, 3, 2, 1, 4, 4, 5}
	for i := 0; i < b.N; i++ {
		oddEvenJumps(a)
	}
}
