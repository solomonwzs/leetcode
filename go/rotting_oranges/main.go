package main

var directions = [][2]int{
	[2]int{0, 1},
	[2]int{1, 0},
	[2]int{0, -1},
	[2]int{-1, 0},
}

func orangesRotting(grid [][]int) int {
	rows := len(grid)
	cols := len(grid[0])
	rottingList := make([][2]int, 0, rows*cols)
	nflash := 0
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == 1 {
				nflash += 1
			} else if grid[i][j] == 2 {
				rottingList = append(rottingList, [2]int{i, j})
			}
		}
	}

	minutes := 0
	start := 0
	end := len(rottingList)
	for start < end && nflash != 0 {
		minutes += 1
		for x := start; x < end; x++ {
			r := rottingList[x]
			for _, d := range directions {
				if r[0]+d[0] >= 0 && r[0]+d[0] < rows &&
					r[1]+d[1] >= 0 && r[1]+d[1] < cols &&
					grid[r[0]+d[0]][r[1]+d[1]] == 1 {
					nflash -= 1
					grid[r[0]+d[0]][r[1]+d[1]] = 2
					rottingList = append(rottingList, [2]int{r[0] + d[0], r[1] + d[1]})
				}
			}
		}
		start = end
		end = len(rottingList)
	}

	if nflash != 0 {
		return -1
	} else {
		return minutes
	}
}
