package main

import (
	"fmt"
)

func jump(nums []int) int {
	position := 0
	jumpCount := 0
	lengthiestJump := 0
	lastJump := 0
	numsSize := len(nums)
	if numsSize == 1 {
		return 0
	}
	if lastJump > numsSize-1 {
		return 1
	}
	for position <= numsSize-1 {
		if lengthiestJump < position+nums[position] {
			lengthiestJump = position + nums[position]
		}
		if position == lastJump {
			jumpCount++
			lastJump = lengthiestJump
			if lastJump >= numsSize-1 {
				return jumpCount
			}
		}
		position++
	}
	return 0
}

func main() {
	nums := []int{2, 3, 1, 1, 4}
	var i = jump(nums)
	fmt.Println(i)
}
