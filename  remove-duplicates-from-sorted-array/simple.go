package main

import "fmt"

func removeDuplicates(nums []int) int {
	k := 1
	i := 0
	numSize := len(nums)
	prev := nums[0]
	for i < numSize {
		if i > 0 {
			prev = nums[i-1]
		}
		if prev != nums[i] {
			nums[k] = nums[i]
			k++
		}
		i++
	}
	return k
}

func main() {
	nums := []int{-1, 0, 0, 0, 0, 3, 3}
	k := removeDuplicates(nums)
	fmt.Println(k)
	fmt.Println(nums)
}
