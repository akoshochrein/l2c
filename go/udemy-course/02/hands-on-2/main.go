package main

import "fmt"

func main() {
	classRoom := map[string]int{"Akos": 28, "Robi": 27, "Erika": 29}
	fmt.Println(classRoom)

	for k := range classRoom {
		fmt.Println(k)
	}

	for k, v := range classRoom {
		fmt.Println(k, v)
	}
}
