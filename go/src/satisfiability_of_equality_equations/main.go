package main

import "fmt"

func printm(m [26][26]byte) {
	for i := 0; i < 26; i++ {
		fmt.Println(m[i])
	}
}

func dfs(m *[26][26]byte, eq bool, a, b int) bool {
	if a > b {
		return dfs(m, eq, b, a)
	}

	// fmt.Printf("%c %c %v %v\n", a+'a', b+'a', eq, m[a][b])
	if m[a][b] == 0 {
		if eq {
			// fmt.Printf("%c==%c\n", a+'a', b+'a')
			m[a][b] = 1
		} else {
			// fmt.Printf("%c!=%c\n", a+'a', b+'a')
			m[a][b] = 2
		}

		for i := a + 1; i < 26; i++ {
			if m[a][i] == 1 && i != b {
				if !dfs(m, eq, i, b) {
					return false
				}
			}
		}
		for i := b + 1; i < 26; i++ {
			if m[b][i] == 1 && i != a {
				if !dfs(m, eq, a, i) {
					return false
				}
			}
		}
		return true
	} else if (m[a][b] == 1 && eq) || (m[a][b] == 2 && !eq) {
		return true
	} else {
		// fmt.Printf("%c %c %v\n", a+'a', b+'a', eq)
		return false
	}
}

func equationsPossible(equations []string) bool {
	m := [26][26]byte{}
	for i := 0; i < 26; i++ {
		m[i][i] = 1
	}

	for _, equation := range equations {
		a := int(equation[0] - 'a')
		b := int(equation[3] - 'a')

		eq := true
		if equation[1] == '!' {
			eq = false
		}

		if !dfs(&m, eq, a, b) {
			return false
		}
	}

	return true
}
