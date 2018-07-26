package main

import (
	"fmt"
)

func main() {
	numbers := []int{1, 2, 3, 4, 123}
	fmt.Println(numbers)

	for i := range numbers {
		fmt.Println(i)
	}

	for i, v := range numbers {
		fmt.Println(i, v)
	}
}
