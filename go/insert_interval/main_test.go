package main

import "testing"

func TestInsert(t *testing.T) {
	intervals := []Interval{
		Interval{1, 2},
		Interval{3, 5},
		Interval{6, 7},
		Interval{8, 10},
		Interval{12, 16},
	}
	newInterval := Interval{17, 18}
	t.Log(insert(intervals, newInterval))
}
