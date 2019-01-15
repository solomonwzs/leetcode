package main

import (
	"fmt"
	"strings"
)

func findSubstring(s string, words []string) (res []int) {
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

func main() {
	fmt.Println(findSubstring(
		"barfoothefoobarman",
		[]string{"foo", "bar"}))
	fmt.Println(findSubstring(
		"wordgoodgoodgoodbestword",
		[]string{"word", "good", "best", "word"}))
}
