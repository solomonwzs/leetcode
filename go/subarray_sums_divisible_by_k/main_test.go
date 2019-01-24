package main

import "testing"

func TestSub(t *testing.T) {
	t.Log(subarraysDivByK([]int{4, 5, 0, -2, -3, 1}, 5))
}

func TestSub1(t *testing.T) {
	t.Log(subarraysDivByK([]int{8, 9, 7, 8, 9}, 8))
}

func TestSub2(t *testing.T) {
	t.Log(subarraysDivByK([]int{-2}, 6))
}
