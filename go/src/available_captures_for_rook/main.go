/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package available_captures_for_rook

var directions = [4][2]int{
	[2]int{0, 1},
	[2]int{0, -1},
	[2]int{1, 0},
	[2]int{-1, 0},
}

func numRookCaptures(board [][]byte) int {
	var row, col int
	for r := 0; r < 8; r++ {
		for c := 0; c < 8; c++ {
			if board[r][c] == 'R' {
				row = r
				col = c
				goto CHECK
			}
		}
	}

CHECK:
	ans := 0
	for _, d := range directions {
		rx := row
		cx := col

		for rx >= 0 && rx < 8 && cx >= 0 && cx < 8 {
			if board[rx][cx] == 'p' {
				ans += 1
				break
			} else if board[rx][cx] == 'B' {
				break
			}
			rx += d[0]
			cx += d[1]
		}
	}
	return ans
}
