package main

import "testing"

func TestEq0(t *testing.T) {
	t.Log(equationsPossible([]string{
		"a==b",
		"b!=a",
	}) == false)
}

func TestEq1(t *testing.T) {
	t.Log(equationsPossible([]string{
		"a==b",
		"b==a",
	}) == true)
}

func TestEq2(t *testing.T) {
	t.Log(equationsPossible([]string{
		"a==b", "b==c", "a==c",
	}) == true)
}

func TestEq3(t *testing.T) {
	t.Log(equationsPossible([]string{
		"a==b", "b!=c", "c==a",
	}) == false)
}

func TestEq4(t *testing.T) {
	t.Log(equationsPossible([]string{
		"c==c", "b==d", "x!=z",
	}) == true)
}

func TestEq5(t *testing.T) {
	t.Log(equationsPossible([]string{
		"f==d", "b!=e", "d!=c", "b==c", "b!=a", "b!=f",
	}) == true)
}

func TestEq6(t *testing.T) {
	t.Log(equationsPossible([]string{
		"g==c", "f!=e", "e==b", "j==b", "g!=a", "e==c", "b!=f", "d!=a", "j==g",
		"f!=i", "a==e",
	}) == false)
}
