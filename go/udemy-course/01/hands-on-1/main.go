package main

import (
	"fmt"
	"math"
)

type shape interface {
	area() float64
}

func info(s shape) {
	fmt.Println("The are of the shape is:", s.area())
}

type square struct {
	side float64
}

func (s square) area() float64 {
	return s.side * s.side
}

type circle struct {
	radius float64
}

func (c circle) area() float64 {
	return c.radius * c.radius * math.Pi
}

func main() {
	s := square{
		1.72,
	}
	info(s)

	c := circle{
		1.72,
	}
	info(c)
}
