package main

import (
	"log"
	"os"
	"strings"
	"text/template"
)

type sage struct {
	Name  string
	Motto string
}

var tpl *template.Template

var fm = template.FuncMap{
	"uc": strings.ToUpper,
	"ft": firstThree,
}

func firstThree(s string) string {
	s = strings.TrimSpace(s)
	return s[:3]
}

func init() {
	tpl = template.Must(template.New("").Funcs(fm).ParseGlob("tpl.gohtml"))
}

func main() {
	buddha := sage{
		Name:  "Buddha",
		Motto: "Belief of no belief",
	}

	yoda := sage{
		Name:  "Yoda",
		Motto: "Do or do not there is no try",
	}

	sages := []sage{buddha, yoda}

	err := tpl.ExecuteTemplate(os.Stdout, "tpl.gohtml", sages)
	if err != nil {
		log.Fatalln(err)
	}
}
