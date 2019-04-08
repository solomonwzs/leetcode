package main

import "testing"

func TestLeast0(t *testing.T) {
	t.Log(leastOpsExpressTarget(3, 19) == 5)
}

func TestLeast1(t *testing.T) {
	t.Log(leastOpsExpressTarget(5, 501) == 8)
}

func TestLeast2(t *testing.T) {
	t.Log(leastOpsExpressTarget(100, 100000000) == 3)
}

func TestLeast3(t *testing.T) {
	t.Log(leastOpsExpressTarget(3, 929) == 19)
}
