package main

import "testing"

func TestAdd0(t *testing.T) {
	t.Log(addToArrayForm([]int{1, 2, 0, 0}, 34))
}

func TestAdd1(t *testing.T) {
	t.Log(addToArrayForm([]int{1, 2}, 134))
}

func TestAdd2(t *testing.T) {
	t.Log(addToArrayForm([]int{2, 1, 5}, 806))
}
