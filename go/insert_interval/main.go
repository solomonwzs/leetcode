package main

type Interval struct {
	Start int
	End   int
}

func insert(intervals []Interval, newInterval Interval) (res []Interval) {
	res = make([]Interval, 0)

	i := 0
	for ; i < len(intervals) && intervals[i].End < newInterval.Start; i++ {
		res = append(res, intervals[i])
	}

	start := newInterval.Start
	end := newInterval.End
	for i < len(intervals) && intervals[i].Start <= newInterval.End {
		if intervals[i].Start < start {
			start = intervals[i].Start
		}
		if intervals[i].End > end {
			end = intervals[i].End
		}
		i += 1
	}
	res = append(res, Interval{start, end})

	for ; i < len(intervals); i++ {
		res = append(res, intervals[i])
	}

	return
}
