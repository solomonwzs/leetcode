package main

import "testing"

func TestTall(t *testing.T) {
	t.Log(tallestBillboard([]int{1, 2, 3, 6}) == 6)
}

func TestTall1(t *testing.T) {
	t.Log(tallestBillboard([]int{1, 2, 3, 4, 5, 6}) == 10)
}

func BenchmarkTall(b *testing.B) {
	for i := 0; i < b.N; i++ {
		tallestBillboard([]int{1, 2, 3, 4, 5, 6})
	}
}
