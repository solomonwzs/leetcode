package main

import "sort"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type CoordinateNode struct {
	Node *TreeNode
	X    int
	Y    int
}

func verticalTraversal(root *TreeNode) [][]int {
	cList := make([]*CoordinateNode, 1)
	cList[0] = &CoordinateNode{
		Node: root,
		X:    0,
		Y:    0,
	}

	resMap := make(map[int][]*CoordinateNode)
	i := 0
	left := 0
	right := 0
	for i < len(cList) {
		n := cList[i]
		if left > n.X {
			left = n.X
		}
		if right < n.X {
			right = n.X
		}

		if _, exist := resMap[n.X]; exist {
			resMap[n.X] = append(resMap[n.X], n)
		} else {
			resMap[n.X] = []*CoordinateNode{n}
		}
		i += 1

		if n.Node.Left != nil {
			cList = append(cList, &CoordinateNode{
				Node: n.Node.Left,
				X:    n.X - 1,
				Y:    n.Y - 1,
			})
		}
		if n.Node.Right != nil {
			cList = append(cList, &CoordinateNode{
				Node: n.Node.Right,
				X:    n.X + 1,
				Y:    n.Y - 1,
			})
		}
	}

	res := make([][]int, 0, len(resMap))
	for x := left; x <= right; x++ {
		if list, exist := resMap[x]; exist {
			sort.SliceStable(list, func(i, j int) bool {
				return list[i].Y > list[j].Y ||
					(list[i].Y == list[j].Y && list[i].Node.Val < list[j].Node.Val)
			})

			l := make([]int, 0, len(list))
			for _, n := range list {
				l = append(l, n.Node.Val)
			}
			res = append(res, l)
		}
	}
	return res
}
