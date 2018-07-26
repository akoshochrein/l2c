package main

import (
	"fmt"
)

type transportation interface {
	transportationDevice() string
}

func report(t transportation) {
	fmt.Println(t.transportationDevice())
}

type vehicle struct {
	doors int
	color string
}

type sedan struct {
	vehicle
	luxury bool
}

func (s sedan) transportationDevice() string {
	return fmt.Sprintln("I am a", s.color, "sedan. I can go really fast.")
}

type truck struct {
	vehicle
	fourWheel bool
}

func (t truck) transportationDevice() string {
	return fmt.Sprintln("I am a", t.doors, "truck. I can carry a lot of things.")
}

func main() {
	t := truck{
		vehicle{2, "blue"},
		true,
	}
	fmt.Println(t)
	fmt.Println(t.doors)
	report(t)

	s := sedan{
		vehicle{4, "red"},
		true,
	}
	fmt.Println(s)
	fmt.Println(s.color)
	report(s)
}
