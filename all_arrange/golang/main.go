package main

import "fmt"

var res [][]int

func main() {
	var track []int
	used := make(map[int]bool)
	nums := []int{1, 2, 3}
	backtrack(nums, track, used)
	fmt.Println(res)
}

func backtrack(nums, track []int, used map[int]bool) {
	// 终止条件:集合里的元素都已经加入路径
	if len(nums) == len(track) {
		res = append(res, track)
		//fmt.Println(track)
		return
	}
	// 外层横向遍历元素集合[1,2,3]
	for i := 0; i < len(nums); i++ {
		// 已使用过跳过
		if used[i] {
			continue
		}
		// 加入路径
		track = append(track, nums[i])
		// 标识已使用
		used[i] = true
		// 纵向树遍历
		backtrack(nums, track, used)
		// 撤销选择
		track = track[:len(track)-1]
		used[i] = false
	}
}
