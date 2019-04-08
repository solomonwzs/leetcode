package main

var direction = [4][2]int{
	[2]int{0, 1},
	[2]int{0, -1},
	[2]int{1, 0},
	[2]int{-1, 0},
}

func travel(cur, end [2]int, x, y int, grid [][]int, emptyN int, num *int) {
	for _, d := range direction {
		var next [2]int
		next[0] = cur[0] + d[0]
		next[1] = cur[1] + d[1]

		if next == end && emptyN == 0 {
			*num += 1
			return
		}

		if (next[0] < 0 || next[0] >= x || next[1] < 0 || next[1] >= y) ||
			(grid[next[0]][next[1]] != 0) {
			continue
		}

		grid[next[0]][next[1]] = -1
		travel(next, end, x, y, grid, emptyN-1, num)
		grid[next[0]][next[1]] = 0
	}
}

func uniquePathsIII(grid [][]int) int {
	x := len(grid)
	if x == 0 {
		return 0
	}
	y := len(grid[0])
	if y == 0 {
		return 0
	}

	var cur [2]int
	var end [2]int
	emptyN := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == 1 {
				cur[0] = i
				cur[1] = j
			} else if grid[i][j] == 2 {
				end[0] = i
				end[1] = j
			} else if grid[i][j] == 0 {
				emptyN += 1
			}
		}
	}

	num := 0
	travel(cur, end, x, y, grid, emptyN, &num)
	return num
}
