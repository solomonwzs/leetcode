package main

import "testing"

func TestInsert(t *testing.T) {
	intervals := []Interval{
		Interval{1, 3},
		Interval{6, 9},
	}
	newInterval := Interval{2, 5}
	t.Log(insert(intervals, newInterval))
}
