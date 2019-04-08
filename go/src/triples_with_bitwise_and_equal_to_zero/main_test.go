package main

import "testing"

func TestCount(t *testing.T) {
	t.Log(countTripletsV1([]int{2, 1, 3}))
	t.Log(countTripletsV2([]int{2, 1, 3}))
}

func BenchmarkCountV1(b *testing.B) {
	arr := make([]int, 1000)
	for i := 0; i < len(arr); i++ {
		arr[i] = i + 1
	}

	for i := 0; i < b.N; i++ {
		countTripletsV1(arr)
	}
}

func BenchmarkCountV2(b *testing.B) {
	arr := make([]int, 1000)
	for i := 0; i < len(arr); i++ {
		arr[i] = i + 1
	}

	for i := 0; i < b.N; i++ {
		countTripletsV2(arr)
	}
}
