package main

import "testing"

func TestCircuit(t *testing.T) {
	t.Log(canCompleteCircuit(
		[]int{1, 2, 3, 4, 5},
		[]int{3, 4, 5, 1, 2},
	))
}

func TestCircuit1(t *testing.T) {
	t.Log(canCompleteCircuit(
		[]int{2, 3, 4},
		[]int{3, 4, 3},
	))
}

func TestCircuit2(t *testing.T) {
	t.Log(canCompleteCircuit(
		[]int{4},
		[]int{5},
	))
}

func TestCircuit3(t *testing.T) {
	t.Log(canCompleteCircuit(
		[]int{5, 1, 2, 3, 4},
		[]int{4, 4, 1, 5, 1},
	))
}
