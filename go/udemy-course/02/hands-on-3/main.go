package main

import (
	"fmt"
)

type person struct {
	fName   string
	lName   string
	favFood []string
}

func (p person) walk() string {
	return fmt.Sprintln(p.fName, "is walking")
}

func main() {
	p1 := person{"Akos", "Hochrein", []string{"pizza", "cheese", "meki"}}
	fmt.Println(p1.fName)

	for _, food := range p1.favFood {
		fmt.Println(food)
	}

	fmt.Println(p1.walk())
}
