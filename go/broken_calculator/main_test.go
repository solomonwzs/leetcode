package main

import "testing"

func TestBroken(t *testing.T) {
	t.Log(brokenCalc(2, 3) == 2)
}

func TestBroken1(t *testing.T) {
	t.Log(brokenCalc(5, 8) == 2)
}

func TestBroken2(t *testing.T) {
	t.Log(brokenCalc(3, 10) == 3)
}

func TestBroken3(t *testing.T) {
	t.Log(brokenCalc(1024, 1) == 1023)
}

func TestBroken4(t *testing.T) {
	t.Log(brokenCalc(1, 1000000000))
}
