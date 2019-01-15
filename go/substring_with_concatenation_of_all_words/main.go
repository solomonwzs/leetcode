package main

import (
	"strings"
)

func findSubstring0(s string, words []string) (res []int) {
	res = make([]int, 0)

	if len(words) == 0 {
		return
	}

	wordCount := make(map[string]int)
	for _, word := range words {
		if val, exist := wordCount[word]; exist {
			wordCount[word] = val + 1
		} else {
			wordCount[word] = 1
		}
	}

	posDict := make(map[int]bool)
	for word, _ := range wordCount {
		begin := 0
		for begin < len(s) {
			if pos := strings.Index(s[begin:], word); pos == -1 {
				break
			} else {
				absPos := pos + begin
				posDict[absPos] = true
				begin += pos + 1
			}
		}
	}

	wordLen := len(words[0])
	for pos, _ := range posDict {
		word := s[pos : pos+wordLen]
		wordCount0 := make(map[string]int)
		wordCount0[word] = 1

		next := pos + wordLen
		match := 1
		for match < len(words) && next < len(s) {
			if _, exist := posDict[next]; !exist {
				break
			} else {
				word = s[next : next+wordLen]
				if val, exist := wordCount0[word]; !exist {
					wordCount0[word] = 1
				} else if val < wordCount[word] {
					wordCount0[word] += 1
				} else {
					break
				}
				match += 1
				next += wordLen
			}
		}

		if match == len(words) {
			res = append(res, pos)
		}
	}

	return
}

func findSubstring1(s string, words0 []string) (res []int) {
	res = make([]int, 0)
	if len(words0) == 0 {
		return
	}

	wordCount := make(map[string]int)
	for _, word := range words0 {
		if val, exist := wordCount[word]; exist {
			wordCount[word] = val + 1
		} else {
			wordCount[word] = 1
		}
	}

	words := make([]string, len(wordCount))
	iCount := make([]int, len(wordCount))
	i := 0
	for word, count := range wordCount {
		words[i] = word
		iCount[i] = count
		i += 1
	}

	posDict := make(map[int]int)
	for i, word := range words {
		begin := 0
		for begin < len(s) {
			if pos := strings.Index(s[begin:], word); pos == -1 {
				break
			} else {
				posDict[pos+begin] = i
				begin += pos + 1
			}
		}
	}

	wordLen := len(words[0])
	for pos, i := range posDict {
		iCount0 := make([]int, len(words))
		iCount0[i] = 1

		next := pos + wordLen
		match := 1
		for match < len(words0) && next < len(s) {
			if wi, exist := posDict[next]; !exist {
				break
			} else {
				if val := iCount0[wi]; val < iCount[wi] {
					iCount0[wi] += 1
					match += 1
					next += wordLen
				} else {
					break
				}
			}
		}

		if match == len(words0) {
			res = append(res, pos)
		}
	}

	return
}
