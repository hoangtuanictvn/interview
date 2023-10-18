package main

import (
	"fmt"
)

func romanToInt(s string) int {
	romanDics := map[uint8]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	value := 0
	for i := len(s) - 1; i >= 0; i-- {
		var prev, cur uint8 = 0, s[i]
		if i <= 0 {
			value += romanDics[cur]
			continue
		} else {
			prev = s[i-1]
			if romanDics[prev] >= romanDics[cur] {
				value += romanDics[cur]
			} else {
				value += romanDics[cur] - romanDics[prev]
				i--
			}
		}
	}
	return value
}

func main() {
	value := romanToInt("XVII")
	fmt.Println(value)
}
