package main

import (
	"testing"
)

func TestFindSubString0(t *testing.T) {
	t.Log(findSubstring0(
		"barfoothefoobarman",
		[]string{"foo", "bar"}))
	t.Log(findSubstring0(
		"wordgoodgoodgoodbestword",
		[]string{"word", "good", "best", "word"}))
}

func TestFindSubString1(t *testing.T) {
	t.Log(findSubstring1(
		"barfoothefoobarman",
		[]string{"foo", "bar"}))
	t.Log(findSubstring1(
		"wordgoodgoodgoodbestword",
		[]string{"word", "good", "best", "word"}))
}

func BenchmarkFindSubString0(b *testing.B) {
	for i := 0; i < b.N; i++ {
		findSubstring0(
			"barfoothefoobarman",
			[]string{"foo", "bar"})
		findSubstring0(
			"wordgoodgoodgoodbestword",
			[]string{"word", "good", "best", "word"})
	}
}

func BenchmarkFindSubString1(b *testing.B) {
	for i := 0; i < b.N; i++ {
		findSubstring1(
			"barfoothefoobarman",
			[]string{"foo", "bar"})
		findSubstring1(
			"wordgoodgoodgoodbestword",
			[]string{"word", "good", "best", "word"})
	}
}
