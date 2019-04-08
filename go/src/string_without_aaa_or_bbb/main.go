package main

func strWithout3a3b(a int, b int) string {
	arr := make([]byte, a+b)
	ca := 0
	cb := 0
	for i := 0; i < len(arr); i++ {
		if (a > b && ca < 2) || (cb == 2) {
			arr[i] = 'a'
			ca += 1
			cb = 0
			a -= 1
		} else {
			arr[i] = 'b'
			cb += 1
			ca = 0
			b -= 1
		}
	}

	return string(arr)
}
