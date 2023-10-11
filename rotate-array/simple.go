package main

import "fmt"

func rotate(nums []int, k int) {
	size := len(nums)
	step := 0
	ns := nums
	if k > size {
		k = k % size
		for step < k {
			ns = append(ns[size-1:], ns[:size-1]...)
			step++
		}
	} else {
		ns = append(ns[size-k:], ns[:size-k]...)
	}
	for i, num := range ns {
		nums[i] = num
	}
}

func main() {
	nums := []int{1, 2, 3, 4, 5, 6, 7}
	rotate(nums, 2)
	fmt.Println(nums)
}
