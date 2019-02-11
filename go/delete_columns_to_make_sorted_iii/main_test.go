package main

import "testing"

func TestMin(t *testing.T) {
	t.Log(minDeletionSize([]string{"babca", "bbazb"}) == 3)
}

func TestMin1(t *testing.T) {
	t.Log(minDeletionSize([]string{"edcba"}) == 4)
}

func TestMin2(t *testing.T) {
	t.Log(minDeletionSize([]string{"ghi", "def", "abc"}) == 0)
}

func TestMin3(t *testing.T) {
	t.Log(minDeletionSize([]string{"aaaabaa"}) == 1)
}

func TestMin4(t *testing.T) {
	t.Log(minDeletionSize([]string{"aaababa", "ababbaa"}) == 4)
}

func TestMin5(t *testing.T) {
	t.Log(minDeletionSize([]string{"babbba", "bbaaab"}) == 3)
}

func TestMin6(t *testing.T) {
	t.Log(minDeletionSize([]string{
		"bbbbaaa",
		"babbaaa",
		"bbbbaab",
		"abababb",
	}) == 4)
}

func TestMin7(t *testing.T) {
	t.Log(minDeletionSize([]string{
		"bbaaa",
		"aaabb",
		"bbaab",
		"aabaa",
	}) == 3)
}

func TestMin8(t *testing.T) {
	t.Log(minDeletionSize([]string{
		"bcabb",
		"ccbcb",
		"bbbbc",
		"cabba",
	}) == 3)
}

func TestMin9(t *testing.T) {
	t.Log(minDeletionSize([]string{"cbbdabc"}) == 3)
}
