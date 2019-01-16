package main

import "fmt"

type Interval struct {
	Start int
	End   int
}

type pos struct {
	i int
	x bool
}

func insert(intervals []Interval, newInterval Interval) (res []Interval) {
	res = make([]Interval, 0)
	if len(intervals) == 0 {
		return
	}

	posList := make([]pos, len(intervals)*4+4)
	posList[0] = pos{i: intervals[0].Start - 1, x: false}
	posList[1] = pos{i: intervals[0].Start - 1, x: false}
	posList[len(posList)-2] = pos{i: intervals[len(intervals)-1].End + 1, x: false}
	posList[len(posList)-1] = pos{i: intervals[len(intervals)-1].End + 1, x: false}
	for i := 0; i < len(intervals); i++ {
		j := i*4 + 2
		posList[j] = pos{i: intervals[i].Start, x: false}
		posList[j+1] = pos{i: intervals[i].Start, x: true}
		posList[j+2] = pos{i: intervals[i].End, x: true}
		posList[j+3] = pos{i: intervals[i].End, x: false}
	}

	ins := false
	for i := 0; i < len(posList); i++ {
		if !ins {
			if newInterval.Start <= posList[i].i {
				if posList[i].x == false {
					posList[i].i = newInterval.Start
				}
				posList[i].x = true
				ins = true
			}
		} else {
			if newInterval.End < posList[i].i {
				if posList[i-1].i < newInterval.End {
					posList[i-1].i = newInterval.End
				}
				break
			} else {
				posList[i].x = true
			}
		}
	}
	fmt.Println(posList)

	return
}
