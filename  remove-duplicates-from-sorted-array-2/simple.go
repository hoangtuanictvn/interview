package main

import "fmt"

func removeDuplicates(nums []int) int {
	size := len(nums)
	if size <= 2 {
		return size
	}
	k := 2
	for j := k; j < size; j++ {
		if nums[k-2] != nums[j] {
			nums[k] = nums[j]
			k++
		}
	}
	return k
}

func main() {
	nums := []int{0, 0, 0, 0, 1, 1, 1, 2, 3, 3} // {0,0,1,1,2,2,3,3}
	k := removeDuplicates(nums)
	fmt.Println(k)
	fmt.Println(nums)
}
