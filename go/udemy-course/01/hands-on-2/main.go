package main

import (
	"fmt"
)

type person struct {
	fname string
	lname string
	age   int
}

func (p person) pSpeak() {
	fmt.Println("As a person, my name is", p.fname, p.lname)
}

type secretAgent struct {
	person
	licenseToKill bool
}

func (sa secretAgent) saSpeak() {
	fmt.Println("As a secret agent, my name is", sa.fname, sa.lname)
}

func main() {
	p := person{
		"Akos",
		"Hochrein",
		28,
	}
	p.pSpeak()

	sa := secretAgent{
		person{
			"Soka",
			"Nierhcoh",
			32,
		},
		true,
	}
	sa.saSpeak()
}
