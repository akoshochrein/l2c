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

func init() {
	tpl = template.Must(template.ParseGlob("tpl.gohtml"))
}

func main() {
	buddha := sage{
		Name:  "Buddha",
		Motto: "The belief of no beliefs",
	}

	ghandi := sage{
		Name:  "Ghandi",
		Motto: "Be the change",
	}

	jesus := sage{
		Name:  "Jesus",
		Motto: "Love all",
	}

	sages := []sage{buddha, ghandi, jesus}

	err := tpl.ExecuteTemplate(os.Stdout, "tpl.gohtml", sages)
	if err != nil {
		log.Fatalln(err)
	}
}
