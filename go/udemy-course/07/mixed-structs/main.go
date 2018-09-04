package main

import (
	"log"
	"os"
	"text/template"
)

var tpl *template.Template

type sage struct {
	Name  string
	Motto string
}

type car struct {
	Manufacturer string
	Model        string
	Doors        int
}

func init() {
	tpl = template.Must(template.ParseGlob("tpl.gohtml"))
}

func main() {
	buddha := sage{
		Name:  "Buddha",
		Motto: "The belief of no beliefs",
	}

	yoda := sage{
		Name:  "Yoda",
		Motto: "Do or do not, there is no try",
	}

	sages := []sage{buddha, yoda}

	ford := car{
		Manufacturer: "Ford",
		Model:        "F150",
		Doors:        2,
	}

	toyota := car{
		Manufacturer: "Toyota",
		Model:        "Corolla",
		Doors:        4,
	}

	cars := []car{ford, toyota}

	data := struct {
		Wisdom         []sage
		Transportation []car
	}{
		sages,
		cars,
	}

	err := tpl.ExecuteTemplate(os.Stdout, "tpl.gohtml", data)
	if err != nil {
		log.Fatalln(err)
	}
}
