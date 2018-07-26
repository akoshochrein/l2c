package main

import (
	"fmt"
)

type human interface {
	dance()
}

type person struct {
	fname string
	lname string
	age   int
}

func (p person) pSpeak() {
	fmt.Println("As a person, my name is", p.fname, p.lname)
}

func (p person) dance() {
	fmt.Println(p.lname, "is dancing")
}

type secretAgent struct {
	person
	licenseToKill bool
}

func (sa secretAgent) saSpeak() {
	fmt.Println("As a secret agent, my name is", sa.fname, sa.lname)
}

func (sa secretAgent) dance() {
	fmt.Println(sa.lname, "is immersed among the dancers")
}

func checkMoves(h human) {
	h.dance()
}

func main() {
	p := person{
		"Akos",
		"Hochrein",
		28,
	}
	p.pSpeak()
	checkMoves(p)

	sa := secretAgent{
		person{
			"Soka",
			"Nierhcoh",
			32,
		},
		true,
	}
	sa.saSpeak()
	checkMoves(sa)
}
